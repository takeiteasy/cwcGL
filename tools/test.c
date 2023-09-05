/* test.c -- https://github.com/takeiteasy/cwcGL
 
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

#define CWCGL_VERSION 2010
#include "cwcgl.h"
#include <stdio.h>

// Window event callbacks, I think the names are self-explanatory
void onKeyboard(void *userdata, int key, int modifier, int isDown) {
    printf("Keyboard Event: Key %d is now %s\n", (int)key, isDown ? "down" : "up");
}

void onMouseButton(void *userdata, int button, int modifier, int isDown) {
    printf("Mouse Button Event: Button %d is now %s\n", button, isDown ? "down" : "up");
}

void onMouseMove(void *userdata, int x, int y, float dx, float dy) {
    printf("Mouse Move Event: Position (%d, %d) by (%f, %f)\n", x, y, dx, dy);
}

void onMouseScroll(void *userdata, float dx, float dy, int modifier) {
    printf("Mouse Scroll Event: Scroll delta (%f, %f)\n", dx, dy);
}

void onFocus(void *userdata, int isFocused) {
    printf("Focus Event: Window is now %s\n", isFocused ? "focused" : "unfocused");
}

void onResized(void *userdata, int w, int h) {
    printf("Resize Event: Window is now (%d, %d)\n", w, h);
}

void onClosed(void *userdata) {
    printf("Close Event: Window is now closing\n");
}

int main(int argc, const char *argv[]) {
    if (!glWindow(640, 480, "glWindow", glResizable))
        return 1;
    if (!InitOpenGL())
        return 1;
    
#define X(NAME, ARGS) on##NAME,
    glWindowCallbacks(CWCGL_CALLBACKS NULL);
#undef X

    while (glPollWindow()) {
        glFlushWindow();
    }
    
    glWindowQuit();
    return 0;
}
