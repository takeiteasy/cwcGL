/* glLinux.c -- https://github.com/takeiteasy/glWindow
 
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

#include "glCommon.c"
#include <sys/time.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xlocale.h>
#include <X11/XKBlib.h>
#include <GL/glx.h>

static struct {
    Display *display;
    Window root, window;
    GLXContext glc;
    int screen;
    int width, height;
    Atom delete;
    GC gc;
    int cursorLastX, cursorLastY;
} GLnative = {0};

struct Hints {
    unsigned long flags;
    unsigned long functions;
    unsigned long decorations;
    long input_mode;
    unsigned long status;
};

int glWindow(unsigned int w, unsigned int h, const char *title, GLflags flags) {
    if (GLwindow.running)
        return 0;
    
    if (!(GLnative.display = XOpenDisplay(NULL)))
        return 0;
    GLnative.root   = DefaultRootWindow(GLnative.display);
    GLnative.screen = DefaultScreen(GLnative.display);
    
    int screenW = DisplayWidth(GLnative.display, GLnative.screen);
    int screenH = DisplayHeight(GLnative.display, GLnative.screen);
    
    if (flags & ppFullscreen)
        flags = ppFullscreen | ppBorderless;
    
    int x = 0, y = 0;
    if (flags & ppFullscreen || flags & ppFullscreenDesktop) {
        w = screenW;
        h = screenH;
    } else {
        x = screenW / 2 - w / 2;
        y = screenH / 2 - h / 2;
    }
    
    Visual *visual = DefaultVisual(GLnative.display, GLnative.screen);
    int format_c = 0;
    XPixmapFormatValues* formats = XListPixmapFormats(GLnative.display, &format_c);
    GLnative.depth = DefaultDepth(GLnative.display, GLnative.screen);
    int depth_c;
    for (int i = 0; i < format_c; ++i)
        if (GLnative.depth == formats[i].depth) {
            depth_c = formats[i].bits_per_pixel;
            break;
        }
    XFree(formats);
    if (depth_c != 32)
        return 0;
    
    static int attribList[] = {
        GLX_RENDER_TYPE,
        GLX_RGBA_BIT,
        GLX_DRAWABLE_TYPE,
        GLX_WINDOW_BIT,
        GLX_DOUBLEBUFFER,
        1,
        GLX_RED_SIZE,
        1,
        GLX_GREEN_SIZE,
        1,
        GLX_BLUE_SIZE,
        1,
        None
    };
    
    int fbcCount = 0;
    GLXFBConfig* fbc = glXChooseFBConfig(dpy, DefaultScreen(dpy), attribList, &fbcCount);
    if (!fbc)
        return 0;
    fbConfig = fbc[0];
    
    XVisualInfo *vi = glXGetVisualFromFBConfig(GLnative.display, fbConfig);
    if (!vi)
        return 0;
    
    GLXContext tmpCtx = glXCreateContext(GLnative.display, vi, 0, GL_TRUE);
    glXCreateContextAttribsARB =
    (PFNGLXCREATECONTEXTATTRIBSARBPROC)glXGetProcAddressARB((const GLubyte*)"glXCreateContextAttribsARB");
    glXDestroyContext(GLnative.display, tmpCtx);
    if (!glXCreateContextAttribsARB)
        return 0;
    
    GLnative.glc = glXCreateContext(GLnative.display, vi, NULL, GL_TRUE);
#if !defined(GL_LEGACY) && defined(GL_VERSION_MAJOR) && defined(GL_VERSION_MINOR)
    int contextAttributes[] = {
        GLX_CONTEXT_MAJOR_VERSION_ARB, GL_VERSION_MAJOR,
        GLX_CONTEXT_MINOR_VERSION_ARB, GL_VERSION_MINOR,
        None
    };
#else
    int contextAttributes[] = {
        GLX_CONTEXT_MAJOR_VERSION_ARB, 1,
        GLX_CONTEXT_MINOR_VERSION_ARB, 0,
        None
    };
#endif
    GLnative.glc = glXCreateContextAttribsARB(GLnative.display, fbConfig, NULL, GL_TRUE, contextAttributes);
    glXMakeCurrent(GLnative.display, GLnative.window, GLnative.glc);
    
    XSetWindowAttributes swa;
    swa.override_redirect = True;
    swa.border_pixel = BlackPixel(GLnative.display, GLnative.screen);
    swa.background_pixel = BlackPixel(GLnative.display, GLnative.screen);
    swa.backing_store = NotUseful;
    if (!(GLnative.window = XCreateWindow(GLnative.display, GLnative.root, x, y, w, h, 0, GLnative.depth, InputOutput, visual, CWBackPixel | CWBorderPixel | CWBackingStore, &swa)))
        return 0;
    GLnative.width = w;
    GLnative.height = h;
    
    GLnative.delete = XInternAtom(GLnative.display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(GLnative.display, GLnative.window, &GLnative.delete, 1);
    
    XSelectInput(GLnative.display, GLnative.window, StructureNotifyMask | KeyPressMask | KeyReleaseMask | PointerMotionMask | ButtonPressMask | ButtonReleaseMask | ExposureMask | FocusChangeMask | EnterWindowMask | LeaveWindowMask);
    XStoreName(GLnative.display, GLnative.window, title);
    
    if (flags & ppFullscreen) {
        Atom p = XInternAtom(GLnative.display, "_NET_WM_STATE_FULLSCREEN", True);
        XChangeProperty(GLnative.display, GLnative.window, XInternAtom(GLnative.display, "_NET_WM_STATE", True), XA_ATOM, 32, PropModeReplace, (unsigned char*)&p, 1);
    }
    if (flags & ppBorderless) {
        struct Hints hints;
        hints.flags = 2;
        hints.decorations = 0;
        Atom p = XInternAtom(GLnative.display, "_MOTIF_WM_HINTS", True);
        XChangeProperty(GLnative.display, GLnative.window, p, p, 32, PropModeReplace, (unsigned char*)&hints, 5);
    }
    
    if (flags & ppAlwaysOnTop) {
        Atom p = XInternAtom(GLnative.display, "_NET_WM_STATE_ABOVE", False);
        XChangeProperty(GLnative.display, GLnative.window, XInternAtom(GLnative.display, "_NET_WM_STATE", False), XA_ATOM, 32, PropModeReplace, (unsigned char *)&p, 1);
    }
    
    XSizeHints hints;
    hints.flags = PPosition | PMinSize | PMaxSize;
    hints.x = 0;
    hints.y = 0;
    if (flags & ppResizable) {
        hints.min_width = 0;
        hints.min_height = 0;
        hints.max_width = screenW;
        hints.max_height = screenH;
    } else {
        hints.min_width = w;
        hints.min_height = h;
        hints.max_width = w;
        hints.max_height = h;
    }
    XSetWMNormalHints(GLnative.display, GLnative.window, &hints);
    XClearWindow(GLnative.display, GLnative.window);
    XMapRaised(GLnative.display, GLnative.window);
    XFlush(GLnative.display);
    GLnative.gc = DefaultGC(GLnative.display, GLnative.screen);
    
    GLwindow.running = 1;
    return 1;
}

static uint8_t ConvertX11Key(KeySym sym) {
    if (sym >= 'a' && sym <= 'z')
        return (uint8_t)sym - ('a' - 'A');
    if (sym >= '0' && sym <= '9')
        return (uint8_t)sym;
    
    switch (sym) {
        case XK_KP_0:
            return KEY_PAD0;
        case XK_KP_1:
            return KEY_PAD1;
        case XK_KP_2:
            return KEY_PAD2;
        case XK_KP_3:
            return KEY_PAD3;
        case XK_KP_4:
            return KEY_PAD4;
        case XK_KP_5:
            return KEY_PAD5;
        case XK_KP_6:
            return KEY_PAD6;
        case XK_KP_7:
            return KEY_PAD7;
        case XK_KP_8:
            return KEY_PAD8;
        case XK_KP_9:
            return KEY_PAD9;
            
        case XK_KP_Multiply:
            return KEY_PADMUL;
        case XK_KP_Divide:
            return KEY_PADDIV;
        case XK_KP_Add:
            return KEY_PADADD;
        case XK_KP_Subtract:
            return KEY_PADSUB;
        case XK_KP_Decimal:
            return KEY_PADDOT;
        case XK_KP_Enter:
            return KEY_PADENTER;
            
        case XK_F1:
            return KEY_F1;
        case XK_F2:
            return KEY_F2;
        case XK_F3:
            return KEY_F3;
        case XK_F4:
            return KEY_F4;
        case XK_F5:
            return KEY_F5;
        case XK_F6:
            return KEY_F6;
        case XK_F7:
            return KEY_F7;
        case XK_F8:
            return KEY_F8;
        case XK_F9:
            return KEY_F9;
        case XK_F10:
            return KEY_F10;
        case XK_F11:
            return KEY_F11;
        case XK_F12:
            return KEY_F12;
            
        case XK_BackSpace:
            return KEY_BACKSPACE;
        case XK_Tab:
            return KEY_TAB;
        case XK_Return:
            return KEY_RETURN;
        case XK_Pause:
            return KEY_PAUSE;
        case XK_Caps_Lock:
            return KEY_CAPSLOCK;
        case XK_Escape:
            return KEY_ESCAPE;
        case XK_space:
            return KEY_SPACE;
            
        case XK_Page_Up:
            return KEY_PAGEUP;
        case XK_Page_Down:
            return KEY_PAGEDN;
        case XK_End:
            return KEY_END;
        case XK_Home:
            return KEY_HOME;
        case XK_Left:
            return KEY_LEFT;
        case XK_Up:
            return KEY_UP;
        case XK_Right:
            return KEY_RIGHT;
        case XK_Down:
            return KEY_DOWN;
        case XK_Insert:
            return KEY_INSERT;
        case XK_Delete:
            return KEY_DELETE;
            
        case XK_Meta_L:
            return KEY_LWIN;
        case XK_Meta_R:
            return KEY_RWIN;
        case XK_Num_Lock:
            return KEY_NUMLOCK;
        case XK_Scroll_Lock:
            return KEY_SCROLL;
        case XK_Shift_L:
            return KEY_LSHIFT;
        case XK_Shift_R:
            return KEY_RSHIFT;
        case XK_Control_L:
            return KEY_LCONTROL;
        case XK_Control_R:
            return KEY_RCONTROL;
        case XK_Alt_L:
            return KEY_LALT;
        case XK_Alt_R:
            return KEY_RALT;
            
        case XK_semicolon:
            return KEY_SEMICOLON;
        case XK_equal:
            return KEY_EQUALS;
        case XK_comma:
            return KEY_COMMA;
        case XK_minus:
            return KEY_MINUS;
        case XK_period:
            return KEY_DOT;
        case XK_slash:
            return KEY_SLASH;
        case XK_grave:
            return KEY_BACKTICK;
        case XK_bracketleft:
            return KEY_LSQUARE;
        case XK_backslash:
            return KEY_BACKSLASH;
        case XK_bracketright:
            return KEY_RSQUARE;
        case XK_apostrophe:
            return KEY_TICK;
    }
    return 0;
}

static int ConvertX11Mod(int state) {
    int mod_keys = 0;
    if (state & ShiftMask)
        mod_keys |= KEY_MOD_SHIFT;
    if (state & ControlMask)
        mod_keys |= KEY_MOD_CONTROL;
    if (state & Mod1Mask)
        mod_keys |= KEY_MOD_ALT;
    if (state & Mod4Mask)
        mod_keys |= KEY_MOD_SUPER;
    if (state & LockMask)
        mod_keys |= KEY_MOD_CAPS_LOCK;
    if (state & Mod2Mask)
        mod_keys |= KEY_MOD_NUM_LOCK;
    return mod_keys;
}

#define Button6 6
#define Button7 7

static int ConvertX11ModEx(int key, int state, int is_pressed) {
    int mod_keys = ConvertX11Mod(state);
    switch (key) {
        case KEY_LSHIFT:
        case KEY_RSHIFT:
            if (is_pressed)
                mod_keys |= KEY_MOD_SHIFT;
            else
                mod_keys &= ~KEY_MOD_SHIFT;
            break;
        case KEY_LCONTROL:
        case KEY_RCONTROL:
            if (is_pressed)
                mod_keys |= KEY_MOD_CONTROL;
            else
                mod_keys &= ~KEY_MOD_CONTROL;
            break;
        case KEY_LALT:
        case KEY_RALT:
            if (is_pressed)
                mod_keys |= KEY_MOD_ALT;
            else
                mod_keys &= ~KEY_MOD_ALT;
            break;
        case KEY_LWIN:
        case KEY_RWIN:
            if (is_pressed)
                mod_keys |= KEY_MOD_SUPER;
            else
                mod_keys &= ~KEY_MOD_SUPER;
            break;
    }
    return mod_keys;
}

int glPollWindow(void) {
    if (!GLwindow.running)
        return 0;
    
    XEvent e;
    while (GLwindow.running && XPending(GLnative.display)) {
        XNextEvent(GLnative.display, &e);
        switch (e.type) {
            case KeyPress:
            case KeyRelease:
                glCallCallback(Keyboard, ConvertX11Key(e.xkey.keycode), ConvertX11ModEx(e.xkey.keycode, e.xkey.state, e.type == KeyPress), e.type == KeyPress);
                break;
            case ButtonPress:
            case ButtonRelease:
                switch (e.xbutton.button) {
                    case Button1:
                    case Button2:
                    case Button3:
                        glCallCallback(MouseButton, (int)e.xbutton.button, ConvertX11Mod(e.xkey.state), e.type == ButtonPress);
                        break;
                    case Button4:
                        glCallCallback(MouseScroll, 0.f, 1.f, ConvertX11Mod(e.xkey.state));
                        break;
                    case Button5:
                        glCallCallback(MouseScroll, 0.f, -1.f, ConvertX11Mod(e.xkey.state));
                        break;
                    case Button6:
                        glCallCallback(MouseScroll, 1.f, 0.f, ConvertX11Mod(e.xkey.state));
                        break;
                    case Button7:
                        glCallCallback(MouseScroll, -1.f, 0.f, ConvertX11Mod(e.xkey.state));
                        break;
                    default:
                        glCallCallback(MouseButton, (int)(e.xbutton.button - 4), ConvertX11Mod(e.xkey.state), e.type == ButtonPress);
                        break;
                }
                break;
            case FocusIn:
            case FocusOut:
                glCallCallback(Focus, e.type == FocusIn);
                break;
            case MotionNotify: {
                int cx = e.xmotion.x;
                int cy = e.xmotion.y;
                glCallCallback(MouseMove, cx, cy, cx - GLnative.cursorLastX, cy - GLnative.cursorLastY);
                GLnative.cursorLastX = cx;
                GLnative.cursorLastY = cy;
                break;
            }
            case ConfigureNotify: {
                int w = e.xconfigure.width;
                int h = e.xconfigure.height;
                if (GLnative.width == w && GLnative.height == h)
                    break;
                glCallCallback(Resized, w, h);
                GLnative.width = w;
                GLnative.height = h;
                XClearWindow(GLnative.display, GLnative.window);
                break;
            }
            case ClientMessage:
                if (e.xclient.data.l[0] != GLnative.delete)
                    break;
                GLwindow.running = 0;
                break;
        }
    }
    return GLwindow.running && glXMakeCurrent(GLnative.display, GLnative.window, GLnative.glc);
}

void glFlushWindow(void) {
    if (!GLwindow.running)
        return;
    glXSwapBuffers(GLnative.display, GLnative.window);
}

void glWindowQuit(void) {
    if (!GLwindow.running)
        return;
    if (GLnative.window)
        XDestroyWindow(GLnative.display, GLnative.window);
    if (GLnative.display)
        XCloseDisplay(GLnative.display);
}

void* glWindowNative(void) {
    return (void*)GLnative.window;
}
