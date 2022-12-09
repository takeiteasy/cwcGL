/* glCommon.c -- https://github.com/takeiteasy/glWindow
 
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
    GL_WIN_CALLBACKS
#undef X
    int running;
    void *userdata;
} GLwindow = {0};

#define glCallCallback(CB, ...)  \
    if (GLwindow.CB##Callback)   \
        GLwindow.CB##Callback(GLwindow.userdata, __VA_ARGS__)

#define X(NAME, ARGS) \
    void(*NAME##Callback)ARGS,
void glWindowCallbacks(GL_WIN_CALLBACKS void* userdata) {
#undef X
#define X(NAME, ARGS) \
    GLwindow.NAME##Callback = NAME##Callback;
    GL_WIN_CALLBACKS
#undef X
    GLwindow.userdata = userdata;
}

#define X(NAME, ARGS)                                          \
    void glWindow##NAME##Callback(void(*NAME##Callback)ARGS) { \
        GLwindow.NAME##Callback = NAME##Callback;              \
    }
GL_WIN_CALLBACKS
#undef X

void glWindowUserdata(void *userdata) {
    GLwindow.userdata = userdata;
}

int glIsWindowOpen(void) {
    return GLwindow.running;
}
