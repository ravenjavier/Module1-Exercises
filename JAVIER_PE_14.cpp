// Exercise Q14 — Simple Landscape  [Medium] 
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

void drawSun(float centerX, float centerY, float radius) 
{
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(centerX, centerY);
        for (int i = 0; i <= 40; i++) {
            float angle = 2.0f * PI * i / 40.0f;
            float x = centerX + radius * cosf(angle);
            float y = centerY + radius * sinf(angle);
            glVertex2f(x, y);
        }
    glEnd();
}

void display() 
{
    glClear(GL_COLOR_BUFFER_BIT);

    // ground
    glColor3f(0.0f, 0.6f, 0.0f);

    glBegin(GL_POLYGON);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(1.0f, -0.4f);
        glVertex2f(-1.0f, -0.4f);
    glEnd();

    // sun
    drawSun(0.7f, 0.7f, 0.15f);

    glFlush();
}

void init() 
{
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);

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
    glutCreateWindow("Exercise Q14 - Simple Landscape");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}