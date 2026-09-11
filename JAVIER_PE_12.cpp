// Exercise Q12 — Arrow  [Medium] 
#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 1.0f, 0.0f);
    glLineWidth(5.0f);

    glBegin(GL_LINES);
        glVertex2f(-0.7f, 0.0f);
        glVertex2f(0.5f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(0.8f, 0.0f);
        glVertex2f(0.5f, 0.3f);
        glVertex2f(0.5f, -0.3f);
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
    glutCreateWindow("Exercise Q12 - Arrow");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}