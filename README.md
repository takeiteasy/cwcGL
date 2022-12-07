# glWindow

Cross-platform OpenGL context with a incredibly simple API. **WIP** -- See [TODO](https://github.com/takeiteasy/glWindow#todo) section for progress, or [here](https://takeiteasy.github.io/glWindow/) for online documentation.

```c
#include "glWindow.h"

int main(int argc, const char *argv[]) {
    // Create a resizable 640x480
    if (!glWindow(640, 480, "glWindow", glResizable))
        return EXIT_FAILURE;
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
- [ ] Windows context
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
