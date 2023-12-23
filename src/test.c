#include "cwcgl.h"
#include <GLUT/glut.h>
#include <stdio.h>

static void loop(void) {
    glClearColor(1.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    if (InitOpenGL())
        return 0;
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(640, 480);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutCreateWindow("cwcgl test");
    glutDisplayFunc(loop);
    glutMainLoop();
}
