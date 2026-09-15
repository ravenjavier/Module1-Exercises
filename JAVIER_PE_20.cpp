// Exercise Q20 — Procedural Striped Flag with Star (Capstone)  [Hard] 
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <cmath>
using namespace std;

// configuration
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 500;

const int STRIPE_COUNT = 6;

// flag dimensions
const float FLAG_LEFT   = -0.9f;
const float FLAG_RIGHT  =  0.9f;
const float FLAG_BOTTOM = -0.6f;
const float FLAG_TOP    =  0.6f;

// star parameters
void drawStar(float centerX, float centerY,
              float outerRadius, float innerRadius)
{
    const float PI = 3.14159265359f;

    glBegin(GL_TRIANGLE_FAN);

    // center of the star
    glVertex2f(centerX, centerY);

    for (int i = 0; i <= 10; i++)
    {
        float angle = 90.0f + i * 36.0f;

        float radius;

        if (i % 2 == 0)
            radius = outerRadius;
        else
            radius = innerRadius;

        float x = centerX + radius * cos(angle * PI / 180.0f);
        float y = centerY + radius * sin(angle * PI / 180.0f);

        glVertex2f(x, y);
    }

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // horizontal stripes
    float flagHeight = FLAG_TOP - FLAG_BOTTOM;
    float stripeHeight = flagHeight / STRIPE_COUNT;

    for (int i = 0; i < STRIPE_COUNT; i++)
    {
        float yBottom = FLAG_BOTTOM + i * stripeHeight;
        float yTop = yBottom + stripeHeight;

        if (i % 2 == 0)
        {
            glColor3f(0.8f, 0.0f, 0.0f);  // red
        }
        else
        {
            glColor3f(1.0f, 1.0f, 1.0f);  // white
        }

        glBegin(GL_QUADS);

        glVertex2f(FLAG_LEFT,  yBottom);
        glVertex2f(FLAG_RIGHT, yBottom);
        glVertex2f(FLAG_RIGHT, yTop);
        glVertex2f(FLAG_LEFT,  yTop);

        glEnd();
    }

    // five pointed star
    glColor3f(1.0f, 1.0f, 0.0f); // yellow

    drawStar(-0.55f, 0.25f, 0.18f, 0.08f);

    glFlush();
}

void init()
{
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercise Q20 — Procedural Striped Flag with Star (Capstone)");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}