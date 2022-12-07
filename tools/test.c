#include "glWindow.h"

int main(int argc, const char *argv[]) {
    if (!glWindow(640, 480, "glWindow", glResizable))
        return 1;
    while (glWindowPoll()) {
        // ...
        glFlushWindow();
    }
    glWindowQuit();
    return 0;
}
