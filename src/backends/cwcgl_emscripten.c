/* cwcgl_emscripten.c -- https://github.com/takeiteasy/cwcGL
 
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

#include "cwcgl.c"
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
