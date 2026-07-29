/* host.c -- GLFW test host for src/reload.{h,c} + src/loader.{h,c} +
 * src/registry.{h,c}. Not part of the library: this is the manual
 * integration test that proves hot-reload, the ABI guard, and GL object
 * lifecycle tracking all work together against a live GL context. See
 * test/leak_test.c for the dylib it loads.
 *
 * The dylib contract is three plain, individually-exported functions --
 * no shared struct, no app-framework fields (window size/title/fps aren't
 * this library's concern):
 *
 *   void test_init(void);          looked up once, on the first load
 *   int  test_tick(double delta);  the primary export; return 0 to quit
 *   void test_reload(void);        looked up on every load after the first
 *   void test_unload(void);        looked up before every unload
 *
 * Only test_tick is mandatory (it's reload_desc.symbol); the rest are
 * optional lookups via cwcgl_reload_lookup.
 */
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "cwcgl.h"

#include <stdio.h>
#include <string.h>

typedef void (*test_init_fn)(void);
typedef int  (*test_tick_fn)(double delta);
typedef void (*test_reload_fn)(void);
typedef void (*test_unload_fn)(void);

typedef struct {
    reload_lib *lib;
    test_tick_fn tick;
    CwcGL_API api;
    int have_init;
    /* False whenever `tick` may point into an already-dlclose'd image --
     * reload_poll() unloads the old dylib before loading the new one, so a
     * failed reload leaves nothing safely callable until the next good
     * load. See the sr.ht tracker (ticket #5). */
    int valid;
} host_state;

static void build_api(CwcGL_API *api) {
    memset(api, 0, sizeof(*api));
    api->magic = CWCGL_ABI_MAGIC;
    api->abi_version = CWCGL_ABI_VERSION;
    api->struct_size = sizeof(CwcGL_API);

#define X(T, N) api->N = __##N;
#if CWCGL_VERSION >= GL_VERSION_1_0
    GL_FUNCTIONS_1_0
#endif
#if CWCGL_VERSION >= GL_VERSION_1_1
    GL_FUNCTIONS_1_1
#endif
#if CWCGL_VERSION >= GL_VERSION_1_2
    GL_FUNCTIONS_1_2
#endif
#if CWCGL_VERSION >= GL_VERSION_1_3
    GL_FUNCTIONS_1_3
#endif
#if CWCGL_VERSION >= GL_VERSION_1_4
    GL_FUNCTIONS_1_4
#endif
#if CWCGL_VERSION >= GL_VERSION_1_5
    GL_FUNCTIONS_1_5
#endif
#if CWCGL_VERSION >= GL_VERSION_2_0
    GL_FUNCTIONS_2_0
#endif
#if CWCGL_VERSION >= GL_VERSION_2_1
    GL_FUNCTIONS_2_1
#endif
#if CWCGL_VERSION >= GL_VERSION_3_0
    GL_FUNCTIONS_3_0
#endif
#if CWCGL_VERSION >= GL_VERSION_3_1
    GL_FUNCTIONS_3_1
#endif
#if CWCGL_VERSION >= GL_VERSION_3_2
    GL_FUNCTIONS_3_2
#endif
#if CWCGL_VERSION >= GL_VERSION_3_3
    GL_FUNCTIONS_3_3
#endif
#if CWCGL_VERSION >= GL_VERSION_4_0
    GL_FUNCTIONS_4_0
#endif
#if CWCGL_VERSION >= GL_VERSION_4_1
    GL_FUNCTIONS_4_1
#endif
#if CWCGL_VERSION >= GL_VERSION_4_2
    GL_FUNCTIONS_4_2
#endif
#if CWCGL_VERSION >= GL_VERSION_4_3
    GL_FUNCTIONS_4_3
#endif
#if CWCGL_VERSION >= GL_VERSION_4_4
    GL_FUNCTIONS_4_4
#endif
#if CWCGL_VERSION >= GL_VERSION_4_5
    GL_FUNCTIONS_4_5
#endif
#if CWCGL_VERSION >= GL_VERSION_4_6
    GL_FUNCTIONS_4_6
#endif
#undef X
}

