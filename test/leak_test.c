/* leak_test.c -- the one dylib test/host.c loads. Deliberately misbehaves
 * two ways, to prove cwcgl_registry's teardown (src/registry.c)
 * actually reclaims what it's told to, whether or not the code being
 * reloaded cleaned up after itself:
 *
 *  - test_init()/test_reload() allocate a texture and never call
 *    glDeleteTextures on it, and don't even keep the handle around --
 *    teardown must reclaim it anyway, from tracking alone.
 *  - test_init() enables GL_BLEND and never disables it -- teardown's
 *    fixed-state reset must turn it back off before the next load's
 *    tick() runs, or the raw orange-on-black tick() below would come out
 *    alpha-blended against the clear color instead of opaque.
 *
 * Build a debug host (`make DEBUG=1`) to see teardown log each reclaimed
 * leak by class and epoch as it happens.
 */
#include "cwcgl.h"
#include <stddef.h>

/* State lives in file-statics -- test dylibs don't need anything like a
 * persistent State pointer surviving reload, unlike a real application. */
static GLuint vao, vbo, program;
static GLint color_loc;

static const float verts[] = {
     0.0f,  0.6f, 0.0f,
    -0.6f, -0.6f, 0.0f,
     0.6f, -0.6f, 0.0f,
};

static const char *vs_src =
    "#version 330 core\n"
    "layout(location = 0) in vec3 pos;\n"
    "void main() { gl_Position = vec4(pos, 1.0); }\n";

static const char *fs_src =
    "#version 330 core\n"
    "uniform vec4 color;\n"
    "out vec4 frag;\n"
    "void main() { frag = color; }\n";

static GLuint compile(GLenum type, const char *src) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &src, NULL);
    glCompileShader(shader);
    return shader;
}

static void leak_a_texture(void) {
    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 64, 64, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
    /* No glDeleteTextures, and `tex` isn't stored anywhere -- the handle
     * is gone the moment this function returns. If teardown didn't track
     * allocations independently of this code, it would leak for real,
     * forever, across every reload. */
}

static void build_gl_objects(void) {
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
    glEnableVertexAttribArray(0);

    GLuint vs = compile(GL_VERTEX_SHADER, vs_src);
    GLuint fs = compile(GL_FRAGMENT_SHADER, fs_src);
    program = glCreateProgram();
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glDeleteShader(vs);
    glDeleteShader(fs);
    color_loc = glGetUniformLocation(program, "color");

    leak_a_texture();
}

CWCGL_EXPORT void test_init(void) {
    build_gl_objects();
    /* Left enabled on purpose -- never disabled anywhere in this file. */
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

CWCGL_EXPORT void test_reload(void) {
    build_gl_objects(); /* leaks another texture every reload */
}

CWCGL_EXPORT void test_unload(void) {
}

CWCGL_EXPORT int test_tick(double delta) {
    (void)delta;
    glClearColor(0.15f, 0.05f, 0.05f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(program);
    glUniform4f(color_loc, 1.0f, 0.4f, 0.1f, 1.0f);
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    return 1;
}
