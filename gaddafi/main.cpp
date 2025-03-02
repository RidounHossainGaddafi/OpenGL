#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0); //GLfloat red,green,blue,alpha initial value 0 alpha values used by glclear to clear the color buffers
    glMatrixMode(GL_PROJECTION);  // To specify which matrix is the current matrix & projection applies subsequent matrix to projecton matrix stack
    glLoadIdentity();
    glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
    //gluOrtho2D(0.0,300.0,0.0,300.0); // Orthographic representation; multiply the current matrix by an orthographic matrix 2D= left right,bottom,top equivalent near=-1,far=1
}


void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f( 1 ,1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(25,25);
    glVertex2i(75,25);
    glVertex2i(75,75);
    glVertex2i(25,75);
    glEnd();

    glColor3f( 0 ,1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(25,75);
    glVertex2i(50,100);
    glVertex2i(75,75);

    glEnd();

    glColor3f( 1 ,0, 1);
    glBegin(GL_POLYGON);
    glVertex2i(42,25);
    glVertex2i(58,25);
    glVertex2i(58,47);
    glVertex2i(42,47);

    glEnd();

glColor3f( 1 ,0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(59,59);
    glVertex2i(71,59);
    glVertex2i(71,71);
    glVertex2i(59,71);

    glEnd();

// Write your Code


    glutSwapBuffers();
}

int main(int argc,char **argv)
{


    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Lab Final");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