static bool on_load(reload_lib *lib, void *sym, void *userdata) {
    host_state *hs = (host_state *)userdata;
    test_tick_fn tick = (test_tick_fn)sym;

    cwcglLoadAPI_fn load_api = (cwcglLoadAPI_fn)cwcgl_reload_lookup(lib, "cwcglLoadAPI");
    if (!load_api) {
        fprintf(stderr, "test dylib missing cwcglLoadAPI export -- not linked against client.c?\n");
        return false;
    }
    if (!load_api(&hs->api)) {
        fprintf(stderr, "test dylib rejected by cwcglLoadAPI -- rebuild it against this cwcGL (ABI mismatch)\n");
        return false;
    }

    /* Fresh epoch on every load, first one included -- the registry was
     * just emptied by teardown() in on_unload (or has never held anything
     * yet), so this never needs a first-load special case. */
    cwcgl_registry_begin_epoch();

    if (!hs->have_init) {
        test_init_fn init = (test_init_fn)cwcgl_reload_lookup(lib, "test_init");
        if (init)
            init();
        hs->have_init = 1;
    } else {
        test_reload_fn reload_fn = (test_reload_fn)cwcgl_reload_lookup(lib, "test_reload");
        if (reload_fn)
            reload_fn();
    }

    /* Only commit `tick`/`valid` once every fallible step above has
     * succeeded -- see host_state.valid for why. */
    hs->tick = tick;
    hs->valid = 1;
    return true;
}

static void on_unload(reload_lib *lib, void *sym, void *userdata) {
    (void)sym;
    host_state *hs = (host_state *)userdata;
    hs->valid = 0;
    /* Runs before dlclose, so the driver still has every object this
     * dylib ever allocated (via glGen-family or glCreate-family calls)
     * even if it never freed them -- teardown reclaims those and resets
     * fixed-function state before the next load's init()/reload() runs. */
    cwcgl_registry_teardown();
    test_unload_fn unload = (test_unload_fn)cwcgl_reload_lookup(lib, "test_unload");
    if (unload)
        unload();
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s [path to test dylib]\n", argv[0]);
        return 1;
    }

    if (!glfwInit()) {
        fprintf(stderr, "glfwInit failed\n");
        return 1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

    GLFWwindow *window = glfwCreateWindow(800, 600, "cwcgl test host", NULL, NULL);
    if (!window) {
        fprintf(stderr, "glfwCreateWindow failed\n");
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    if (cwcgl_InitOpenGL()) {
        fprintf(stderr, "cwcgl_InitOpenGL failed to resolve one or more GL entry points\n");
        glfwTerminate();
        return 1;
    }

    host_state hs = {0};
    build_api(&hs.api);
    cwcgl_registry_install(&hs.api);
#if defined(CWCGL_DEBUG_VALIDATE)
    cwcgl_registry_install_debug_validation(&hs.api);
#endif

    reload_desc desc = {
        .path = argv[1],
        .symbol = "test_tick",
        .userdata = &hs,
        .on_load = on_load,
        .on_unload = on_unload,
    };
    hs.lib = cwcgl_reload_open(&desc);
    if (!hs.lib) {
        fprintf(stderr, "failed to load test dylib: %s\n", argv[1]);
        glfwTerminate();
        return 1;
    }

    double last = glfwGetTime();
    while (!glfwWindowShouldClose(window)) {
        double now = glfwGetTime();
        double delta = now - last;
        last = now;

        if (!cwcgl_reload_poll(hs.lib))
            fprintf(stderr, "reload failed, waiting for a fixed build...\n");

        int fbw, fbh;
        glfwGetFramebufferSize(window, &fbw, &fbh);
        glViewport(0, 0, fbw, fbh);

        /* hs.tick can be left dangling by a failed cwcgl_reload_poll() (see
         * host_state.valid) -- skip ticking rather than calling through a
         * pointer into an already-dlclose'd image. */
        if (hs.valid && !hs.tick(delta))
            break;

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    cwcgl_reload_close(hs.lib);
    cwcgl_CloseGLLibrary();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
