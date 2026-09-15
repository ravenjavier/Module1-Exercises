// Exercise Q11 — Concentric Circles  [Medium] 
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

const float PI = 3.14159265358979323846f;

void drawCircleOutline(float radius, float r, float g, float b) 
{
    glColor3f(r, g, b);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 60; i++) 
    {
        float angle = 2.0f * PI * i / 60.0f;
        float x = radius * cosf(angle);
        float y = radius * sinf(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void display() 
{
    glClear(GL_COLOR_BUFFER_BIT);

    // red
    drawCircleOutline(0.8f, 1.0f, 0.0f, 0.0f);
    // green
    drawCircleOutline(0.5f, 0.0f, 1.0f, 0.0f);
    // blue
    drawCircleOutline(0.3f, 0.0f, 0.0f, 1.0f);

    glFlush();
}

void init() 
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glLineWidth(3.0f);
}

int main(int argc, char** argv) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercise Q11 - Concentric Circles");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
