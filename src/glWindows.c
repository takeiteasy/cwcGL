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


#if defined(GL_VERSION_MAJOR)
#if !defined(GL_VERSION_MINOR)
#define GL_VERSION_MINOR 0
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
#else
#define GL_LEGACY
#endif

#if defined(_MSC_VER)
#pragma comment(lib, "shell32")
#pragma comment(lib, "user32")
#pragma comment(lib, "gdi32")
#pragma comment(lib, "opengl32")

#if !defined(_DLL)
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
    LARGE_INTEGER timestamp;
} GLnative = {0};

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
    long windowFlags = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;
    if (flags & glFullscreen) {
        flags = glFullscreen;
        rect.right = GetSystemMetrics(SM_CXSCREEN);
        rect.bottom = GetSystemMetrics(SM_CYSCREEN);
        windowFlags = WS_POPUP & ~(WS_CAPTION | WS_THICKFRAME | WS_MINIMIZE | WS_MAXIMIZE | WS_SYSMENU);

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
        windowFlags = WS_POPUP;
    if (flags & glResizable)
        windowFlags |= WS_MAXIMIZEBOX | WS_SIZEBOX;
    if (flags & glFullscreenDesktop) {
        windowFlags = WS_OVERLAPPEDWINDOW;

        int width = GetSystemMetrics(SM_CXFULLSCREEN);
        int height = GetSystemMetrics(SM_CYFULLSCREEN);

        rect.right = width;
        rect.bottom = height;
        AdjustWindowRect(&rect, windowFlags, 0);
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

        AdjustWindowRect(&rect, windowFlags, 0);

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
    if (!(GLnative.hwnd = CreateWindowEx(0, title, title, windowFlags, rect.left, rect.top, rect.right, rect.bottom, 0, 0, 0, 0)))
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

#if !defined(GL_LEGACY)
    if (!(wglChoosePixelFormat = (PFNWGLCHOOSEPIXELFORMATARBPROC)wglGetProcAddress("wglChoosePixelFormatARB")))
        return 0;
    if (!(wglCreateContextAttribs = (PFNWGLCREATECONTEXTATTRIBSARBPROC)wglGetProcAddress("wglCreateContextAttribsARB")))
        return 0;

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
    if (!wglChoosePixelFormat(GLnative.hdc, wglAttrib, NULL, 1, &pf, &numFormats))
        return 0;
    if (!(GLnative.glContext = wglCreateContextAttribs(GLnative.hdc, GLnative.glContext, wglVersionAttrib)))
        return 0;
    if (!wglMakeCurrent(GLnative.hdc, GLnative.glContext))
        return 0;
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

double glGetTime(void) {
    LARGE_INTEGER cnt, freq;
    QueryPerformanceCounter(&cnt);
    QueryPerformanceFrequency(&freq);
    ULONGLONG diff = cnt.QuadPart - GLnative.timestamp.QuadPart;
    GLnative.timestamp = cnt;
    return (double)(diff / (double)freq.QuadPart);
}
