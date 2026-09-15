// Exercise Q16 — Bouncing Ball  [Hard] 
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;

float ballX = 0.0f;
float ballY = 0.0f;

float dx = 0.007f;
float dy = 0.007f;

float radius = 0.08f;

void drawBall()
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(ballX, ballY);

    for (int i = 0; i <= 100; i++)
    {
        float angle = 2.0f * 3.1415926f * i / 100;

        float x = ballX + radius * cos(angle);
        float y = ballY + radius * sin(angle);

        glVertex2f(x, y);
    }

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawBall();

    glutSwapBuffers();
}

void idle()
{
    ballX += dx;
    ballY += dy;

    if (ballX + radius >= 1.0f)
    {
        ballX = 1.0f - radius;
        dx = -dx;
    }

    if (ballX - radius <= -1.0f)
    {
        ballX = -1.0f + radius;
        dx = -dx;
    }

    if (ballY + radius >= 1.0f)
    {
        ballY = 1.0f - radius;
        dy = -dy;
    }

    if (ballY - radius <= -1.0f)
    {
        ballY = -1.0f + radius;
        dy = -dy;
    }

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
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercise Q16 - Bouncing Ball");

    init();

    glutDisplayFunc(display);

    glutIdleFunc(idle);

    glutMainLoop();

    return 0;
}