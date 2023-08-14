/* glWindow.h -- https://github.com/takeiteasy/fungl
 
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

#ifndef glWindow_h
#define glWindow_h
#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @header glWindow
 * @copyright George Watson
 */

#if defined(__EMSCRIPTEN__) || defined(EMSCRIPTEN)
#define GLW_EMSCRIPTEN
#include <emscripten.h>
#endif

#if defined(macintosh) || defined(Macintosh) || (defined(__APPLE__) && defined(__MACH__))
#define GLW_MAC
#elif defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__WINDOWS__)
#define GLW_WINDOWS
#elif defined(__gnu_linux__) || defined(__linux__) || defined(__unix__)
#define GLW_LINUX
#else
#error Sorry, unsupported operating system!
#endif

#if defined(GLW_EMSCRIPTEN)
#if defined(GL_LEGACY)
#define GL_VERSION_MAJOR 1
#else
#define GL_VERSION_MAJOR 2
#endif
#else
#if !defined(GL_LEGACY)
#define DEFAULT_GL_VERSION_MAJOR 3
#define DEFAULT_GL_VERSION_MINOR 2
#if !defined(GL_VERSION_MAJOR) && !defined(GL_VERSION_MINOR)
#define GL_VERSION_MAJOR DEFAULT_GL_VERSION_MAJOR
#define GL_VERSION_MINOR DEFAULT_GL_VERSION_MINOR
#endif
#if defined(GL_VERSION_MAJOR)
#if !defined(GL_VERSION_MINOR)
#if GL_VERSION_MAJOR == DEFAULT_GL_VERSION_MAJOR
#define GL_VERSION_MINOR DEFAULT_GL_VERSION_MINOR
#else
#define GL_VERSION_MINOR 0
#endif
#endif
#endif
#endif
#endif

#if defined(GLW_WINDOWS)
#define EXPORT __declspec(dllexport)
#elif defined(GLW_EMSCRIPTEN)
#define EXPORT EMSCRIPTEN_KEEPALIVE
#else
#define EXPORT
#endif

/*!
 * @enum GLflags
 * @abstract Window config flags
 * @constant glResizable Resizable window flag
 * @constant glFullscreen Fullscreen window flag
 * @constant glFullscreenDesktop Window will resize to size of screen
 * @constant glBorderless Borderless window flag
 * @constant glAlwaysOnTop Floating window flag
 * @discussion Flags can be shifted together with | operator
 */
typedef enum {
    glResizable         = 1 << 0,
    glFullscreen        = 1 << 1,
    glFullscreenDesktop = 1 << 2,
    glBorderless        = 1 << 3,
    glAlwaysOnTop       = 1 << 4
} GLflags;
/*!
 * @typedef GLkeys
 * @abstract Keyboard key type
 */
typedef enum {
    KEY_PAD0=128,KEY_PAD1,KEY_PAD2,KEY_PAD3,KEY_PAD4,KEY_PAD5,KEY_PAD6,KEY_PAD7,KEY_PAD8,KEY_PAD9,
    KEY_PADMUL,KEY_PADADD,KEY_PADENTER,KEY_PADSUB,KEY_PADDOT,KEY_PADDIV,
    KEY_F1,KEY_F2,KEY_F3,KEY_F4,KEY_F5,KEY_F6,KEY_F7,KEY_F8,KEY_F9,KEY_F10,KEY_F11,KEY_F12,
    KEY_BACKSPACE,KEY_TAB,KEY_RETURN,KEY_SHIFT,KEY_CONTROL,KEY_ALT,KEY_PAUSE,KEY_CAPSLOCK,
    KEY_ESCAPE,KEY_SPACE,KEY_PAGEUP,KEY_PAGEDN,KEY_END,KEY_HOME,KEY_LEFT,KEY_UP,KEY_RIGHT,KEY_DOWN,
    KEY_INSERT,KEY_DELETE,KEY_LWIN,KEY_RWIN,KEY_NUMLOCK,KEY_SCROLL,KEY_LSHIFT,KEY_RSHIFT,
    KEY_LCONTROL,KEY_RCONTROL,KEY_LALT,KEY_RALT,KEY_SEMICOLON,KEY_EQUALS,KEY_COMMA,KEY_MINUS,
    KEY_DOT,KEY_SLASH,KEY_BACKTICK,KEY_LSQUARE,KEY_BACKSLASH,KEY_RSQUARE,KEY_TICK
} GLkey;
/*!
 * @enum GLmod
 * @abstract Keyboard modifier type
 * @constant KEY_MOD_SHIFT Shift key modifier
 * @constant KEY_MOD_CONTROL Control key modifier
 * @constant KEY_MOD_ALT Alt key modifier
 * @constant KEY_MOD_SUPER Windows/Super key modifier
 * @constant KEY_MOD_CAPS_LOCK Caps lock key modifier
 * @constant KEY_MOD_NUM_LOCK Num lock key modifier
 * @discussion Multiple modifiers will be shifted together so check with & operator
 */
