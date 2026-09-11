// Exercise Q07 — Two Triangles  [Easy] 
#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    // red tringle
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.8f, -0.5f);
        glVertex2f(-0.2f, -0.5f);
        glVertex2f(-0.5f, 0.5f);
    glEnd();

    // blue triangle
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.2f, -0.5f);
        glVertex2f(0.8f, -0.5f);
        glVertex2f(0.5f, 0.5f);
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
    glutCreateWindow("Exercise Q07 - Two Triangles");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}