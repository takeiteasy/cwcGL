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

typedef struct {
    void *native;
    int id;
#define X(NAME, ARGS) void(*NAME##Func)ARGS;
    CALLBACKS
#undef X
} glWindow;

typedef struct glWindowEntry {
    glWindow window;
    struct glWindowEntry *next;
} glWindowBucket;

static struct {
    glWindowBucket *front, *back;
    int running, initialized;
    int x, y, width, height;
#define X(NAME, ARGS) void(*NAME##Func)ARGS;
    CALLBACKS
#undef X
    void(*TimerFunc)(int value);
} state;

static glWindow *currentWindow = NULL;
static int windowIDCounter = 0;

void* CreateNativeWindow(int x, int y, int w, int h, const char *title);
void PollNativeWindow(void *handle);
void FlushNativeWindow(void *handle);
void DestroyNativeWindow(void *handle);

#if defined(CWCGL_EMSCRIPTEN)
#include "backends/cwcgl_emscripten.c"
#elif defined(CWCGL_MAC)
#include "backends/cwcgl_mac.c"
#elif defined(CWCGL_WINDOWS)
#include "backends/cwcgl_windows.c"
#elif defined(CWCGL_LINUX)
#include "backends/cwcgl_linux.c"
#endif

void glutInit(int *argcp, char **argv) {
    state.initialized = 1;
    state.running = 0;
    state.x = -1;
    state.y = -1;
    state.width = 640;
    state.height = 480;
    state.front = state.back = NULL;
    InitOpenGL();
}

void glutInitDisplayMode(unsigned int mode) {
    
}

void glutInitWindowPosition(int x, int y) {
    state.x = x;
    state.y = y;
}

void glutInitWindowSize(int width, int height) {
    state.width = width;
    state.height = height;
}

void glutMainLoop(void) {
    assert(state.front);
    state.running = 1;
    
    while (state.running) {
#if defined(CWCGL_LINUX)
        glWindowBucket *bucket = state.front;
        while (bucket) {
            PollNativeWindow(bucket->window.native);
            if (bucket->window.DisplayFunc)
                bucket->window.DisplayFunc();
            bucket = bucket->next;
        }
#else
        PollNativeWindow(NULL);
        glWindowBucket *bucket = state.front;
        while (bucket) {
            if (bucket->window.DisplayFunc)
                bucket->window.DisplayFunc();
            bucket = bucket->next;
        }
#endif
    }
}

int glutCreateWindow(char *title) {
    assert(state.initialized);
    glWindowBucket *result = malloc(sizeof(glWindowBucket));
    result->window.id = windowIDCounter++;
#define X(NAME, ARGS) result->window.NAME##Func = state.NAME##Func;
    CALLBACKS
#undef X
    assert(result->window.native = CreateNativeWindow(state.x, state.y, state.width, state.height, title));
    
    if (!state.front)
        state.front = state.back = result;
    else {
        state.back->next = result;
        state.back = result;
    }
    if (!currentWindow)
        currentWindow = &result->window;
    return result->window.id;
}

int glutCreateSubWindow(int win, int x, int y, int width, int height) {
    return -1;
}

void glutDestroyWindow(int win) {
    
}

void glutPostRedisplay(void) {

}

void glutSwapBuffers(void) {

}

int glutGetWindow(void) {
    return -1;
}

void glutSetWindow(int win) {

}

void glutSetWindowTitle(char *title) {

}

void glutSetIconTitle(char *title) {

}

void glutPositionWindow(int x, int y) {

}

void glutReshapeWindow(int width, int height) {

}

void glutPopWindow(void) {

}

void glutPushWindow(void) {

}

void glutIconifyWindow(void) {

}

void glutShowWindow(void) {

}

void glutHideWindow(void) {

}

void glutFullScreen(void) {

}

void glutSetCursor(int cursor) {

}

void glutEstablishOverlay(void) {

}

void glutRemoveOverlay(void) {

}

void glutUseLayer(GLenum layer) {

}

void glutPostOverlayRedisplay(void) {

}

void glutShowOverlay(void) {

}

void glutHideOverlay(void) {

}

int glutCreateMenu(void(*fn)(int)) {
    return -1;
}

void glutDestroyMenu(int menu) {

}

int glutGetMenu(void) {
    return -1;
}

void glutSetMenu(int menu) {

}

void glutAddMenuEntry(char *label, int value) {

}

void glutAddSubMenu(char *label, int submenu) {

}

void glutChangeToMenuEntry(int item, char *label, int value) {

}

void glutChangeToSubMenu(int item, char *label, int submenu) {

}

void glutRemoveMenuItem(int item) {

}

void glutAttachMenu(int button) {

}

void glutDetachMenu(int button) {

}

#define X(NAME, ARGS) \
void glut##NAME##Func(void(*callback)ARGS) { \
    state.NAME##Func = callback; \
}
CALLBACKS
#undef X

void glutTimerFunc(unsigned int millis, void(*fn)(int value), int value) {
    state.TimerFunc = fn;
}

void glutSetColor(int cell, GLfloat red, GLfloat green, GLfloat blue) {

}

GLfloat glutGetColor(int cell, int component) {
    return 0.f;
}

void glutCopyColormap(int win) {

}

int glutGet(GLenum type) {
    return -1;
}

int glutDeviceGet(GLenum type) {
    return -1;
}

int glutExtensionSupported(char *name) {
    return -1;
}

int glutGetModifiers(void) {
    return -1;
}

int glutLayerGet(GLenum type) {
    return -1;
}

void glutBitmapCharacter(void *font, int character) {

}

int glutBitmapWidth(void *font, int character) {
    return -1;
}

void glutStrokeCharacter(void *font, int character) {

}

int glutStrokeWidth(void *font, int character) {
    return -1;
}

void glutWireSphere(GLdouble radius, GLint slices, GLint stacks) {

}

void glutSolidSphere(GLdouble radius, GLint slices, GLint stacks) {

}

void glutWireCone(GLdouble base, GLdouble height, GLint slices, GLint stacks) {

}

void glutSolidCone(GLdouble base, GLdouble height, GLint slices, GLint stacks) {

}

void glutWireCube(GLdouble size) {

}

void glutSolidCube(GLdouble size) {

}

void glutWireTorus(GLdouble innerRadius, GLdouble outerRadius, GLint sides, GLint rings) {

}

void glutSolidTorus(GLdouble innerRadius, GLdouble outerRadius, GLint sides, GLint rings) {

}

void glutWireDodecahedron(void) {

}

void glutSolidDodecahedron(void) {

}

void glutWireTeapot(GLdouble size) {

}

void glutSolidTeapot(GLdouble size) {

}

void glutWireOctahedron(void) {

}

void glutSolidOctahedron(void) {

}

void glutWireTetrahedron(void) {

}

void glutSolidTetrahedron(void) {

}

void glutWireIcosahedron(void) {

}

void glutSolidIcosahedron(void) {

}