typedef enum {
    KEY_MOD_SHIFT     = 1 << 0,
    KEY_MOD_CONTROL   = 1 << 1,
    KEY_MOD_ALT       = 1 << 2,
    KEY_MOD_SUPER     = 1 << 3,
    KEY_MOD_CAPS_LOCK = 1 << 4,
    KEY_MOD_NUM_LOCK  = 1 << 5
} GLmod;

#define GLW_CALLBACKS                             \
    X(Keyboard,     (void*, GLkey, GLmod, int))      \
    X(MouseButton,  (void*, int, GLmod, int))        \
    X(MouseMove,    (void*, int, int, float, float)) \
    X(MouseScroll,  (void*, float, float, GLmod))    \
    X(Resized,      (void*, int, int))               \
    X(Focus,        (void*, int))                    \
    X(Closed,       (void*))

/*!
 * @function glWindow
 * @abstract Create a new OpenGL window
 * @param w Window width
 * @param h Window height
 * @param title Window title
 * @param flags Window flags
 * @return Returns 1 if window creation successful, 0 for failure
 */
EXPORT int glWindow(unsigned int w, unsigned int h, const char *title, GLflags flags);
/*!
 * @function glPollWindow
 * @abstract Poll a window for events
 * @return Returns 1 if window is still open, 0 if closed
 */
EXPORT int glPollWindow(void);
/*!
 * @function glFlushWindow
 * @abstract Render OpenGL to window
 */
EXPORT void glFlushWindow(void);
/*!
 * @function glWindowQuit
 * @abstract Close window + free all resources
 */
EXPORT void glWindowQuit(void);

#define X(NAME, ARGS) \
    void(*NAME##Callback)ARGS,
/*!
 * @function glWindowCallbacks
 * @abstract Assign window event callbacks
 * @param KeyboardCallback Callback for keyboard events
 * @param MouseButtonCallback Callback for mouse button events
 * @param MouseMoveCallback Callback for mouse movement event
 * @param MouseScrollCallback Callback for mouse scroll event
 * @param ResizedCallback Callback for window resize event
 * @param FocusCallback Callback for window focus/blur events
 * @param ClosedCallback Callback for window close event
 * @param userdata Userdata stored by pp, passed to callback functions
 * @discussion All callbacks are optional, pass NULL to skip callback. These can also be set individually, e.g. glWindowKeyboardCallback(cb)
 */
EXPORT void glWindowCallbacks(GLW_CALLBACKS void *userdata);
#undef X
#define X(NAME, ARGS) \
    EXPORT void glWindow##NAME##Callback(void(*NAME##Callback)ARGS);
GLW_CALLBACKS
#undef X

/*!
 * @function glWindowUserData
 * @abstract Assign userdata to be send to window event callbacks
 * @param userdata Custom userdata
 */
EXPORT void glWindowUserdata(void *userdata);
/*!
 * @function glIsWindowOpen
 * @abstract Check if a window is still open
 * @return Returns 1 if window is still open, 0 is closed
 */
EXPORT int glIsWindowOpen(void);
/*!
 * @function glWindowNative
 * @abstract Retrieve the native window handle
 * @return Returns pointer to native window handle
 */
EXPORT void* glWindowNative(void);

#ifdef __cplusplus
}
#endif
#endif // glWindow_h
