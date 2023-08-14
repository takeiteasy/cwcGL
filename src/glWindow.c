/* glWindow.c -- https://github.com/takeiteasy/fungl

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

#include "glWindow.h"

static struct {
#define X(NAME, ARGS) void(*NAME##Callback)ARGS;
    GLW_CALLBACKS
#undef X
    int running;
    void *userdata;
} GLwindow = {0};

#define glCallCallback(CB, ...)  \
    if (GLwindow.CB##Callback)   \
        GLwindow.CB##Callback(GLwindow.userdata, __VA_ARGS__)

#define X(NAME, ARGS) \
    void(*NAME##Callback)ARGS,
void glWindowCallbacks(GLW_CALLBACKS void* userdata) {
#undef X
#define X(NAME, ARGS) \
    GLwindow.NAME##Callback = NAME##Callback;
    GLW_CALLBACKS
#undef X
    GLwindow.userdata = userdata;
}

#define X(NAME, ARGS)                                          \
    void glWindow##NAME##Callback(void(*NAME##Callback)ARGS) { \
        GLwindow.NAME##Callback = NAME##Callback;              \
    }
GLW_CALLBACKS
#undef X

void glWindowUserdata(void *userdata) {
    GLwindow.userdata = userdata;
}

int glIsWindowOpen(void) {
    return GLwindow.running;
}

#if defined(GLW_EMSCRIPTEN)
#include <emscripten/html5_webgl.h>

#define canvas "#canvas"

static struct {
    int screenW, screenH;
    int canvasW, canvasH;
    int mouseInCanvas;
    EMSCRIPTEN_WEBGL_CONTEXT_HANDLE webgl;
} GLnative = {0};

static GLmod TranslateWebMod(int ctrl, int shift, int alt, int meta) {
    return ((ctrl ? KEY_MOD_CONTROL : 0) | (shift ? KEY_MOD_SHIFT : 0) | (alt ? KEY_MOD_ALT : 0) | (meta ? KEY_MOD_SUPER : 0));
}

static EM_BOOL key_callback(int type, const EmscriptenKeyboardEvent* e, void* user_data) {
    GLmod mod = TranslateWebMod(e->ctrlKey, e->shiftKey, e->altKey, e->metaKey);
    glCallCallback(Keyboard, e->keyCode, mod, type == EMSCRIPTEN_EVENT_KEYDOWN);
    return e->keyCode == 82 && mod == KEY_MOD_SUPER ? 0 : 1;
}

static EM_BOOL mouse_callback(int type, const EmscriptenMouseEvent* e, void* user_data) {
    switch (type) {
        case EMSCRIPTEN_EVENT_MOUSEDOWN:
            if (GLnative.mouseInCanvas && e->buttons != 0)
                glCallCallback(MouseButton, e->button + 1, TranslateWebMod(e->ctrlKey, e->shiftKey, e->altKey, e->metaKey), 1);
            break;
        case EMSCRIPTEN_EVENT_MOUSEUP:
            if (GLnative.mouseInCanvas)
                glCallCallback(MouseButton, e->button + 1, TranslateWebMod(e->ctrlKey, e->shiftKey, e->altKey, e->metaKey), 0);
            break;
        case EMSCRIPTEN_EVENT_MOUSEMOVE:
            if (GLnative.mouseInCanvas)
                glCallCallback(MouseMove, e->clientX - (GLnative.screenW / 2) + (GLnative.canvasW / 2), e->clientY, e->movementX, e->movementY);
            break;
        case EMSCRIPTEN_EVENT_MOUSEENTER:
            GLnative.mouseInCanvas = 1;
            return 1;
        case EMSCRIPTEN_EVENT_MOUSELEAVE:
            GLnative.mouseInCanvas = 0;
            return 0;
        case EMSCRIPTEN_EVENT_CLICK:
        case EMSCRIPTEN_EVENT_DBLCLICK:
        default:
            return 0;
    }
    return 1;
}

static EM_BOOL wheel_callback(int type, const EmscriptenWheelEvent* e, void* user_data) {
    glCallCallback(MouseScroll, e->deltaX, e->deltaY, TranslateWebMod(e->mouse.ctrlKey, e->mouse.shiftKey, e->mouse.altKey, e->mouse.metaKey));
    return 1;
}

static EM_BOOL uievent_callback(int type, const EmscriptenUiEvent* e, void* user_data) {
    GLnative.screenW = e->documentBodyClientWidth;
    GLnative.screenH = e->documentBodyClientHeight;
    emscripten_get_element_css_size(canvas, (double*)&GLnative.canvasW, (double*)&GLnative.canvasH);
    glCallCallback(Resized, GLnative.screenW, GLnative.screenH);
    return 1;
}

static EM_BOOL focusevent_callback(int type, const EmscriptenFocusEvent* e, void* user_data) {
    glCallCallback(Focus, type == EMSCRIPTEN_EVENT_FOCUS);
    return 1;
}

static const char* beforeunload_callback(int eventType, const void *reserved, void *userData) {
    return "Do you really want to leave the page?";
}

int glWindow(unsigned int w, unsigned int h, const char *title, GLflags flags) {
    if (GLwindow.running)
        return 0;

    emscripten_set_canvas_element_size(canvas, w, h);

    emscripten_set_keypress_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, 0, 1, key_callback);
    emscripten_set_keydown_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, 0, 1, key_callback);
    emscripten_set_keyup_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, 0, 1, key_callback);

    emscripten_set_click_callback(canvas, 0, 1, mouse_callback);
    emscripten_set_mousedown_callback(canvas, 0, 1, mouse_callback);
    emscripten_set_mouseup_callback(canvas, 0, 1, mouse_callback);
    emscripten_set_dblclick_callback(canvas, 0, 1, mouse_callback);
    emscripten_set_mousemove_callback(canvas, 0, 1, mouse_callback);
    emscripten_set_mouseenter_callback(canvas, 0, 1, mouse_callback);
    emscripten_set_mouseleave_callback(canvas, 0, 1, mouse_callback);
    emscripten_set_mouseover_callback(canvas, 0, 1, mouse_callback);
    emscripten_set_mouseout_callback(canvas, 0, 1, mouse_callback);

    emscripten_set_wheel_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, 0, 1, wheel_callback);

    emscripten_set_resize_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, 0, 1, uievent_callback);
    emscripten_set_scroll_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, 0, 1, uievent_callback);

    emscripten_set_blur_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, 0, 1, focusevent_callback);
    emscripten_set_focus_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, 0, 1, focusevent_callback);
    emscripten_set_focusin_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, 0, 1, focusevent_callback);
    emscripten_set_focusout_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, 0, 1, focusevent_callback);

    EmscriptenWebGLContextAttributes attribs;
    emscripten_webgl_init_context_attributes(&attribs);
    attribs.majorVersion = GL_VERSION_MAJOR;
    GLnative.webgl = emscripten_webgl_create_context(canvas, &attribs);

    GLwindow.running = emscripten_webgl_make_context_current(GLnative.webgl) == EMSCRIPTEN_RESULT_SUCCESS;
    return GLwindow.running;
}

int glPollWindow(void) {
    // ...
}

void glFlushWindow(void) {
    // ...
}

void glWindowQuit(void) {
    if (!GLwindow.running)
        return;
    emscripten_cancel_main_loop();
    emscripten_webgl_destroy_context(GLnative.webgl);
    GLwindow.running = 0;
}

void* glWindowNative(void) {
    return NULL;
}
#elif defined(GLW_MAC)
#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <math.h>
#include <objc/objc.h>
#include <objc/runtime.h>
#include <objc/message.h>
#include <objc/NSObjCRuntime.h>
#include <mach/mach_time.h>

// maybe this is available somewhere in objc runtime?
#if __LP64__ || (TARGET_OS_EMBEDDED && !TARGET_OS_IPHONE) || TARGET_OS_WIN32 || NS_BUILD_32_LIKE_64
#define NSIntegerEncoding "q"
#define NSUIntegerEncoding "L"
#else
#define NSIntegerEncoding "i"
#define NSUIntegerEncoding "I"
#endif

#ifdef __OBJC__
#import <Cocoa/Cocoa.h>
#else
// this is how they are defined originally
#include <CoreGraphics/CGBase.h>
#include <CoreGraphics/CGGeometry.h>
#include <CoreGraphics/CoreGraphics.h>

typedef CGPoint NSPoint;
typedef CGSize NSSize;
typedef CGRect NSRect;

extern id const NSApp;
extern id const NSDefaultRunLoopMode;

typedef enum {
    NSWindowStyleMaskBorderless          = 0,
    NSWindowStyleMaskTitled              = 1 << 0,
    NSWindowStyleMaskClosable            = 1 << 1,
    NSWindowStyleMaskMiniaturizable      = 1 << 2,
    NSWindowStyleMaskResizable           = 1 << 3,
    NSWindowStyleMaskFullScreen          = 1 << 14,
    NSWindowStyleMaskFullSizeContentView = 1 << 15,
} NSWindowStyleMask;

typedef enum {
    NSWindowCloseButton,
    NSWindowMiniaturizeButton,
    NSWindowZoomButton
} NSWindowButton;

typedef enum {
    NSEventTypeLeftMouseDown      = 1,
    NSEventTypeLeftMouseUp        = 2,
    NSEventTypeRightMouseDown     = 3,
    NSEventTypeRightMouseUp       = 4,
    NSEventTypeMouseMoved         = 5,
    NSEventTypeLeftMouseDragged   = 6,
    NSEventTypeRightMouseDragged  = 7,
    NSEventTypeMouseEntered       = 8,
    NSEventTypeMouseExited        = 9,
    NSEventTypeKeyDown            = 10,
    NSEventTypeKeyUp              = 11,
    NSEventTypeFlagsChanged       = 12,
    NSEventTypeCursorUpdate       = 17,
    NSEventTypeScrollWheel        = 22,
    NSEventTypeOtherMouseDown     = 25,
    NSEventTypeOtherMouseUp       = 26,
    NSEventTypeOtherMouseDraggedd = 27
} NSEventType;

typedef enum {
    NSEventModifierFlagCapsLock = 1 << 16,
    NSEventModifierFlagShift    = 1 << 17,
    NSEventModifierFlagControl  = 1 << 18,
    NSEventModifierFlagOption   = 1 << 19,
    NSEventModifierFlagCommand  = 1 << 20
} NSEventModifierFlags;

typedef enum {
    NSTrackingMouseEnteredAndExited = 0x01,
    NSTrackingActiveInKeyWindow     = 0x20,
    NSTrackingInVisibleRect         = 0x200
} NSTrackingAreaOptions;

typedef enum {
    NSOpenGLPFANoRecovery = 72,
    NSOpenGLPFAAccelerated = 73,
    NSOpenGLPFADoubleBuffer = 5,
    NSOpenGLPFAAlphaSize = 11,
    NSOpenGLPFAColorSize = 8,
    NSOpenGLPFAOpenGLProfile = 99
} NSOpenGLPixelFormatAttribute;

typedef id NSColorSpaceName;
extern id NSDeviceRGBColorSpace;
#define NSBitmapFormatAlphaNonpremultiplied 1 << 1

#define NSOpenGLProfileVersion3_2Core 0x3200
#define NSBackingStoreBuffered 2
#define NSFloatingWindowLevel 5
#define NSWindowCollectionBehaviorFullScreenPrimary 1 << 7
#define NSApplicationActivationPolicyRegular 0
#endif

// ABI is a bit different between platforms
#ifdef __arm64__
#define abi_objc_msgSend_stret objc_msgSend
#else
#define abi_objc_msgSend_stret objc_msgSend_stret
#endif
#ifdef __i386__
#define abi_objc_msgSend_fpret objc_msgSend_fpret
#else
#define abi_objc_msgSend_fpret objc_msgSend
#endif

#define __STRINGIFY(s) #s

#define sel(NAME) sel_registerName(__STRINGIFY(NAME))
#define class(NAME) ((id)objc_getClass(__STRINGIFY(NAME)))
#define protocol(NAME) objc_getProtocol(__STRINGIFY(NAME))

#define ObjC_Super(RET, ...) ((RET(*)(struct objc_super*, SEL, ##__VA_ARGS__))objc_msgSendSuper)
#define ObjC_Set(OBJ, VAR, VAL) object_setInstanceVariable(OBJ, __STRINGIFY(VAR), (void*)VAL)
#define ObjC_Get(OBJ, VAR, OUT) object_getInstanceVariable(self, __STRINGIFY(VAR), (void**)&OUT)
#define ObjC_SelfSet(VAR, VAL) ObjC_Set(self, VAR, VAL)
#define ObjC_SelfGet(VAR, OUT) ObjC_Get(self, VAR, OUT)
#define ObjC(RET, ...) ((RET(*)(id, SEL, ##__VA_ARGS__))objc_msgSend)
// ObjC functions that return regular structs (e.g. NSRect) must use this
#define ObjC_Struct(RET, ...) ((RET(*)(id, SEL, ##__VA_ARGS__))abi_objc_msgSend_stret)

#define ObjC_Class(NAME, SUPER) \
    objc_allocateClassPair((Class)objc_getClass(__STRINGIFY(SUPER)), __STRINGIFY(NAME), 0)
#define ObjC_AddMethod(CLASS, SEL, IMPL, SIGNATURE)                  \
    if (!class_addMethod(CLASS, sel(SEL), (IMP)(IMPL), (SIGNATURE))) \
        assert(NO)
#define ObjC_AddIVar(CLASS, NAME, SIZE, SIGNATURE)                                   \
    if (!class_addIvar(CLASS, __STRINGIFY(NAME), SIZE, rint(log2(SIZE)), SIGNATURE)) \
        assert(NO)
#define ObjC_AddProtocol(CLASS, PROTOCOL)                           \
    if (!class_addProtocol(CLASS, protocol(__STRINGIFY(PROTOCOL)))) \
        assert(NO);
#define ObjC_SubClass(NAME) objc_registerClassPair(NAME)

#if defined(__OBJC__) && __has_feature(objc_arc) && !defined(OBJC_NO_ARC)
#define OBJC_ARC_AVAILABLE
#endif

#if defined(OBJC_ARC_AVAILABLE)
#define ObjC_Autorelease(CLASS)
#define AutoreleasePool(...) \
    do                       \
    {                        \
        @autoreleasepool     \
        {                    \
            __VA_ARGS__      \
        }                    \
    } while (0)
#else
#define ObjC_Autorelease(CLASS) ObjC(void)(class(CLASS), sel(autorelease))
#define AutoreleasePool(...)                                \
    do                                                      \
    {                                                       \
        id __OBJC_POOL = ObjC_Initalize(NSAutoreleasePool); \
        __VA_ARGS__                                         \
        ObjC(void)(__OBJC_POOL, sel(drain));                \
    } while (0)
#endif
#define ObjC_Alloc(CLASS) ObjC(id)(class(CLASS), sel(alloc))
#define ObjC_Init(CLASS) ObjC(id)(CLASS, sel(init))
#define ObjC_Initalize(CLASS) ObjC(id)(ObjC_Alloc(CLASS), sel(init))
#define ObjC_Release(CLASS) ObjC(void)(CLASS, sel(release))

static struct {
    id window, glContext;
    int cursorInWindow;
} GLnative = {0};

static NSUInteger applicationShouldTerminate(id self, SEL _sel, id sender) {
    glWindowQuit();
    ObjC(void, id)(NSApp, sel(terminate:), nil);
    return 0;
}

static void windowWillClose(id self, SEL _sel, id notification) {
    if (GLwindow.ClosedCallback)
        GLwindow.ClosedCallback(GLwindow.userdata);
    GLwindow.running = 0;
}

static BOOL windowShouldClose(id self, SEL _sel, id sender) {
    ObjC(void, id)(NSApp, sel(terminate:), nil);
    return 1;
}

static void windowDidResize(id self, SEL _sel, id notification) {
    CGRect frame = ObjC(CGRect)(ObjC(id)(GLnative.window, sel(contentView)), sel(frame));
    glCallCallback(Resized, frame.size.width, frame.size.height);
}

static void mouseEntered(id self, SEL _sel, id event) {
    GLnative.cursorInWindow = YES;
}

static void mouseExited(id self, SEL _sel, id event) {
    GLnative.cursorInWindow = NO;
    ObjC(void)(class(NSCursor), sel(unhide));
}

static id CreateNSString(const char *str) {
    return ObjC(id, const char*)(class(NSString), sel(stringWithUTF8String:), str);
}

int glWindow(unsigned int w, unsigned int h, const char *title, GLflags flags) {
    if (GLwindow.running)
        return 0;

    AutoreleasePool({
        ObjC(id)(class(NSApplication), sel(sharedApplication));
        ObjC(void, NSInteger)(NSApp, sel(setActivationPolicy:), NSApplicationActivationPolicyRegular);

        Class AppDelegate = ObjC_Class(AppDelegate, NSObject);
        ObjC_AddMethod(AppDelegate, applicationShouldTerminate, applicationShouldTerminate, NSUIntegerEncoding "@:@:");
        id appDelegate = ObjC(id)(ObjC(id)((id)AppDelegate, sel(alloc)), sel(init));

        ObjC(void, id)(NSApp, sel(setDelegate:), appDelegate);
        ObjC(void)(NSApp, sel(finishLaunching));

        id menuBar = ObjC_Initalize(NSMenu);
        id menuItem = ObjC_Initalize(NSMenuItem);
        ObjC(void, id)(menuBar, sel(addItem:), menuItem);
        ObjC(id, id)(NSApp, sel(setMainMenu:), menuBar);
        id procInfo = ObjC(id)(class(NSProcessInfo), sel(processInfo));
        id appName = ObjC(id)(procInfo, sel(processName));

        id appMenu = ObjC(id, id)(ObjC_Alloc(NSMenu), sel(initWithTitle:), appName);
        id quitTitle = ObjC(id, id)(CreateNSString("Quit "), sel(stringByAppendingString:), appName);
        id quitItem = ObjC(id, id, SEL, id)(ObjC_Alloc(NSMenuItem), sel(initWithTitle:action:keyEquivalent:), quitTitle, sel(terminate:), CreateNSString("q"));

        ObjC(void, id)(appMenu, sel(addItem:), quitItem);
        ObjC(void, id)(menuItem, sel(setSubmenu:), appMenu);

        NSWindowStyleMask styleMask = NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskMiniaturizable;
#if MAC_OS_X_VERSION_MAX_ALLOWED < MAC_OS_X_VERSION_10_7
        if (flags & glFullscreen)
            flags &= (~glFullscreen | glFullscreenDesktop);
#endif
        flags |= (flags & glFullscreen ? (glBorderless | glResizable | glFullscreenDesktop) : 0);
        styleMask |= (flags & glResizable ? NSWindowStyleMaskResizable : 0);
        styleMask |= (flags & glBorderless ? NSWindowStyleMaskFullSizeContentView : 0);

        if (flags & glFullscreenDesktop) {
            NSRect f = ObjC_Struct(NSRect)(ObjC(id)(class(NSScreen), sel(mainScreen)), sel(frame));
            w = f.size.width;
            h = f.size.height;
            styleMask |= NSWindowStyleMaskFullSizeContentView;
        }
        NSRect windowFrame = {{0, 0}, {w, h}};

        GLnative.window = ObjC(id, NSRect, NSUInteger, NSUInteger, BOOL)(ObjC_Alloc(NSWindow), sel(initWithContentRect:styleMask:backing:defer:), windowFrame, styleMask, NSBackingStoreBuffered, NO);
        ObjC(void, BOOL)(GLnative.window, sel(setReleasedWhenClosed:), NO);

        if (flags & glAlwaysOnTop)
            ObjC(void, NSInteger)(GLnative.window, sel(setLevel:), NSFloatingWindowLevel);

#if MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_7
        if (flags & glFullscreen) {
            ObjC(void, NSUInteger)(GLnative.window, sel(setCollectionBehavior:), NSWindowCollectionBehaviorFullScreenPrimary);
            ObjC(void, SEL, id, BOOL)(GLnative.window, sel(performSelectorOnMainThread:withObject:waitUntilDone:), sel(toggleFullScreen:), GLnative.window, NO);
        }
#endif

        ObjC(void, BOOL)(GLnative.window, sel(setAcceptsMouseMovedEvents:), YES);
        ObjC(void, BOOL)(GLnative.window, sel(setRestorable:), NO);
        ObjC(void, BOOL)(GLnative.window, sel(setReleasedWhenClosed:), NO);

        id windowTitle = nil;
        if (flags & glBorderless && flags & ~glFullscreen) {
            windowTitle = ObjC(id)(class(NSString), sel(string));
            ObjC(void, BOOL)(GLnative.window, sel(setTitlebarAppearsTransparent:), YES);
            ObjC(void, BOOL)(ObjC(id, NSUInteger)(GLnative.window, sel(standardWindowButton:), NSWindowZoomButton), sel(setHidden:), YES);
            ObjC(void, BOOL)(ObjC(id, NSUInteger)(GLnative.window, sel(standardWindowButton:), NSWindowCloseButton), sel(setHidden:), YES);
            ObjC(void, BOOL)(ObjC(id, NSUInteger)(GLnative.window, sel(standardWindowButton:), NSWindowMiniaturizeButton), sel(setHidden:), YES);
        } else
            windowTitle = CreateNSString(title);
        ObjC(void, id)(GLnative.window, sel(setTitle:), windowTitle);
        ObjC(void)(GLnative.window, sel(center));
        ObjC(void, id)(GLnative.window, sel(setBackgroundColor:), ObjC(id)(class(NSColor), sel(blackColor)));


        Class WindowDelegate = ObjC_Class(WindowDelegate, NSObject);
        ObjC_AddIVar(WindowDelegate, glWindow, sizeof(void*), "ˆv");
        ObjC_AddMethod(WindowDelegate, windowShouldClose:, windowShouldClose, "c@:@");
        ObjC_AddMethod(WindowDelegate, windowWillClose:, windowWillClose, "v@:@");
        ObjC_AddMethod(WindowDelegate, windowDidResize:, windowDidResize, "v@:@");
        ObjC_AddMethod(WindowDelegate, mouseEntered:, mouseEntered, "v@:@");
        ObjC_AddMethod(WindowDelegate, mouseExited:, mouseExited, "v@:@");
        ObjC_SubClass(WindowDelegate);
        id windowDelegate = ObjC(id)(ObjC(id)((id)WindowDelegate, sel(alloc)), sel(init));
        ObjC(void, id)(GLnative.window, sel(setDelegate:), windowDelegate);

        id contentView = ObjC(id)(GLnative.window, sel(contentView));
        int trackingFlags = NSTrackingMouseEnteredAndExited | NSTrackingActiveInKeyWindow | NSTrackingInVisibleRect;
        id trackingArea = ObjC(id, NSRect, int, id, id)(ObjC_Alloc(NSTrackingArea), sel(initWithRect:options:owner:userInfo:), windowFrame, trackingFlags, windowDelegate, 0);
        ObjC(void, id)(contentView, sel(addTrackingArea:), trackingArea);

        NSOpenGLPixelFormatAttribute pixelFormatAttributes[] = {
            NSOpenGLPFAOpenGLProfile, NSOpenGLProfileVersion3_2Core,
            NSOpenGLPFAColorSize, 24,
            NSOpenGLPFAAlphaSize, 8,
            NSOpenGLPFADoubleBuffer,
            NSOpenGLPFAAccelerated,
            NSOpenGLPFANoRecovery,
            0
        };

        id pixelFormat = ObjC(id, const uint32_t*)(ObjC_Alloc(NSOpenGLPixelFormat), sel(initWithAttributes:), pixelFormatAttributes);

        GLnative.glContext = ObjC(id, id, id)(ObjC_Alloc(NSOpenGLContext), sel(initWithFormat:shareContext:), pixelFormat, nil);
        ObjC(void, id)(GLnative.glContext, sel(setView:), contentView);
        ObjC(void)(GLnative.glContext, sel(makeCurrentContext));

        ObjC(void, BOOL)(GLnative.window, sel(setAcceptsMouseMovedEvents:), YES);
        ObjC(void, SEL, id, BOOL)(GLnative.window, sel(performSelectorOnMainThread:withObject:waitUntilDone:), sel(makeKeyAndOrderFront:), nil, YES);
        ObjC(void, BOOL)(NSApp, sel(activateIgnoringOtherApps:), YES);
    });

    GLwindow.running = 1;
    return 1;
}

// from Carbon HIToolbox/Events.h
enum {
    kVK_ANSI_A = 0x00,
    kVK_ANSI_S = 0x01,
    kVK_ANSI_D = 0x02,
    kVK_ANSI_F = 0x03,
    kVK_ANSI_H = 0x04,
    kVK_ANSI_G = 0x05,
    kVK_ANSI_Z = 0x06,
    kVK_ANSI_X = 0x07,
    kVK_ANSI_C = 0x08,
    kVK_ANSI_V = 0x09,
    kVK_ANSI_B = 0x0B,
    kVK_ANSI_Q = 0x0C,
    kVK_ANSI_W = 0x0D,
    kVK_ANSI_E = 0x0E,
    kVK_ANSI_R = 0x0F,
    kVK_ANSI_Y = 0x10,
    kVK_ANSI_T = 0x11,
    kVK_ANSI_1 = 0x12,
    kVK_ANSI_2 = 0x13,
    kVK_ANSI_3 = 0x14,
    kVK_ANSI_4 = 0x15,
    kVK_ANSI_6 = 0x16,
    kVK_ANSI_5 = 0x17,
    kVK_ANSI_Equal = 0x18,
    kVK_ANSI_9 = 0x19,
    kVK_ANSI_7 = 0x1A,
    kVK_ANSI_Minus = 0x1B,
    kVK_ANSI_8 = 0x1C,
    kVK_ANSI_0 = 0x1D,
    kVK_ANSI_RightBracket = 0x1E,
    kVK_ANSI_O = 0x1F,
    kVK_ANSI_U = 0x20,
    kVK_ANSI_LeftBracket = 0x21,
    kVK_ANSI_I = 0x22,
    kVK_ANSI_P = 0x23,
    kVK_ANSI_L = 0x25,
    kVK_ANSI_J = 0x26,
    kVK_ANSI_Quote = 0x27,
    kVK_ANSI_K = 0x28,
    kVK_ANSI_Semicolon = 0x29,
    kVK_ANSI_Backslash = 0x2A,
    kVK_ANSI_Comma = 0x2B,
    kVK_ANSI_Slash = 0x2C,
    kVK_ANSI_N = 0x2D,
    kVK_ANSI_M = 0x2E,
    kVK_ANSI_Period = 0x2F,
    kVK_ANSI_Grave = 0x32,
    kVK_ANSI_KeypadDecimal = 0x41,
    kVK_ANSI_KeypadMultiply = 0x43,
    kVK_ANSI_KeypadPlus = 0x45,
    kVK_ANSI_KeypadClear = 0x47,
    kVK_ANSI_KeypadDivide = 0x4B,
    kVK_ANSI_KeypadEnter = 0x4C,
    kVK_ANSI_KeypadMinus = 0x4E,
    kVK_ANSI_KeypadEquals = 0x51,
    kVK_ANSI_Keypad0 = 0x52,
    kVK_ANSI_Keypad1 = 0x53,
    kVK_ANSI_Keypad2 = 0x54,
    kVK_ANSI_Keypad3 = 0x55,
    kVK_ANSI_Keypad4 = 0x56,
    kVK_ANSI_Keypad5 = 0x57,
    kVK_ANSI_Keypad6 = 0x58,
    kVK_ANSI_Keypad7 = 0x59,
    kVK_ANSI_Keypad8 = 0x5B,
    kVK_ANSI_Keypad9 = 0x5C,
    kVK_Return = 0x24,
    kVK_Tab = 0x30,
    kVK_Space = 0x31,
    kVK_Delete = 0x33,
    kVK_Escape = 0x35,
    kVK_Command = 0x37,
    kVK_Shift = 0x38,
    kVK_CapsLock = 0x39,
    kVK_Option = 0x3A,
    kVK_Control = 0x3B,
    kVK_RightShift = 0x3C,
    kVK_RightOption = 0x3D,
    kVK_RightControl = 0x3E,
    kVK_Function = 0x3F,
    kVK_F17 = 0x40,
    kVK_VolumeUp = 0x48,
    kVK_VolumeDown = 0x49,
    kVK_Mute = 0x4A,
    kVK_F18 = 0x4F,
    kVK_F19 = 0x50,
    kVK_F20 = 0x5A,
    kVK_F5 = 0x60,
    kVK_F6 = 0x61,
    kVK_F7 = 0x62,
    kVK_F3 = 0x63,
    kVK_F8 = 0x64,
    kVK_F9 = 0x65,
    kVK_F11 = 0x67,
    kVK_F13 = 0x69,
    kVK_F16 = 0x6A,
    kVK_F14 = 0x6B,
    kVK_F10 = 0x6D,
    kVK_F12 = 0x6F,
    kVK_F15 = 0x71,
    kVK_Help = 0x72,
    kVK_Home = 0x73,
    kVK_PageUp = 0x74,
    kVK_ForwardDelete = 0x75,
    kVK_F4 = 0x76,
    kVK_End = 0x77,
    kVK_F2 = 0x78,
    kVK_PageDown = 0x79,
    kVK_F1 = 0x7A,
    kVK_LeftArrow = 0x7B,
    kVK_RightArrow = 0x7C,
    kVK_DownArrow = 0x7D,
    kVK_UpArrow = 0x7E
};

// Taken from tigr: https://github.com/erkkah/tigr/blob/master/tigr.c#L3142
static uint8_t ConvertMacKey(uint16_t key) {
    switch (key) {
        case kVK_ANSI_Q:
            return 'Q';
        case kVK_ANSI_W:
            return 'W';
        case kVK_ANSI_E:
            return 'E';
        case kVK_ANSI_R:
            return 'R';
        case kVK_ANSI_T:
            return 'T';
        case kVK_ANSI_Y:
            return 'Y';
        case kVK_ANSI_U:
            return 'U';
        case kVK_ANSI_I:
            return 'I';
        case kVK_ANSI_O:
            return 'O';
        case kVK_ANSI_P:
            return 'P';
        case kVK_ANSI_A:
            return 'A';
        case kVK_ANSI_S:
            return 'S';
        case kVK_ANSI_D:
            return 'D';
        case kVK_ANSI_F:
            return 'F';
        case kVK_ANSI_G:
            return 'G';
        case kVK_ANSI_H:
            return 'H';
        case kVK_ANSI_J:
            return 'J';
        case kVK_ANSI_K:
            return 'K';
        case kVK_ANSI_L:
            return 'L';
        case kVK_ANSI_Z:
            return 'Z';
        case kVK_ANSI_X:
            return 'X';
        case kVK_ANSI_C:
            return 'C';
        case kVK_ANSI_V:
            return 'V';
        case kVK_ANSI_B:
            return 'B';
        case kVK_ANSI_N:
            return 'N';
        case kVK_ANSI_M:
            return 'M';
        case kVK_ANSI_0:
            return '0';
        case kVK_ANSI_1:
            return '1';
        case kVK_ANSI_2:
            return '2';
        case kVK_ANSI_3:
            return '3';
        case kVK_ANSI_4:
            return '4';
        case kVK_ANSI_5:
            return '5';
        case kVK_ANSI_6:
            return '6';
        case kVK_ANSI_7:
            return '7';
        case kVK_ANSI_8:
            return '8';
        case kVK_ANSI_9:
            return '9';
        case kVK_ANSI_Keypad0:
            return KEY_PAD0;
        case kVK_ANSI_Keypad1:
            return KEY_PAD1;
        case kVK_ANSI_Keypad2:
            return KEY_PAD2;
        case kVK_ANSI_Keypad3:
            return KEY_PAD3;
        case kVK_ANSI_Keypad4:
            return KEY_PAD4;
        case kVK_ANSI_Keypad5:
            return KEY_PAD5;
        case kVK_ANSI_Keypad6:
            return KEY_PAD6;
        case kVK_ANSI_Keypad7:
            return KEY_PAD7;
        case kVK_ANSI_Keypad8:
            return KEY_PAD8;
        case kVK_ANSI_Keypad9:
            return KEY_PAD9;
        case kVK_ANSI_KeypadMultiply:
            return KEY_PADMUL;
        case kVK_ANSI_KeypadPlus:
            return KEY_PADADD;
        case kVK_ANSI_KeypadEnter:
            return KEY_PADENTER;
        case kVK_ANSI_KeypadMinus:
            return KEY_PADSUB;
        case kVK_ANSI_KeypadDecimal:
            return KEY_PADDOT;
        case kVK_ANSI_KeypadDivide:
            return KEY_PADDIV;
        case kVK_F1:
            return KEY_F1;
        case kVK_F2:
            return KEY_F2;
        case kVK_F3:
            return KEY_F3;
        case kVK_F4:
            return KEY_F4;
        case kVK_F5:
            return KEY_F5;
        case kVK_F6:
            return KEY_F6;
        case kVK_F7:
            return KEY_F7;
        case kVK_F8:
            return KEY_F8;
        case kVK_F9:
            return KEY_F9;
        case kVK_F10:
            return KEY_F10;
        case kVK_F11:
            return KEY_F11;
        case kVK_F12:
            return KEY_F12;
        case kVK_Shift:
            return KEY_LSHIFT;
        case kVK_Control:
            return KEY_LCONTROL;
        case kVK_Option:
            return KEY_LALT;
        case kVK_CapsLock:
            return KEY_CAPSLOCK;
        case kVK_Command:
            return KEY_LWIN;
        case kVK_Command - 1:
            return KEY_RWIN;
        case kVK_RightShift:
            return KEY_RSHIFT;
        case kVK_RightControl:
            return KEY_RCONTROL;
        case kVK_RightOption:
            return KEY_RALT;
        case kVK_Delete:
            return KEY_BACKSPACE;
        case kVK_Tab:
            return KEY_TAB;
        case kVK_Return:
            return KEY_RETURN;
        case kVK_Escape:
            return KEY_ESCAPE;
        case kVK_Space:
            return KEY_SPACE;
        case kVK_PageUp:
            return KEY_PAGEUP;
        case kVK_PageDown:
            return KEY_PAGEDN;
        case kVK_End:
            return KEY_END;
        case kVK_Home:
            return KEY_HOME;
        case kVK_LeftArrow:
            return KEY_LEFT;
        case kVK_UpArrow:
            return KEY_UP;
        case kVK_RightArrow:
            return KEY_RIGHT;
        case kVK_DownArrow:
            return KEY_DOWN;
        case kVK_Help:
            return KEY_INSERT;
        case kVK_ForwardDelete:
            return KEY_DELETE;
        case kVK_F14:
            return KEY_SCROLL;
        case kVK_F15:
            return KEY_PAUSE;
        case kVK_ANSI_KeypadClear:
            return KEY_NUMLOCK;
        case kVK_ANSI_Semicolon:
            return KEY_SEMICOLON;
        case kVK_ANSI_Equal:
            return KEY_EQUALS;
        case kVK_ANSI_Comma:
            return KEY_COMMA;
        case kVK_ANSI_Minus:
            return KEY_MINUS;
        case kVK_ANSI_Slash:
            return KEY_SLASH;
        case kVK_ANSI_Backslash:
            return KEY_BACKSLASH;
        case kVK_ANSI_Grave:
            return KEY_BACKTICK;
        case kVK_ANSI_Quote:
            return KEY_TICK;
        case kVK_ANSI_LeftBracket:
            return KEY_LSQUARE;
        case kVK_ANSI_RightBracket:
            return KEY_RSQUARE;
        case kVK_ANSI_Period:
            return KEY_DOT;
        default:
            return 0;
    }
}

static uint32_t ConvertMacMod(NSUInteger modifierFlags) {
    int mods = 0;
    if (modifierFlags & NSEventModifierFlagShift)
        mods |= KEY_MOD_SHIFT;
    if (modifierFlags & NSEventModifierFlagControl)
        mods |= KEY_MOD_CONTROL;
    if (modifierFlags & NSEventModifierFlagOption)
        mods |= KEY_MOD_ALT;
    if (modifierFlags & NSEventModifierFlagCommand)
        mods |= KEY_MOD_SUPER;
    if (modifierFlags & NSEventModifierFlagCapsLock)
        mods |= KEY_MOD_CAPS_LOCK;
    return mods;
}

int glPollWindow(void) {
    if (!GLwindow.running)
        return 0;

    AutoreleasePool({
        id distantPast = ObjC(id)(class(NSDate), sel(distantPast));
        id e = nil;
        while (GLwindow.running && (e = ObjC(id, unsigned long long, id, id, BOOL)(NSApp, sel(nextEventMatchingMask:untilDate:inMode:dequeue:), NSUIntegerMax, distantPast, NSDefaultRunLoopMode, YES))) {
            NSUInteger type = ObjC(NSUInteger)(e, sel(type));
            switch (type) {
                case NSEventTypeLeftMouseDown:
                case NSEventTypeLeftMouseUp:
                    glCallCallback(MouseButton, 1, ConvertMacMod(ObjC(NSUInteger)(e, sel(modifierFlags))), type == NSEventTypeLeftMouseDown);
                    break;
                case NSEventTypeRightMouseDown:
                case NSEventTypeRightMouseUp:
                    glCallCallback(MouseButton, 2, ConvertMacMod(ObjC(NSUInteger)(e, sel(modifierFlags))), type == NSEventTypeRightMouseDown);
                    break;
                case NSEventTypeOtherMouseDown:
                case NSEventTypeOtherMouseUp:
                    glCallCallback(MouseButton, (int)ObjC(NSUInteger)(e, sel(buttonNumber)), ConvertMacMod(ObjC(NSUInteger)(e, sel(modifierFlags))), type == NSEventTypeOtherMouseDown);
                    break;
                case NSEventTypeScrollWheel:
                    glCallCallback(MouseScroll, ObjC(CGFloat)(e, sel(deltaX)), ObjC(CGFloat)(e, sel(deltaY)), ConvertMacMod(ObjC(NSUInteger)(e, sel(modifierFlags))));
                    break;
                case NSEventTypeKeyDown:
                case NSEventTypeKeyUp:
                    glCallCallback(Keyboard, ConvertMacKey(ObjC(unsigned short)(e, sel(keyCode))), ConvertMacMod(ObjC(NSUInteger)(e, sel(modifierFlags))), type == NSEventTypeKeyDown);
                    break;
                case NSEventTypeMouseMoved:
                    if (GLnative.cursorInWindow) {
                        CGPoint locationInWindow = ObjC(CGPoint)(e, sel(locationInWindow));
                        glCallCallback(MouseMove, (int)locationInWindow.x, (int)(ObjC_Struct(CGRect)(ObjC(id)(GLnative.window, sel(contentView)), sel(frame)).size.height - roundf(locationInWindow.y)), ObjC(CGFloat)(e, sel(deltaX)), ObjC(CGFloat)(e, sel(deltaY)));
                    }
                    break;
                default:
                    break;
            }
            ObjC(void, id)(NSApp, sel(sendEvent:), e);
        }
    });
    return GLwindow.running;
}

void glFlushWindow(void) {
    if (!GLwindow.running)
        return;
    ObjC(void)(GLnative.glContext, sel(flushBuffer));
}

void glWindowQuit(void) {
    if (!GLwindow.running)
        return;
    ObjC(void)(GLnative.window, sel(close));
    ObjC_Release(GLnative.glContext);
    ObjC_Release(GLnative.window);
}

void* glWindowNative(void) {
    return (void*)GLnative.window;
}
#elif defined(GLW_WINDOWS)
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#undef near
#undef far
#undef wherever_you_are

#if !defined(GL_LEGACY)
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
#elif defined(GLW_LINUX)
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
#else
#error Unsupported OS
#endif
