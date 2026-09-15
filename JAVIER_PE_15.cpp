// Exercise Q15 — Move a Square with Arrow Keys  [Hard] 
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <GL/glut.h>
#include <iostream>
using namespace std;

//square 
float squareX = 0.0f;
float squareY = 0.0f;
float squareSize = 0.2f;
float moveSpeed = 0.1f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 1.0f, 0.0f);

    float halfSize = squareSize / 2.0f;

    float left   = squareX - halfSize;
    float right  = squareX + halfSize;
    float bottom = squareY - halfSize;
    float top    = squareY + halfSize;

    glBegin(GL_QUADS);

        glVertex2f(left, bottom);
        glVertex2f(right, bottom);
        glVertex2f(right, top);
        glVertex2f(left, top);

    glEnd();

    glFlush();
}

void specialKeys(int key, int x, int y)
{
    // Move the square
    if (key == GLUT_KEY_LEFT)
    {
        squareX -= moveSpeed;
    }
    else if (key == GLUT_KEY_RIGHT)
    {
        squareX += moveSpeed;
    }
    else if (key == GLUT_KEY_UP)
    {
        squareY += moveSpeed;
    }
    else if (key == GLUT_KEY_DOWN)
    {
        squareY -= moveSpeed;
    }

    float halfSize = squareSize / 2.0f;

    if (squareX < -1.0f + halfSize)
        squareX = -1.0f + halfSize;

    if (squareX > 1.0f - halfSize)
        squareX = 1.0f - halfSize;

    if (squareY < -1.0f + halfSize)
        squareY = -1.0f + halfSize;

    if (squareY > 1.0f - halfSize)
        squareY = 1.0f - halfSize;

    glutPostRedisplay();
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
    glutCreateWindow("Exercise Q15 - Move Square with Arrow Keys");

    init();

    glutDisplayFunc(display);

    glutSpecialFunc(specialKeys);

    glutMainLoop();

    return 0;
}
