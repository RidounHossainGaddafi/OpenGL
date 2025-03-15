#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0); // White background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // Black color for lines

    glBegin(GL_LINES);

    // Main kite shape
    glVertex2i(250, 400); // Point A (top)
    glVertex2i(150, 250); // Point C (left)

    glVertex2i(250, 400); // Point A (top)
    glVertex2i(350, 250); // Point D (right)

    glVertex2i(150, 250); // Point C (left)
    glVertex2i(250, 100); // Point B (bottom)

    glVertex2i(350, 250); // Point D (right)
    glVertex2i(250, 100); // Point B (bottom)

    // Diagonal lines
    glVertex2i(250, 400); // Point A (top)
    glVertex2i(250, 100); // Point B (bottom)

    glVertex2i(150, 250); // Point C (left)
    glVertex2i(350, 250); // Point D (right)

    // Tail of the kite
    glVertex2i(250, 100); // Point B (bottom)
    glVertex2i(200, 50);  // Point E (left tail)

    glVertex2i(250, 100); // Point B (bottom)
    glVertex2i(300, 50);  // Point F (right tail)

    // Horizontal line connecting tail ends
    glVertex2i(200, 50);  // Point E
    glVertex2i(300, 50);  // Point F

    glEnd();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Kite Drawing");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
