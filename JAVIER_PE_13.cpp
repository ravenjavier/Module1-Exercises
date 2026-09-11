// Exercise Q13 — Letter "F" from Rectangles  [Medium] 
#include <GL/glut.h>

void drawRect(float x0, float y0, float x1, float y1)
{
    glBegin(GL_POLYGON);

        glVertex2f(x0, y0);
        glVertex2f(x1, y0);
        glVertex2f(x1, y1);
        glVertex2f(x0, y1);

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 1.0f, 0.0f);

    // vertical bar
    drawRect(-0.5f, -0.6f, -0.2f, 0.6f);

    // top bar
    drawRect(-0.5f, 0.3f, 0.5f, 0.6f);

    // middle bar
    drawRect(-0.5f, -0.05f, 0.3f, 0.2f);

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
    glutCreateWindow("Exercise Q13 - Letter F from Rectangles");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}