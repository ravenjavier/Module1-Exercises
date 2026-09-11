// Exercise Q06 — Hexagon Outline  [Easy] 
#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 1.0f);
    glLineWidth(4.0f);

    glBegin(GL_LINE_LOOP);

        glVertex2f(0.0f, 0.7f);
        glVertex2f(0.6f, 0.35f);
        glVertex2f(0.6f, -0.35f);
        glVertex2f(0.0f, -0.7f);
        glVertex2f(-0.6f, -0.35f);
        glVertex2f(-0.7f, 0.35f);

    glEnd();
    glFlush();
}

void init()
{
    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);

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
    glutCreateWindow("Exercise Q06 - Hexagon Outline");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}