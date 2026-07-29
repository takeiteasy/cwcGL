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

/* registry.h -- GL object lifecycle tracking, host-side only.
 *
 * Tracks every object a scene allocates through the ~20 GL 3.3 lifecycle
 * functions (GL_LIFECYCLE_FUNCTIONS in loader.h) so a reload can guarantee
 * no GL object or fixed-function state survives it, whether or not the
 * scene cleaned up after itself. Scenes never call anything in this file
 * directly -- cwcgl_registry_install() patches the CwcGL_API struct the
 * host hands over so tracking is transparent to scene code.
 *
 * Knows nothing about reload or windowing; the host wires it in via its
 * own on_load/on_unload hooks (see test/host.c).
 */
#ifndef CWCGL_REGISTRY_H
#define CWCGL_REGISTRY_H
#if defined(__cplusplus)
extern "C" {
#endif

#include "loader.h"
#include <stddef.h>

/* One entry per distinct `class=` value among the 20 GL_LIFECYCLE_FUNCTIONS
 * rows in cwcgl.h (several rows share a class -- e.g. TEXTURE covers both
 * glGenTextures and glDeleteTextures). Not generated: gl.rb emits the
 * (name, class, kind, arity) rows as metadata, this enum is the hand-written
 * registry's own indexing scheme over them. */
typedef enum {
    CWCGL_CLASS_TEXTURE,
    CWCGL_CLASS_BUFFER,
    CWCGL_CLASS_FRAMEBUFFER,
    CWCGL_CLASS_RENDERBUFFER,
    CWCGL_CLASS_VERTEX_ARRAY,
    CWCGL_CLASS_QUERY,
    CWCGL_CLASS_SAMPLER,
    CWCGL_CLASS_PROGRAM,
    CWCGL_CLASS_SHADER,
    CWCGL_CLASS_COUNT
} CwcGL_LifecycleClass;

/* Overwrites the ~20 lifecycle fields of `api` (glGenTextures, glDeleteBuffers,
 * glCreateShader, ...) with tracking wrappers; every other field is left as
 * whatever the host already put there (the raw driver pointer). Call once,
 * after build_api() has populated `api` from the host's own __glFoo globals. */
void cwcgl_registry_install(CwcGL_API *api);

/* Starts a fresh tracking epoch. Call once per scene (re)load, after
 * cwcglLoadAPI() succeeds and before dispatching to init()/reload() --
 * first load included, so epoch numbering has no special case. */
void cwcgl_registry_begin_epoch(void);

/* Returns the number of cwcgl_registry_begin_epoch() calls so far (1 for the
 * very first load). Debug/diagnostic use only -- not part of the ABI handed
 * to scenes. */
unsigned cwcgl_registry_current_epoch(void);

/* Unwinds everything the current epoch allocated and never freed: resets
 * bindings, deletes tracked objects, resets fixed-function state. Call from
 * on_unload, before the dylib backing the current epoch is dlclose'd. Safe
 * to call with an empty registry (first load has nothing to tear down). */
void cwcgl_registry_teardown(void);

/* Number of objects of `cls` currently tracked (i.e. allocated and not yet
 * deleted, by the scene or by a prior teardown). Always available -- not
 * gated behind CWCGL_DEBUG_VALIDATE -- so tests can assert on
 * leak counts without a debug build. Call before teardown to see what a
 * scene left behind; always 0 immediately after. */
size_t cwcgl_registry_tracked_count(CwcGL_LifecycleClass cls);

#if defined(CWCGL_DEBUG_VALIDATE)
/* Debug builds only: true if `id` was allocated in the current epoch and is
 * still tracked (i.e. not deleted). Handle 0 (the universal "unbind" value)
 * always passes. Used by the debug consumer-validation wrappers installed
 * alongside the lifecycle wrappers; exposed here so tests/tools can also
 * probe registry state directly.
 *
 * Known limitation: this is a presence check, not a per-object generation
 * stamp. If a scene keeps a stale GLuint across a reload and the driver
 * happens to reissue that exact numeric name to a *new* object in the new
 * epoch, this reports "valid" even though it is logically the wrong object.
 * Catching that requires tagging each id with its creation epoch, not just
 * membership in the current set -- not implemented; see the sr.ht tracker. */
int cwcgl_registry_is_tracked(CwcGL_LifecycleClass cls, GLuint id);

/* Debug builds only: patches a representative set of consumer functions
 * (glBindTexture, glUseProgram, glAttachShader, and their obvious siblings
 * -- not exhaustive, see the sr.ht tracker) to reject handles not tracked in the
 * current epoch. Call after cwcgl_registry_install(); release builds skip
 * this entirely, so they pay for none of these extra wrappers. */
void cwcgl_registry_install_debug_validation(CwcGL_API *api);
#endif

#if defined(__cplusplus)
}
#endif
#endif // CWCGL_REGISTRY_H
