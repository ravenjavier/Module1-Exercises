// Exercise Q17 — Traffic Light Simulator  [Hard] 
#include <GL/glut.h>
#include <cmath>

int state = 0;

void drawCircle(float centerX, float centerY, float radius,
                float red, float green, float blue)
{
    glColor3f(red, green, blue);

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(centerX, centerY);
    for (int i = 0; i <= 100; i++)
    {
        float angle = 2.0f * 3.1415926f * i / 100.0f;

        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);

        glVertex2f(x, y);
    }

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // traffic light
    glColor3f(0.15f, 0.15f, 0.15f);

    glBegin(GL_QUADS);
    glVertex2f(-0.35f, 0.85f);
    glVertex2f( 0.35f, 0.85f);
    glVertex2f( 0.35f,-0.85f);
    glVertex2f(-0.35f,-0.85f);
    glEnd();

    float radius = 0.20f;

    // red light
    if (state == 0)
        drawCircle(0.0f, 0.50f, radius, 1.0f, 0.0f, 0.0f);
    else
        drawCircle(0.0f, 0.50f, radius, 0.25f, 0.0f, 0.0f);

    // yellow light
    if (state == 1)
        drawCircle(0.0f, 0.0f, radius, 1.0f, 1.0f, 0.0f);
    else
        drawCircle(0.0f, 0.0f, radius, 0.25f, 0.25f, 0.0f);

    // green light
    if (state == 2)
        drawCircle(0.0f, -0.50f, radius, 0.0f, 1.0f, 0.0f);
    else
        drawCircle(0.0f, -0.50f, radius, 0.0f, 0.25f, 0.0f);

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    // press "n" to go next light
    if (key == 'n' || key == 'N')
    {
        state = (state + 1) % 3;

        glutPostRedisplay();
    }

    // press "esc" to exit
    if (key == 27)
    {
        exit(0);
    }
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
    glutInitWindowSize(500, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercise Q17 - Traffic Light Simulator");

    init();

    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}