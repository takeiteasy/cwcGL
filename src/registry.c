/*
 The MIT License (MIT)

 Copyright (c) 2022 George Watson

 Permission is hereby granted, free of charge, to any person
 obtaining a copy of this software and associated documentation
 files (the "Software"), to deal in the Software without restriction,
 including without limitation the rights to use, copy, modify, merge,
 publish, distribute, sublicense, and/or sell copies of the Software,
 and to permit persons to whom the Software is furnished to do so,
 subject to the following conditions:

 The above copyright notice and this permission notice shall be
 included in all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

/* Wrappers below call the real driver entry points (glGenTextures etc,
 * which on the host side are #define'd to __glGenTextures by loader.h,
 * resolved by InitOpenGL()) -- never cwcgl_registry_install()'s own
 * wrappers. The two must stay distinct: if a wrapper's address were ever
 * fed back into the __glFoo global it wraps, every tracked call would
 * recurse into itself.
 */
#include "registry.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    GLuint *ids;
    size_t count;
    size_t cap;
} cwcgl_id_set;

static cwcgl_id_set g_sets[CWCGL_CLASS_COUNT];
static GLsync *g_syncs = NULL;
static size_t g_sync_count = 0, g_sync_cap = 0;
static unsigned g_epoch = 0;

static void set_add(cwcgl_id_set *s, GLuint id) {
    if (s->count == s->cap) {
        size_t cap = s->cap ? s->cap * 2 : 8;
        GLuint *ids = realloc(s->ids, cap * sizeof(GLuint));
        if (!ids)
            return; /* leak-detected-at-teardown is the worst case, not a crash */
        s->ids = ids;
        s->cap = cap;
    }
    s->ids[s->count++] = id;
}

static void set_remove(cwcgl_id_set *s, GLuint id) {
    for (size_t i = 0; i < s->count; i++) {
        if (s->ids[i] == id) {
            s->ids[i] = s->ids[--s->count];
            return;
        }
    }
}

#if defined(CWCGL_DEBUG_VALIDATE)
static int set_contains(const cwcgl_id_set *s, GLuint id) {
    for (size_t i = 0; i < s->count; i++)
        if (s->ids[i] == id)
            return 1;
    return 0;
}
#endif

static void set_delete_all(cwcgl_id_set *s, void (*deleter)(GLsizei, const GLuint *)) {
    if (s->count)
        deleter((GLsizei)s->count, s->ids);
    s->count = 0;
}

/* ---- the 20 tracking wrappers -------------------------------------- */

