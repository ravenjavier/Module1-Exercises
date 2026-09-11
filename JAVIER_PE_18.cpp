// Exercise Q18 — Rotating Clock Hand  [Hard]
#include <GL/glut.h>
#include <cmath>

// hand angle
float angle = 90.0f;

// clock radius
float clockRadius = 0.75f;

float toRadians(float degrees)
{
    return degrees * (3.14159265358979323846f / 180.0f);
}

void drawClockFace()
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 100; i++)
    {
        float theta = 2.0f * 3.14159265358979323846f * i / 100.0f;
        float x = clockRadius * cos(theta);
        float y = clockRadius * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();

    // 12 ticks
    for (int i = 0; i < 12; i++)
    {
        float theta = toRadians(i * 30.0f);
        
        // outer point
        float outerRadius = 0.75f;
        float outerX = outerRadius * cos(theta);
        float outerY = outerRadius * sin(theta);

        // inner point
        float innerRadius = 0.65f;
        float innerX = innerRadius * cos(theta);
        float innerY = innerRadius * sin(theta);

        glBegin(GL_LINES);
        glVertex2f(innerX, innerY);
        glVertex2f(outerX, outerY);
        glEnd();
    }
}

void drawHand()
{
    float theta = toRadians(angle);

    float handRadius = 0.55f;

    float handX = handRadius * cos(theta);
    float handY = handRadius * sin(theta);
    glColor3f(1.0f, 0.0f, 0.0f);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(handX, handY);
    glEnd();

    glLineWidth(1.0f);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawClockFace();
    drawHand();

    glutSwapBuffers();
}

void idle()
{
    angle -= 0.3f;
    if (angle < 0.0f)
    {
        angle += 360.0f;
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
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercise Q18 - Rotating Clock Hand");

    init();

    glutDisplayFunc(display);

    glutIdleFunc(idle);

    glutMainLoop();
    return 0;
}