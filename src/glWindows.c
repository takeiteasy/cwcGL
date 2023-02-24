/* glWindows.c -- https://github.com/takeiteasy/glWindow
 
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
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef near
#undef far
#undef wherever_you_are

#if !defined(GL_LEGACY)
#if !defined(GL_VERSION_MAJOR) && !defined(GL_VERSION_MINOR)
#define GL_VERSION_MAJOR 3
#define GL_VERSION_MINOR 2
#endif
#if defined(GL_VERSION_MAJOR)
#if !defined(GL_VERSION_MINOR)
#if GL_VERSION_MAJOR == 3
#define GL_VERSION_MINOR 2
#else
#define GL_VERSION_MINOR 0
#endif
#endif
#endif

#define WGL_DRAW_TO_WINDOW_ARB 0x2001
#define WGL_SUPPORT_OPENGL_ARB 0x2010
#define WGL_DOUBLE_BUFFER_ARB 0x2011
#define WGL_PIXEL_TYPE_ARB 0x2013
#define WGL_COLOR_BITS_ARB 0x2014
#define WGL_DEPTH_BITS_ARB 0x2022
#define WGL_STENCIL_BITS_ARB 0x2023
#define WGL_TYPE_RGBA_ARB 0x202B
#define WGL_CONTEXT_MAJOR_VERSION_ARB 0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB 0x2092

typedef BOOL(WINAPI* PFNWGLCHOOSEPIXELFORMATARBPROC)(HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats, int* piFormats, UINT* nNumFormats);
typedef HGLRC(WINAPI* PFNWGLCREATECONTEXTATTRIBSARBPROC)(HDC hDC, HGLRC hShareContext, const int* attribList);
PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormat;
PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribs;
#endif

#if defined(_MSC_VER)
#pragma comment(lib, "user32")
#pragma comment(lib, "gdi32")
#pragma comment(lib, "opengl32")
#pragma comment(lib, "ntdll")

#if !defined(_DLL)
#include <shellapi.h>
#pragma comment(lib, "shell32")
#include <stdlib.h>

extern int main(int argc, const char *argv[]);

#ifdef UNICODE
int CALLBACK wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
#else
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#endif
{
    int n, argc;
    LPWSTR *wargv = CommandLineToArgvW(GetCommandLineW(), &argc);
    char **argv = calloc(argc + 1, sizeof(int));

    (void)hInstance;
    (void)hPrevInstance;
    (void)lpCmdLine;
    (void)nCmdShow;

    for (n = 0; n < argc; n++) {
        int len = WideCharToMultiByte(CP_UTF8, 0, wargv[n], -1, 0, 0, NULL, NULL);
        argv[n] = malloc(len);
        WideCharToMultiByte(CP_UTF8, 0, wargv[n], -1, argv[n], len, NULL, NULL);
    }
    return main(argc, argv);
}
#endif
#endif

static struct {
    WNDCLASS wnd;
    HWND hwnd;
    HDC hdc;
    HGLRC glContext;
    TRACKMOUSEEVENT tme;
    int tmeRefresh;
    int width, height;
    int cursorLastX, cursorLastY;
    int mouseInWindow;
    long windowFlags;
} GLnative = {0};

static int WindowsModState(void) {
    int mods = 0;
    
    if (GetKeyState(VK_SHIFT) & 0x8000)
        mods |= KEY_MOD_SHIFT;
    if (GetKeyState(VK_CONTROL) & 0x8000)
        mods |= KEY_MOD_CONTROL;
    if (GetKeyState(VK_MENU) & 0x8000)
        mods |= KEY_MOD_ALT;
    if ((GetKeyState(VK_LWIN) | GetKeyState(VK_RWIN)) & 0x8000)
        mods |= KEY_MOD_SUPER;
    if (GetKeyState(VK_CAPITAL) & 1)
        mods |= KEY_MOD_CAPS_LOCK;
    if (GetKeyState(VK_NUMLOCK) & 1)
        mods |= KEY_MOD_NUM_LOCK;
    
    return mods;
}

static int ConvertWindowsKey(int key) {
    if (key >= 'A' && key <= 'Z')
        return key;
    if (key >= '0' && key <= '9')
        return key;
    switch (key) {
        case VK_BACK:
            return KEY_BACKSPACE;
        case VK_TAB:
            return KEY_TAB;
        case VK_RETURN:
            return KEY_RETURN;
        case VK_SHIFT:
            return KEY_SHIFT;
        case VK_CONTROL:
            return KEY_CONTROL;
        case VK_MENU:
            return KEY_ALT;
        case VK_PAUSE:
            return KEY_PAUSE;
        case VK_CAPITAL:
            return KEY_CAPSLOCK;
        case VK_ESCAPE:
            return KEY_ESCAPE;
        case VK_SPACE:
            return KEY_SPACE;
        case VK_PRIOR:
            return KEY_PAGEUP;
        case VK_NEXT:
            return KEY_PAGEDN;
        case VK_END:
            return KEY_END;
        case VK_HOME:
            return KEY_HOME;
        case VK_LEFT:
            return KEY_LEFT;
        case VK_UP:
            return KEY_UP;
        case VK_RIGHT:
            return KEY_RIGHT;
        case VK_DOWN:
            return KEY_DOWN;
        case VK_INSERT:
            return KEY_INSERT;
        case VK_DELETE:
            return KEY_DELETE;
        case VK_LWIN:
            return KEY_LWIN;
        case VK_RWIN:
            return KEY_RWIN;
        case VK_NUMPAD0:
            return KEY_PAD0;
        case VK_NUMPAD1:
            return KEY_PAD1;
        case VK_NUMPAD2:
            return KEY_PAD2;
        case VK_NUMPAD3:
            return KEY_PAD3;
        case VK_NUMPAD4:
            return KEY_PAD4;
        case VK_NUMPAD5:
            return KEY_PAD5;
        case VK_NUMPAD6:
            return KEY_PAD6;
        case VK_NUMPAD7:
            return KEY_PAD7;
        case VK_NUMPAD8:
            return KEY_PAD8;
        case VK_NUMPAD9:
            return KEY_PAD9;
        case VK_MULTIPLY:
            return KEY_PADMUL;
        case VK_ADD:
            return KEY_PADADD;
        case VK_SEPARATOR:
            return KEY_PADENTER;
        case VK_SUBTRACT:
            return KEY_PADSUB;
        case VK_DECIMAL:
            return KEY_PADDOT;
        case VK_DIVIDE:
            return KEY_PADDIV;
        case VK_F1:
            return KEY_F1;
        case VK_F2:
            return KEY_F2;
        case VK_F3:
            return KEY_F3;
        case VK_F4:
            return KEY_F4;
        case VK_F5:
            return KEY_F5;
        case VK_F6:
            return KEY_F6;
        case VK_F7:
            return KEY_F7;
        case VK_F8:
            return KEY_F8;
        case VK_F9:
            return KEY_F9;
        case VK_F10:
            return KEY_F10;
        case VK_F11:
            return KEY_F11;
        case VK_F12:
            return KEY_F12;
        case VK_NUMLOCK:
            return KEY_NUMLOCK;
        case VK_SCROLL:
            return KEY_SCROLL;
        case VK_LSHIFT:
            return KEY_LSHIFT;
        case VK_RSHIFT:
            return KEY_RSHIFT;
        case VK_LCONTROL:
            return KEY_LCONTROL;
        case VK_RCONTROL:
            return KEY_RCONTROL;
        case VK_LMENU:
            return KEY_LALT;
        case VK_RMENU:
            return KEY_RALT;
        case VK_OEM_1:
            return KEY_SEMICOLON;
        case VK_OEM_PLUS:
            return KEY_EQUALS;
        case VK_OEM_COMMA:
            return KEY_COMMA;
        case VK_OEM_MINUS:
            return KEY_MINUS;
        case VK_OEM_PERIOD:
            return KEY_DOT;
        case VK_OEM_2:
            return KEY_SLASH;
        case VK_OEM_3:
            return KEY_BACKTICK;
        case VK_OEM_4:
            return KEY_LSQUARE;
        case VK_OEM_5:
            return KEY_BACKSLASH;
        case VK_OEM_6:
            return KEY_RSQUARE;
        case VK_OEM_7:
            return KEY_TICK;
    }
    return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    if (!GLwindow.running)
        goto DEFAULT_PROC;
    
    switch(message) {
        case WM_PAINT:
            SwapBuffers(GLnative.hdc);
            ValidateRect(hWnd, NULL);
            break;
        case WM_DESTROY:
        case WM_CLOSE:
            if (GLwindow.ClosedCallback)
                GLwindow.ClosedCallback(GLwindow.userdata);
            GLwindow.running = 0;
            break;
        case WM_SIZE:
            GLnative.width = LOWORD(lParam);
            GLnative.height = HIWORD(lParam);
            glCallCallback(Resized, GLnative.width, GLnative.height);
            break;
        case WM_MENUCHAR:
            // Disable beep on Alt+Enter
            if (LOWORD(wParam) == VK_RETURN)
                return MNC_CLOSE << 16;
            return DefWindowProcW(hWnd, message, wParam, lParam);
        case WM_KEYDOWN:
        case WM_SYSKEYDOWN:
        case WM_KEYUP:
        case WM_SYSKEYUP:
            glCallCallback(Keyboard, ConvertWindowsKey(wParam), WindowsModState(), !((lParam >> 31) & 1));
            break;
        case WM_LBUTTONUP:
        case WM_RBUTTONUP:
        case WM_MBUTTONUP:
        case WM_XBUTTONUP:
        case WM_LBUTTONDOWN:
        case WM_LBUTTONDBLCLK:
        case WM_RBUTTONDOWN:
        case WM_RBUTTONDBLCLK:
        case WM_MBUTTONDOWN:
        case WM_MBUTTONDBLCLK:
        case WM_XBUTTONDOWN:
        case WM_XBUTTONDBLCLK: {
            int button = 0;
            int action = 0;
            switch (message) {
                case WM_LBUTTONDOWN:
                    action = 1;
                case WM_LBUTTONUP:
                    button = 1;
                    break;
                case WM_RBUTTONDOWN:
                    action = 1;
                case WM_RBUTTONUP:
                    button = 2;
                    break;
                case WM_MBUTTONDOWN:
                    action = 1;
                case WM_MBUTTONUP:
                    button = 3;
                    break;
                default:
                    button = (GET_XBUTTON_WPARAM(wParam) == XBUTTON1 ? 5 : 6);
                    if (message == WM_XBUTTONDOWN)
                        action = 1;
            }
            glCallCallback(MouseButton, button, WindowsModState(), action);
            break;
        }
        case WM_MOUSEWHEEL:
            glCallCallback(MouseScroll, 0.f, (SHORT)HIWORD(wParam) / (float)WHEEL_DELTA, WindowsModState());
            break;
        case WM_MOUSEHWHEEL:
            glCallCallback(MouseScroll, -((SHORT)HIWORD(wParam) / (float)WHEEL_DELTA), 0., WindowsModState());
            break;
        case WM_MOUSEMOVE: {
            if (GLnative.tmeRefresh) {
                GLnative.tme.cbSize = sizeof(GLnative.tme);
                GLnative.tme.hwndTrack = GLnative.hwnd;
                GLnative.tme.dwFlags = TME_HOVER | TME_LEAVE;
                GLnative.tme.dwHoverTime = 1;
                TrackMouseEvent(&GLnative.tme);
            }
            int cx = ((int)(short)LOWORD(lParam));
            int cy = ((int)(short)HIWORD(lParam));
            glCallCallback(MouseMove, cx, cy, cx - GLnative.cursorLastX, cy - GLnative.cursorLastY);
            GLnative.cursorLastX = cx;
            GLnative.cursorLastY = cy;
            break;
        }
        case WM_MOUSEHOVER:
            GLnative.mouseInWindow = 1;
            GLnative.tmeRefresh = 1;
            break;
        case WM_MOUSELEAVE:
            GLnative.tmeRefresh = 0;
            break;
        case WM_SETFOCUS:
            glCallCallback(Focus, 1);
            break;
        case WM_KILLFOCUS:
            glCallCallback(Focus, 0);
            break;
        default:
            goto DEFAULT_PROC;
    }

    return FALSE;
DEFAULT_PROC:
    return DefWindowProc(hWnd, message, wParam, lParam);
}

int glWindow(unsigned int w, unsigned int h, const char *title, GLflags flags) {
    if (GLwindow.running)
        return 0;

    RECT rect = {0};
    GLnative.windowFlags = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;
    if (flags & glFullscreen) {
        flags = glFullscreen;
        rect.right = GetSystemMetrics(SM_CXSCREEN);
        rect.bottom = GetSystemMetrics(SM_CYSCREEN);
        GLnative.windowFlags = WS_POPUP & ~(WS_CAPTION | WS_THICKFRAME | WS_MINIMIZE | WS_MAXIMIZE | WS_SYSMENU);

        DEVMODE settings = {0};
        EnumDisplaySettings(0, 0, &settings);
        settings.dmPelsWidth = GetSystemMetrics(SM_CXSCREEN);
        settings.dmPelsHeight = GetSystemMetrics(SM_CYSCREEN);
        settings.dmBitsPerPel = 32;
        settings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

        if (ChangeDisplaySettings(&settings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
            flags = glFullscreenDesktop;
    }

    if (flags & glBorderless)
        GLnative.windowFlags = WS_POPUP;
    if (flags & glResizable)
        GLnative.windowFlags |= WS_MAXIMIZEBOX | WS_SIZEBOX;
    if (flags & glFullscreenDesktop) {
        GLnative.windowFlags = WS_OVERLAPPEDWINDOW;

        int width = GetSystemMetrics(SM_CXFULLSCREEN);
        int height = GetSystemMetrics(SM_CYFULLSCREEN);

        rect.right = width;
        rect.bottom = height;
        AdjustWindowRect(&rect, GLnative.windowFlags, 0);
        if (rect.left < 0) {
            width += rect.left * 2;
            rect.right += rect.left;
            rect.left = 0;
        }
        if (rect.bottom > (LONG)height) {
            height -= (rect.bottom - height);
            rect.bottom += (rect.bottom - height);
            rect.top = 0;
        }
    } else {
        rect.right = w;
        rect.bottom = h;

        AdjustWindowRect(&rect, GLnative.windowFlags, 0);

        rect.right -= rect.left;
        rect.bottom -= rect.top;

        rect.left = (GetSystemMetrics(SM_CXSCREEN) - rect.right) / 2;
        rect.top = (GetSystemMetrics(SM_CYSCREEN) - rect.bottom + rect.top) / 2;
    }

    memset(&GLnative.wnd, 0, sizeof(GLnative.wnd));
    GLnative.wnd.style = CS_OWNDC | CS_VREDRAW | CS_HREDRAW;
    GLnative.wnd.lpfnWndProc = WndProc;
    GLnative.wnd.hCursor = LoadCursor(0, IDC_ARROW);
    GLnative.wnd.lpszClassName = title;
    if (!RegisterClass(&GLnative.wnd))
        return 0;
    
    GLnative.width = rect.right;
    GLnative.height = rect.bottom;
    if (!(GLnative.hwnd = CreateWindowEx(0, title, title, GLnative.windowFlags, rect.left, rect.top, rect.right, rect.bottom, 0, 0, 0, 0)))
        return 0;
    if (!(GLnative.hdc = GetDC(GLnative.hwnd)))
        return 0;

    if (flags & glAlwaysOnTop)
        SetWindowPos(GLnative.hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

    ShowWindow(GLnative.hwnd, SW_NORMAL);
    SetFocus(GLnative.hwnd);

    GLnative.tme.cbSize = sizeof(GLnative.tme);
    GLnative.tme.hwndTrack = GLnative.hwnd;
    GLnative.tme.dwFlags = TME_HOVER | TME_LEAVE;
    GLnative.tme.dwHoverTime = HOVER_DEFAULT;
    TrackMouseEvent(&GLnative.tme);

    PIXELFORMATDESCRIPTOR pfd;
    ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;

    int pf = ChoosePixelFormat(GLnative.hdc, &pfd);
    if (!pf)
        return 0;
    if (!SetPixelFormat(GLnative.hdc, pf, &pfd))
        return 0;
    DescribePixelFormat(GLnative.hdc, pf, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
    if (!(GLnative.glContext = wglCreateContext(GLnative.hdc)))
        return 0;
    if (!wglMakeCurrent(GLnative.hdc, GLnative.glContext))
        return 0;

#if !defined(GL_LEGACY) && defined(GL_VERSION_MAJOR) && defined(GL_VERSION_MINOR)
    wglChoosePixelFormat = (PFNWGLCHOOSEPIXELFORMATARBPROC)wglGetProcAddress("wglChoosePixelFormatARB");
    wglCreateContextAttribs = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB");
    
    int wglAttrib[] = {
        WGL_DRAW_TO_WINDOW_ARB, 1,
        WGL_SUPPORT_OPENGL_ARB, 1,
        WGL_DOUBLE_BUFFER_ARB, 1,
        WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
        WGL_COLOR_BITS_ARB, 32,
        WGL_DEPTH_BITS_ARB, 24,
        WGL_STENCIL_BITS_ARB, 8,
        0
    };
    int wglVersionAttrib[] = {
        WGL_CONTEXT_MAJOR_VERSION_ARB, GL_VERSION_MAJOR,
        WGL_CONTEXT_MINOR_VERSION_ARB, GL_VERSION_MINOR,
        0
    };
    UINT numFormats;
    
    if (!wglChoosePixelFormat || !wglCreateContextAttribs)
        goto SKIP;
    if (!wglChoosePixelFormat(GLnative.hdc, wglAttrib, NULL, 1, &pf, &numFormats))
        return 0;
    if (!(GLnative.glContext = wglCreateContextAttribs(GLnative.hdc, GLnative.glContext, wglVersionAttrib)))
        return 0;
    if (!wglMakeCurrent(GLnative.hdc, GLnative.glContext))
        return 0;
SKIP:
#endif

    QueryPerformanceCounter(&GLnative.timestamp);
    GLwindow.running = 1;
    return 1;
}

int glPollWindow(void) {
    if (!GLwindow.running)
        return 0;
        
    static MSG msg;
    if (PeekMessage(&msg, GLnative.hwnd, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return GLwindow.running;
}

void glFlushWindow(void) {
    if (!GLwindow.running)
        return;
    InvalidateRect(GLnative.hwnd, NULL, TRUE);
    SendMessage(GLnative.hwnd, WM_PAINT, 0, 0);
}

void glWindowQuit(void) {
    if (!GLwindow.running)
        return;
    wglMakeCurrent(GLnative.hdc, NULL);
    wglDeleteContext(GLnative.glContext);
    ReleaseDC(GLnative.hwnd, GLnative.hdc);
    DestroyWindow(GLnative.hwnd);
}

void* glWindowNative(void) {
    return (void*)GLnative.hwnd;
}
