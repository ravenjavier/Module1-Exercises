// Exercise Q09 — 4x4 Checkerboard  [Medium] 
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the checkerboard
    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            if ((row + col) % 2 == 0) {
                glColor3f(1.0f, 1.0f, 1.0f);
            } else {
                glColor3f(0.0f, 0.0f, 0.0f);
            }

            float x1 = -1.0f + col * 0.5f;
            float y1 = -1.0f + row * 0.5f;
            float x2 = x1 + 0.5f;
            float y2 = y1 + 0.5f;

            glBegin(GL_QUADS);
                glVertex2f(x1, y1);
                glVertex2f(x2, y1);
                glVertex2f(x2, y2);
                glVertex2f(x1, y2);
            glEnd();
        }
    }

    glFlush();
}

void init()
{
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercise Q09 - 4x4 Checkerboard");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}