#define CWCGL_ARRAY_ALLOC(NAME, CLASS) \
    static void cwcgl_##NAME(GLsizei n, GLuint *ids) { \
        NAME(n, ids); \
        for (GLsizei i = 0; i < n; i++) \
            set_add(&g_sets[CWCGL_CLASS_##CLASS], ids[i]); \
    }

#define CWCGL_ARRAY_DELETE(NAME, CLASS) \
    static void cwcgl_##NAME(GLsizei n, const GLuint *ids) { \
        for (GLsizei i = 0; i < n; i++) \
            set_remove(&g_sets[CWCGL_CLASS_##CLASS], ids[i]); \
        NAME(n, ids); \
    }

CWCGL_ARRAY_ALLOC(glGenTextures, TEXTURE)
CWCGL_ARRAY_DELETE(glDeleteTextures, TEXTURE)
CWCGL_ARRAY_ALLOC(glGenBuffers, BUFFER)
CWCGL_ARRAY_DELETE(glDeleteBuffers, BUFFER)
CWCGL_ARRAY_ALLOC(glGenFramebuffers, FRAMEBUFFER)
CWCGL_ARRAY_DELETE(glDeleteFramebuffers, FRAMEBUFFER)
CWCGL_ARRAY_ALLOC(glGenRenderbuffers, RENDERBUFFER)
CWCGL_ARRAY_DELETE(glDeleteRenderbuffers, RENDERBUFFER)
CWCGL_ARRAY_ALLOC(glGenVertexArrays, VERTEX_ARRAY)
CWCGL_ARRAY_DELETE(glDeleteVertexArrays, VERTEX_ARRAY)
CWCGL_ARRAY_ALLOC(glGenQueries, QUERY)
CWCGL_ARRAY_DELETE(glDeleteQueries, QUERY)
CWCGL_ARRAY_ALLOC(glGenSamplers, SAMPLER)
CWCGL_ARRAY_DELETE(glDeleteSamplers, SAMPLER)

#undef CWCGL_ARRAY_ALLOC
#undef CWCGL_ARRAY_DELETE

static GLuint cwcgl_glCreateProgram(void) {
    GLuint id = glCreateProgram();
    set_add(&g_sets[CWCGL_CLASS_PROGRAM], id);
    return id;
}

static void cwcgl_glDeleteProgram(GLuint program) {
    set_remove(&g_sets[CWCGL_CLASS_PROGRAM], program);
    glDeleteProgram(program);
}

static GLuint cwcgl_glCreateShader(GLenum type) {
    GLuint id = glCreateShader(type);
    set_add(&g_sets[CWCGL_CLASS_SHADER], id);
    return id;
}

static void cwcgl_glDeleteShader(GLuint shader) {
    set_remove(&g_sets[CWCGL_CLASS_SHADER], shader);
    glDeleteShader(shader);
}

static GLsync cwcgl_glFenceSync(GLenum condition, GLbitfield flags) {
    GLsync sync = glFenceSync(condition, flags);
    if (sync) {
        if (g_sync_count == g_sync_cap) {
            size_t cap = g_sync_cap ? g_sync_cap * 2 : 8;
            GLsync *syncs = realloc(g_syncs, cap * sizeof(GLsync));
            if (syncs) {
                g_syncs = syncs;
                g_sync_cap = cap;
            }
        }
        if (g_sync_count < g_sync_cap)
            g_syncs[g_sync_count++] = sync;
    }
    return sync;
}

static void cwcgl_glDeleteSync(GLsync sync) {
    for (size_t i = 0; i < g_sync_count; i++) {
        if (g_syncs[i] == sync) {
            g_syncs[i] = g_syncs[--g_sync_count];
            break;
        }
    }
    glDeleteSync(sync);
}

/* ---- public surface -------------------------------------------------- */

void cwcgl_registry_install(CwcGL_API *api) {
    api->__glGenTextures = cwcgl_glGenTextures;
    api->__glDeleteTextures = cwcgl_glDeleteTextures;
    api->__glGenBuffers = cwcgl_glGenBuffers;
    api->__glDeleteBuffers = cwcgl_glDeleteBuffers;
    api->__glGenFramebuffers = cwcgl_glGenFramebuffers;
    api->__glDeleteFramebuffers = cwcgl_glDeleteFramebuffers;
    api->__glGenRenderbuffers = cwcgl_glGenRenderbuffers;
    api->__glDeleteRenderbuffers = cwcgl_glDeleteRenderbuffers;
    api->__glGenVertexArrays = cwcgl_glGenVertexArrays;
    api->__glDeleteVertexArrays = cwcgl_glDeleteVertexArrays;
    api->__glGenQueries = cwcgl_glGenQueries;
    api->__glDeleteQueries = cwcgl_glDeleteQueries;
    api->__glGenSamplers = cwcgl_glGenSamplers;
    api->__glDeleteSamplers = cwcgl_glDeleteSamplers;
    api->__glCreateProgram = cwcgl_glCreateProgram;
    api->__glDeleteProgram = cwcgl_glDeleteProgram;
    api->__glCreateShader = cwcgl_glCreateShader;
    api->__glDeleteShader = cwcgl_glDeleteShader;
    api->__glFenceSync = cwcgl_glFenceSync;
    api->__glDeleteSync = cwcgl_glDeleteSync;
}

void cwcgl_registry_begin_epoch(void) {
    g_epoch++;
}

unsigned cwcgl_registry_current_epoch(void) {
    return g_epoch;
}

static void reset_bindings(void) {
    glUseProgram(0);
    glBindVertexArray(0);

    static const GLenum buffer_targets[] = {
        GL_ARRAY_BUFFER, GL_ELEMENT_ARRAY_BUFFER, GL_COPY_READ_BUFFER,
        GL_COPY_WRITE_BUFFER, GL_PIXEL_PACK_BUFFER, GL_PIXEL_UNPACK_BUFFER,
        GL_TEXTURE_BUFFER, GL_TRANSFORM_FEEDBACK_BUFFER, GL_UNIFORM_BUFFER,
    };
    for (size_t i = 0; i < sizeof(buffer_targets) / sizeof(buffer_targets[0]); i++)
        glBindBuffer(buffer_targets[i], 0);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);

    GLint max_units = 0;
    glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &max_units);
    static const GLenum texture_targets[] = {
        GL_TEXTURE_1D, GL_TEXTURE_2D, GL_TEXTURE_3D,
        GL_TEXTURE_1D_ARRAY, GL_TEXTURE_2D_ARRAY, GL_TEXTURE_RECTANGLE,
        GL_TEXTURE_CUBE_MAP, GL_TEXTURE_BUFFER,
        GL_TEXTURE_2D_MULTISAMPLE, GL_TEXTURE_2D_MULTISAMPLE_ARRAY,
    };
    for (GLint unit = 0; unit < max_units; unit++) {
        glActiveTexture(GL_TEXTURE0 + (GLenum)unit);
        for (size_t i = 0; i < sizeof(texture_targets) / sizeof(texture_targets[0]); i++)
            glBindTexture(texture_targets[i], 0);
        glBindSampler((GLuint)unit, 0);
    }
    glActiveTexture(GL_TEXTURE0);
}

