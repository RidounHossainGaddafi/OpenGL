#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

float p = -50.0;

void init(void)
{
    glClearColor(0.0, 0.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0, 2);
    glVertex2f(5,2);
    glVertex2f(10,2);
    glVertex2f(12,2);
    glVertex2f(12.5,2.5);
    glVertex2f(13,4);
    glVertex2f(24,5);
    glVertex2f(32,5);

    glVertex2f(34,10);
    glVertex2f(32,10);
    glVertex2f(30,7);
    glVertex2f(20,8);

    glVertex2f(12,9);
    glVertex2f(11,10);
    glVertex2f(10,12);
    glVertex2f(10,13);

    glVertex2f(9, 15);
    glVertex2f(5,18);
    glVertex2f(3,19);
    glVertex2f(1,19.5);
    glVertex2f(0,20);
    glVertex2f(-5,20);
    glVertex2f(-8,18);
    glVertex2f(-10,17);

    glVertex2f(-12,16);
    glVertex2f(-13,9);
    glVertex2f(-14,8);
    glVertex2f(-15,8);
    glVertex2f(-15,4);
    glVertex2f(-14,2);
    glVertex2f(-10,2);
    glVertex2f(-5,2);
    glVertex2f(-3,2);
    glEnd();

    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-14, 10);
    glVertex2f(-10, 10);
    glVertex2f(-7, 10);

    glVertex2f(-6, 11);
    glVertex2f(-5, 13);
    glVertex2f(-6, 15);
    glVertex2f(-14, 10);
    glVertex2f(-10, 10);
    glVertex2f(-7, 10);
    glEnd();

    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0, 2);
    glVertex2f(5,2);
    glVertex2f(10,2);
    glEnd();

    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0, 2);
    glVertex2f(5,2);
    glVertex2f(10,2);
    glEnd();

    glutSwapBuffers();

    //
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Lab Final");
    init();
    glutDisplayFunc(Draw);
    glutIdleFunc(Draw);
    glutMainLoop();
    return 0;
}
