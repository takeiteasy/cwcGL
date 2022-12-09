# glWindow

Cross-platform OpenGL context with a incredibly simple API. **WIP** -- See [TODO](https://github.com/takeiteasy/glWindow#todo) section for progress, or [here](https://takeiteasy.github.io/glWindow/) for online documentation.

```c
#include "glWindow.h"

static void KeyboardCallback(void *userdata, GLkey key, GLmod modifier, int isDown);
static void MouseButtonCallback(void *userdata, int button, GLmod modifier, int isDown);
static void MouseMoveCallback(void *userdata, int x, int y, float dx, float dy);
static void MouseScrollCallback(void *userdata, float dx, float dy, GLmod modifier);
static void ResizedCallback(void *userdata, int w, int h);
static void FocusCallback(void *userdata, int isFocused);
static void ClosedCallback(void *userdata);

int main(int argc, const char *argv[]) {
    // Create a resizable 640x480
    if (!glWindow(640, 480, "glWindow", glResizable))
        return EXIT_FAILURE;
    // Assign window event callbacks
    glWindowCallbacks(KeyboardCallback,
                      MouseButtonCallback,
                      MouseMoveCallback,
                      MouseScrollCallback,
                      ResizedCallback,
                      FocusCallback,
                      ClosedCallback,
                      NULL); // Last value is userdata that will be passed to callbacks
    // Poll events until window is closed
    while (glWindowPoll()) {
        // ...
        // Flush window
        glFlushWindow();
    }
    // Clean up
    glWindowQuit();
    return EXIT_SUCCESS;
}
```

## TODO

- [X] ~~Mac context~~
- [X] ~~Documentation~~
- [ ] Windows context (WIP)
- [ ] Linux context (X11)
- [ ] WebGL (Emscripten) context

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
