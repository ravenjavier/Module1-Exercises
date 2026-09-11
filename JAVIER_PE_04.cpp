#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 1.0f);
    glLineWidth(4.0f);

    glBegin(GL_LINE_LOOP);

        glVertex2f(0.0f, 0.7f);
        glVertex2f(-0.7f, -0.5f);
        glVertex2f(0.7f, -0.5f);

    glEnd();
    glFlush();
}