size_t cwcgl_registry_tracked_count(CwcGL_LifecycleClass cls) {
    return g_sets[cls].count;
}

#if defined(CWCGL_DEBUG_VALIDATE)
static const char *const g_class_names[CWCGL_CLASS_COUNT] = {
    [CWCGL_CLASS_TEXTURE] = "texture",       [CWCGL_CLASS_BUFFER] = "buffer",
    [CWCGL_CLASS_FRAMEBUFFER] = "framebuffer", [CWCGL_CLASS_RENDERBUFFER] = "renderbuffer",
    [CWCGL_CLASS_VERTEX_ARRAY] = "vertex array", [CWCGL_CLASS_QUERY] = "query",
    [CWCGL_CLASS_SAMPLER] = "sampler",       [CWCGL_CLASS_PROGRAM] = "program",
    [CWCGL_CLASS_SHADER] = "shader",
};

static void report_leaks(void) {
    for (int cls = 0; cls < CWCGL_CLASS_COUNT; cls++) {
        if (g_sets[cls].count)
            fprintf(stderr, "cwcgl: teardown reclaiming %zu leaked %s(s) from epoch %u\n",
                    g_sets[cls].count, g_class_names[cls], g_epoch);
    }
    if (g_sync_count)
        fprintf(stderr, "cwcgl: teardown reclaiming %zu leaked sync object(s) from epoch %u\n",
                g_sync_count, g_epoch);
}
#endif

static void delete_tracked_objects(void) {
#if defined(CWCGL_DEBUG_VALIDATE)
    report_leaks();
#endif
    /* Programs/shaders first: a leaked program referencing leaked shaders
     * only actually frees once both sides are gone, but deletion order
     * between the two doesn't matter -- glDeleteShader on a still-attached
     * shader just flags it, same as it would in scene-authored cleanup. */
    for (size_t i = 0; i < g_sets[CWCGL_CLASS_PROGRAM].count; i++)
        glDeleteProgram(g_sets[CWCGL_CLASS_PROGRAM].ids[i]);
    g_sets[CWCGL_CLASS_PROGRAM].count = 0;

    for (size_t i = 0; i < g_sets[CWCGL_CLASS_SHADER].count; i++)
        glDeleteShader(g_sets[CWCGL_CLASS_SHADER].ids[i]);
    g_sets[CWCGL_CLASS_SHADER].count = 0;

    for (size_t i = 0; i < g_sync_count; i++)
        glDeleteSync(g_syncs[i]);
    g_sync_count = 0;

    set_delete_all(&g_sets[CWCGL_CLASS_VERTEX_ARRAY], glDeleteVertexArrays);
    set_delete_all(&g_sets[CWCGL_CLASS_BUFFER], glDeleteBuffers);
    set_delete_all(&g_sets[CWCGL_CLASS_RENDERBUFFER], glDeleteRenderbuffers);
    set_delete_all(&g_sets[CWCGL_CLASS_FRAMEBUFFER], glDeleteFramebuffers);
    set_delete_all(&g_sets[CWCGL_CLASS_TEXTURE], glDeleteTextures);
    set_delete_all(&g_sets[CWCGL_CLASS_QUERY], glDeleteQueries);
    set_delete_all(&g_sets[CWCGL_CLASS_SAMPLER], glDeleteSamplers);
}

