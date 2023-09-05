# cwcGL 

A cross-platform OpenGL window + context. **WIP**

<p align="center">
  <img width="492" height="640" src="https://raw.githubusercontent.com/takeiteasy/cwcGL/master/zap.jpg">
</p>

```c
// Load OpenGL version to 3.2
#define CWCGL_VERSION 3020
#include "glWindow.h"

// Window event callbacks
void KeyboardCallback(void *userdata, int key, int modifier, int isDown);
void MouseButtonCallback(void *userdata, int button, int modifier, int isDown);
void MouseMoveCallback(void *userdata, int x, int y, float dx, float dy);
void MouseScrollCallback(void *userdata, float dx, float dy, int modifier);
void ResizedCallback(void *userdata, int w, int h);
void FocusCallback(void *userdata, int isFocused);
void ClosedCallback(void *userdata);

int main(int argc, const char *argv[]) {
    // Create a resizable 640x480 window
    if (!glWindow(640, 480, "glWindow", glResizable))
        return EXIT_FAILURE;
    // Initialize OpenGL
    if (!InitOpenGL())
        return EXIT_FAILURE;
    // Assign window event callbacks
    glWindowCallbacks(KeyboardCallback,
                      MouseButtonCallback,
                      MouseMoveCallback,
                      MouseScrollCallback,
                      ResizedCallback,
                      FocusCallback,
                      ClosedCallback,
                      NULL); // Last value is userdata that will 
                             // be passed to callbacks
    // Poll events until window is closed
    while (glPollWindow()) {
        // ...
        // Flush window
        glFlushWindow();
    }
    // Clean up
    glWindowQuit();
    return EXIT_SUCCESS;
}
```

## License
```
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
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
```
