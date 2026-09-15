// Exercise Q10 — Five-Pointed Star Outline  [Medium] 
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <cmath>
using namespace std;

const float PI = 3.14159265358979323846f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 0.0f);
    glLineWidth(4.0f);
    
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 10; ++i) {
            
            float angle = PI / 2.0f + i * PI / 5.0f;
            float radius;
            
            if (i % 2 == 0) {
                radius = 0.7f; // outer vertex
            } else {
                radius = 0.3f; // inner vertex
            }
            float x = radius * cosf(angle);
            float y = radius * sinf(angle);

            glVertex2f(x, y);
        }
    glEnd();

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
    glutCreateWindow("Exercise Q10 - Five-Pointed Star Outline");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}