// Exercise Q19 — Keyboard Color Picker  [Hard] 
#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <cstdlib>
using namespace std;

float colors[6][3] = {
    {1.0f, 0.0f, 0.0f}, // red
    {0.0f, 1.0f, 0.0f}, // green
    {0.0f, 0.0f, 1.0f}, // blue
    {1.0f, 1.0f, 0.0f}, // yellow
    {1.0f, 0.0f, 1.0f}, // magenta
    {0.0f, 1.0f, 1.0f}  // cyan
};

string colorNames[6] = {
    "Red",
    "Green",
    "Blue",
    "Yellow",
    "Magenta",
    "Cyan"
};

int currentColor = 0;

void display()
{
    glClearColor(
        colors[currentColor][0],
        colors[currentColor][1],
        colors[currentColor][2],
        1.0f
    );
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    // esc key to exit
    if (key == 27)
    {
        cout << "Exiting program." << endl;
        exit(0);
    }

    if (key >= '1' && key <= '6')
    {
        currentColor = key - '1';
        cout << "Selected Color: " << colorNames[currentColor] << endl;
        
        glutPostRedisplay();
    }
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
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
    glutCreateWindow("Exercise Q19 - Keyboard Color Picker");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    cout << "Press keys 1-6 to change colors:" << endl;
    for (int i = 0; i < 6; ++i)
    {
        cout << (i + 1) << ": " << colorNames[i] << endl;
    }
    cout << "Press ESC to exit." << endl;

    glutMainLoop();
    return 0;
}