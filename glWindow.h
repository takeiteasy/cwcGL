/* glWindow.h -- https://github.com/takeiteasy/glWindow
 
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
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @header glWidow Yet another cross-platform OpenGL context
 * @copyright George Watson
 */

#if defined(__EMSCRIPTEN__) || defined(EMSCRIPTEN)
#define GL_WIN_EMSCRIPTEN
#endif
#if defined(macintosh) || defined(Macintosh) || (defined(__APPLE__) && defined(__MACH__))
#define GL_WIN_MAC
#elif defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__WINDOWS__)
#define GL_WIN_WINDOWS
#elif defined(__gnu_linux__) || defined(__linux__) || defined(__unix__)
#define GL_WIN_LINUX
#else
#error Sorry, unsupported operating system!
#endif

#if defined(GL_WIN_WINDOWS)
#define EXPORT __declspec(dllexport)
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
 * @constant KEY_MOD_CAPS Caps lock key modifier
 * @constant KEY_MOD_LOCK Num lock key modifier
 * @discussion Multiple modifiers will be shifted together so check with & operator
 */
typedef enum {
    KEY_MOD_SHIFT   = 1 << 0,
    KEY_MOD_CONTROL = 1 << 1,
    KEY_MOD_ALT     = 1 << 2,
    KEY_MOD_SUPER   = 1 << 3,
    KEY_MOD_CAPS    = 1 << 4,
    KEY_MOD_LOCK    = 1 << 5
} GLmod;

#define GL_WIN_CALLBACKS                             \
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
 * @abstract Close all windows + free all resources
 */
EXPORT void glWindowQuit(void);
/*!
 * @function glGetTime
 * @abstract High resolution timer
 * @return Current elapsed CPU time
 */
EXPORT double glGetTime(void);

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
EXPORT void glWindowCallbacks(GL_WIN_CALLBACKS void *userdata);
#undef X
#define X(NAME, ARGS) \
    EXPORT void glWindow##NAME##Callback(void(*NAME##Callback)ARGS);
GL_WIN_CALLBACKS
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
 * @enum GLcursor
 * @abstract System cursors
 * @constant ArrowCursor Default arrow cursor
 * @constant IBeamCursor I-Beam Cursor
 * @constant WaitCursor Wait cursor
 * @constant CrosshairCursor Crosshair
 * @constant WaitArrowCursor Waiting arrow cursor
 * @constant NWSECursor North-West, South-East cursor
 * @constant NESWCursor North-East, South-West cursor
 * @constant WECursor West-East cursor
 * @constant NSCursor North-South cursor
 * @constant MoveCursor All-direction cursor
 * @constant StopCursor Stop-symbol cursor
 * @constant HandCursor Hand cursor
 */
typedef enum {
    ArrowCursor = 0,   // Arrow
    IBeamCursor,       // I-beam
    WaitCursor,        // Wait
    CrosshairCursor,   // Crosshair
    WaitArrowCursor,   // Small wait cursor (or Wait if not available)
    NWSECursor,        // Double arrow pointing northwest and southeast
    NESWCursor,        // Double arrow pointing northeast and southwest
    WECursor,          // Double arrow pointing west and east
    NSCursor,          // Double arrow pointing north and south
    MoveCursor,        // Four pointed arrow pointing north, south, east, and west
    StopCursor,        // Slashed circle or crossbones
    HandCursor         // Hand
} GLcursor;

/*!
 * @function glSetWindowIcon
 * @abstract Set window icon from glImage
 * @param data Image data
 * @param w Image width
 * @param h Image height
 * @return Returns 1 on success, 0 on failure
 */
EXPORT int glSetWindowIcon(unsigned char *data, int w, int h);
/*!
 * @function glSetCursor
 * @abstract Change the cursor for a window
 * @param cursor System cursor
 */
EXPORT void glSetCursor(GLcursor cursor);
/*!
 * @function glSetCustomCursor
 * @abstract Change the cursor for a window from a glImage
 * @param data Image data
 * @param w Image width
 * @param h Image height
 * @return Returns 1 on success, 0 on failure
 */
EXPORT int glSetCustomCursor(unsigned char *data, int w, int h);
/*!
 * @function glHideCursor
 * @abstract Hide the cursor when window is active
 */
EXPORT void glHideCursor(void);
/*!
 * @function glShowCursor
 * @abstract Show the cursor when window is active
 */
EXPORT void glShowCursor(void);
/*!
 * @function glDisableCursor
 * @abstract When window is active, cursor won't move
 */
EXPORT void glDisableCursor(void);
/*!
 * @function glEnableCursor
 * @abstract Undo glDisableCursor
 */
EXPORT void glEnableCursor(void);
/*!
 * @function glCursorPosition
 * @abstract Get the position of the cursor
 * @param x Returns the cursor's X position
 * @param y Returns the cursor's Y position
 */
EXPORT void glCursorPosition(int *x, int *y);
/*!
 * @function glSetCursorPosition
 * @abstract Set the cursor position
 * @param x Cursor's new X position
 * @param y Cursor's new Y position
 */
EXPORT void glSetCursorPosition(int x, int y);
/*!
 * @function glWindowPosition
 * @abstract Get the window's current position
 * @param x Returns the windows's X position
 * @param y Returns the windows's Y position
 */
EXPORT void glWindowPosition(int *x, int *y);
/*!
 * @function glSetWindowPosition
 * @abstract Set a windows position
 * @param x Window's new X position
 * @param y Window's new Y position
 */
EXPORT void glSetWindowPosition(int x, int y);
/*!
 * @function glWindowSize
 * @abstract Get a windows size
 * @param w Returns the window's width
 * @param h Returns the window's height
 */
EXPORT void glWindowSize(int *w, int *h);
/*!
 * @function glWindowSetSize
 * @abstract Set a windows size
 * @param w Window's new width
 * @param h Window's new height
 */
EXPORT void glWindowSetSize(int w, int h);
/*!
 * @function glWindowScreenSize
 * @abstract Get the screen size of a windows current screen
 * @param w Returns current screen's width
 * @param h Returns current screen's height
 */
EXPORT void glWindowScreenSize(int *w, int *h);
/*!
 * @function glSetWindowTitle
 * @abstract Set a window's title
 * @param title Window's new title
 */
EXPORT void glSetWindowTitle(const char *title);

#if defined(__cplusplus)
}
#endif
#endif // glWindow_h
