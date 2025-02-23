#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <math.h>

void init(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
}

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for(int i = 0; i <= 100; i++)
    {
        float angle = 2 * 3.1416 * i / 100;
        float x = rx * cosf(angle) + cx;
        float y = ry * sinf(angle) + cy;
        glVertex2f(x, y);
    }
    glEnd();
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(0.678, 0.847, 0.902);
    circle(10, 8, -10, 10);
    circle(12, 10, 0, 12);
    circle(10, 10, 0, 12);
    circle(10, 8, 10, 10);
    circle(8, 6, 5, 5);
    circle(13, 9, 8, -1);
    circle(8, 6, -5, 5);


    glColor3f(0, 0, 0);
    circle(2, 2, -4, 8);
    circle(2, 2, 4, 8);


    glColor3f(1.0, 0.6, 0.6);
    circle(2, 2, -8, 5);
    circle(2, 2, 8, 5);


    glColor3f(0, 0, 0);
    glBegin(GL_TRIANGLE_FAN);
    for(int i = 50; i <= 150; i++)
    {
        float angle = 3.1416 * i / 180;
        float x = 4 * cosf(angle);
        float y = 3 * sinf(angle);
        glVertex2f(x, y);
    }
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("lab final");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
