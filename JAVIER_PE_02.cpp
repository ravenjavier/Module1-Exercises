// Exercise Q02 — Horizontal Green Line  [Easy] 
#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 1.0f, 0.0f);
    glLineWidth(4.0f);

    glBegin(GL_LINES);
        glVertex2f(-0.8f, 0.0f);
        glVertex2f(0.8f, 0.0f);
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
    glutCreateWindow("Exercise Q02 - Horizontal Green Line");

    init();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}