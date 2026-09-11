// Exercise Q05 — Square Outline on Gray Background  [Easy] 
#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(4.0f);

    glBegin(GL_LINE_LOOP);

        // bottom
        glVertex2f(-0.4f, -0.4f);
        glVertex2f(0.4f, -0.4f);

        // top
        glVertex2f(0.4f, 0.4f);
        glVertex2f(-0.4f, 0.4f);

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
    glutCreateWindow("Exercise Q05 - Square Outline on Gray Background");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}