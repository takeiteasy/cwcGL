#include "glWindow.h"

int main(int argc, const char *argv[]) {
    if (!glWindow(640, 480, "glWindow", glResizable))
        abort();
    while (glWindowPoll()) {
        // ...
        glFlushWindow();
    }
    glWindowQuit();
}
