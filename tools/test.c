#define CWCGL_VERSION 3020
#include "cwcgl.h"
#include <stdio.h>

static GLcontext test = {0};

int main(int argc, const char *argv[]) {
    if (!glWindow(640, 480, "glWindow", glResizable))
        return 1;
    if (InitOpenGL())
        return 1;

    while (glPollWindow()) {
        cwcglClear(&test, GL_COLOR_BUFFER_BIT);
        cwcglBegin(&test, GL_TRIANGLES);
        cwcglVertex3f(&test, -0.5f, -0.5f, 0.0f);
        cwcglVertex3f(&test, 0.5f, -0.5f, 0.0f);
        cwcglVertex3f(&test, 0.0f, 0.5f, 0.0f);
        cwcglEnd(&test);
        ProcessGLQueue(&test);
        glFlushWindow();
    }

    glWindowQuit();
    return 0;
}
