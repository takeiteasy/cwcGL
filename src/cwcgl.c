/* cwcgl.c -- https://github.com/takeiteasy/cwcGL
 
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
 SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#include "cwcgl.h"

#define X(T, N) T cwcgl##N = (T)((void *)0);
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
#undef X

#if defined(CWCGL_WINDOWS) || defined(__CYGWIN__)
#ifndef _WINDOWS_
#undef APIENTRY
#endif
#include <windows.h>
typedef void* (APIENTRYP PFNWGLGETPROCADDRESSPROC_PRIVATE)(const char*);
static PFNWGLGETPROCADDRESSPROC_PRIVATE glLoaderGetProcAddressPtr;
static HMODULE libGL = NULL;

#ifdef _MSC_VER
#ifdef __has_include
#if __has_include(<winapifamily.h>)
#define HAVE_WINAPIFAMILY 1
#endif
#elif _MSC_VER >= 1700 && !_USING_V110_SDK71_
#define HAVE_WINAPIFAMILY 1
#endif
#endif

#ifdef HAVE_WINAPIFAMILY
#include <winapifamily.h>
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) && WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
#define IS_UWP 1
#endif
#endif

static int LoadGLLibrary(void) {
#ifndef IS_UWP
    if ((libGL = LoadLibraryW(L"opengl32.dll"))) {
        void(*tmp)(void);
        tmp = (void(*)(void)) GetProcAddress(libGL, "wglGetProcAddress");
        glLoaderGetProcAddressPtr = (PFNWGLGETPROCADDRESSPROC_PRIVATE)tmp;
        return glLoaderGetProcAddressPtr != NULL;
    }
#endif
    return 0;
}

static void CloseGLLibrary(void) {
    if (libGL) {
        FreeLibrary((HMODULE)libGL);
        libGL = NULL;
    }
}
#else
#include <dlfcn.h>
#if !defined(CWCGL_MAC) && !defined(__HAIKU__)
typedef void* (APIENTRYP PFNGLXGETPROCADDRESSPROC_PRIVATE)(const char*);
static PFNGLXGETPROCADDRESSPROC_PRIVATE glLoaderGetProcAddressPtr;
#endif
static void* libGL = NULL;

static int LoadGLLibrary(void) {
#if defined(CWCGL_MAC)
    static const char *NAMES[] = {
        "../Frameworks/OpenGL.framework/OpenGL",
        "/Library/Frameworks/OpenGL.framework/OpenGL",
        "/System/Library/Frameworks/OpenGL.framework/OpenGL",
        "/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL"
    };
#else
    static const char *NAMES[] = {"libGL.so.1", "libGL.so"};
#endif
    
    unsigned int index = 0;
    for (index = 0; index < (sizeof(NAMES) / sizeof(NAMES[0])); index++) {
        if ((libGL = dlopen(NAMES[index], RTLD_NOW | RTLD_GLOBAL))) {
#if defined(CWCGL_MAC) || defined(__HAIKU__)
            return 1;
#else
            glLoaderGetProcAddressPtr = (PFNGLXGETPROCADDRESSPROC_PRIVATE)dlsym(libGL,
                "glXGetProcAddressARB");
            return glLoaderGetProcAddressPtr != NULL;
#endif
        }
    }
    return 0;
}

static void CloseGLLibrary(void) {
    if (libGL) {
        dlclose(libGL);
        libGL = NULL;
    }
}
#endif

static void* LoadGLProc(const char *namez) {
    void* result = NULL;
    if (libGL == NULL)
        return NULL;

#if !defined(CWCGL_MAC) && !defined(__HAIKU__)
    if (glLoaderGetProcAddressPtr)
        result = glLoaderGetProcAddressPtr(namez);
#endif
    if (!result) {
#if defined(CWCGL_WINDOWS) || defined(__CYGWIN__)
        result = (void*)GetProcAddress((HMODULE)libGL, namez);
#else
        result = dlsym(libGL, namez);
#endif
    }

    return result;
}

#define X(T, N)                       \
    if (!(cwcgl##N = (T)LoadGLProc(#N))) \
        failures++;
static int failures = 0;
static int InitOpenGL(void) {
    int result = 0;
    if (LoadGLLibrary()) {
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
        result = failures == 0;
        CloseGLLibrary();
    }
    return result;
}
#undef X
    
#define CALLBACKS                                          \
    X(Display, (void))                                     \
    X(Reshape, (int width, int height))                    \
    X(Keyboard, (unsigned char key, int x, int y))         \
    X(Mouse, (int button, int state, int x, int y))        \
    X(Motion, (int x, int y))                              \
    X(PassiveMotion, (int x, int y))                       \
    X(Entry, (int state))                                  \
    X(Visibility, (int state))                             \
    X(Idle, (void))                                        \
    X(MenuState, (int state))                              \
    X(Special, (int key, int x, int y))                    \
    X(SpaceballMotion, (int x, int y, int z))              \
    X(SpaceballRotate, (int x, int y, int z))              \
    X(SpaceballButton, (int button, int state))            \
    X(ButtonBox, (int button, int state))                  \
    X(Dials, (int dial, int value))                        \
    X(TabletMotion, (int x, int y))                        \
    X(TabletButton, (int button, int state, int x, int y)) \
    X(MenuStatus, (int status, int x, int y))              \
    X(OverlayDisplay, (void))

static struct {
#define X(NAME, ARGS) void(*NAME##Callback)ARGS;
    CWCGL_CALLBACKS
#undef X
    int running;
    void *userdata;
} GLwindow = {0};

#define glCallCallback(CB, ...)  \
    if (GLwindow.CB##Callback)   \
        GLwindow.CB##Callback(GLwindow.userdata, __VA_ARGS__)

#define X(NAME, ARGS) \
    void(*NAME##Callback)ARGS,
void glWindowCallbacks(CWCGL_CALLBACKS void* userdata) {
#undef X
#define X(NAME, ARGS) \
    GLwindow.NAME##Callback = NAME##Callback;
    CWCGL_CALLBACKS
#undef X
    GLwindow.userdata = userdata;
}

#define X(NAME, ARGS)                                          \
    void glWindow##NAME##Callback(void(*NAME##Callback)ARGS) { \
        GLwindow.NAME##Callback = NAME##Callback;              \
    }
CWCGL_CALLBACKS
#undef X

void glWindowUserdata(void *userdata) {
    GLwindow.userdata = userdata;
}

int glIsWindowOpen(void) {
    return GLwindow.running;
}

#if defined(CWCGL_EMSCRIPTEN)
#include "backends/cwcgl_emscripten.c"
#elif defined(CWCGL_MAC)
#include "backends/cwcgl_mac.c"
#elif defined(CWCGL_WINDOWS)
#include "backends/cwcgl_windows.c"
#elif defined(CWCGL_LINUX)
#include "backends/cwcgl_linux.c"
#endif
