// Exercise Q04 — Orange Rectangle  [Easy] 
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
    
    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_POLYGON);

        // bottom
        glVertex2f(-0.8f, -0.4f);
        glVertex2f(0.8f, -0.4f);

        // top
        glVertex2f(0.8f, 0.4f);
        glVertex2f(-0.8f, 0.4f);

    glEnd();
    glFlush();
}

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

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

    glutCreateWindow("Exercise Q04 - Orange Rectangle");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}