static void reset_fixed_state(void) {
    glDisable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    glDisable(GL_SCISSOR_TEST);
    glDisable(GL_STENCIL_TEST);
    glDepthMask(GL_TRUE);
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
    glBlendFunc(GL_ONE, GL_ZERO);
    glDepthFunc(GL_LESS);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    glClearStencil(0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    /* Viewport is deliberately left alone: the host sets it from the
     * framebuffer size every frame (see src/host/main.c), so resetting it
     * here would just be overwritten before anything drew. */
}

void cwcgl_registry_teardown(void) {
    reset_bindings();
    delete_tracked_objects();
    reset_fixed_state();
}

#if defined(CWCGL_DEBUG_VALIDATE)
int cwcgl_registry_is_tracked(CwcGL_LifecycleClass cls, GLuint id) {
    if (id == 0)
        return 1;
    return set_contains(&g_sets[cls], id);
}

/* ---- debug-only consumer validation ---------------------------------
 *
 * Not exhaustive: GL 3.3 core has on the order of 200 functions that
 * consume a `class=` object (gl.xml's own count), and only the ones named
 * in the design plan plus their obvious siblings are covered here. Extend
 * by following the same pattern -- check cwcgl_registry_is_tracked(),
 * report, and pass through to the real call either way. See the sr.ht tracker.
 */
static void validate(CwcGL_LifecycleClass cls, GLuint id, const char *fn) {
    if (!cwcgl_registry_is_tracked(cls, id))
        fprintf(stderr,
                "cwcgl: %s called with handle %u not registered in epoch %u "
                "(stale handle from before the last reload?)\n",
                fn, id, g_epoch);
}

static void cwcgl_debug_glBindTexture(GLenum target, GLuint texture) {
    validate(CWCGL_CLASS_TEXTURE, texture, "glBindTexture");
    glBindTexture(target, texture);
}

static void cwcgl_debug_glBindBuffer(GLenum target, GLuint buffer) {
    validate(CWCGL_CLASS_BUFFER, buffer, "glBindBuffer");
    glBindBuffer(target, buffer);
}

static void cwcgl_debug_glBindFramebuffer(GLenum target, GLuint framebuffer) {
    validate(CWCGL_CLASS_FRAMEBUFFER, framebuffer, "glBindFramebuffer");
    glBindFramebuffer(target, framebuffer);
}

static void cwcgl_debug_glBindRenderbuffer(GLenum target, GLuint renderbuffer) {
    validate(CWCGL_CLASS_RENDERBUFFER, renderbuffer, "glBindRenderbuffer");
    glBindRenderbuffer(target, renderbuffer);
}

static void cwcgl_debug_glBindVertexArray(GLuint array) {
    validate(CWCGL_CLASS_VERTEX_ARRAY, array, "glBindVertexArray");
    glBindVertexArray(array);
}

static void cwcgl_debug_glBindSampler(GLuint unit, GLuint sampler) {
    validate(CWCGL_CLASS_SAMPLER, sampler, "glBindSampler");
    glBindSampler(unit, sampler);
}

static void cwcgl_debug_glUseProgram(GLuint program) {
    validate(CWCGL_CLASS_PROGRAM, program, "glUseProgram");
    glUseProgram(program);
}

static void cwcgl_debug_glLinkProgram(GLuint program) {
    validate(CWCGL_CLASS_PROGRAM, program, "glLinkProgram");
    glLinkProgram(program);
}

static void cwcgl_debug_glAttachShader(GLuint program, GLuint shader) {
    validate(CWCGL_CLASS_PROGRAM, program, "glAttachShader");
    validate(CWCGL_CLASS_SHADER, shader, "glAttachShader");
    glAttachShader(program, shader);
}

static void cwcgl_debug_glDetachShader(GLuint program, GLuint shader) {
    validate(CWCGL_CLASS_PROGRAM, program, "glDetachShader");
    validate(CWCGL_CLASS_SHADER, shader, "glDetachShader");
    glDetachShader(program, shader);
}

void cwcgl_registry_install_debug_validation(CwcGL_API *api) {
    api->__glBindTexture = cwcgl_debug_glBindTexture;
    api->__glBindBuffer = cwcgl_debug_glBindBuffer;
    api->__glBindFramebuffer = cwcgl_debug_glBindFramebuffer;
    api->__glBindRenderbuffer = cwcgl_debug_glBindRenderbuffer;
    api->__glBindVertexArray = cwcgl_debug_glBindVertexArray;
    api->__glBindSampler = cwcgl_debug_glBindSampler;
    api->__glUseProgram = cwcgl_debug_glUseProgram;
    api->__glLinkProgram = cwcgl_debug_glLinkProgram;
    api->__glAttachShader = cwcgl_debug_glAttachShader;
    api->__glDetachShader = cwcgl_debug_glDetachShader;
}
#endif
