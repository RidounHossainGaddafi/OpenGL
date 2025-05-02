#include <GL/gl.h>
#include<stdio.h>
#include<math.h>
#include <GL/glut.h>

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

float shift1 = 30; // to move the bus.
float shift3 = 0; // to move the car.
float rainOffset = 0;
bool rainOn = false;
float snowOffset = 0;
bool snowOn = true;
bool nightMode = false;


void init(void)
{
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 200, 0, 160);
}
float bx = 0;


void clouds()
{
    if(bx<200)
    {
        bx+=0.035;
    }
    else
    {
        bx-=300;
    }
    // 1st cloud
    circle(4, 8, 97.5+bx, 144);
    circle(4, 8, 99+bx, 140);
    circle(4, 8, 104+bx, 145);
    circle(4, 8, 104+bx, 140);
    circle(4, 6, 107+bx, 142.5);

    // 2nd cloud
    glColor3f(1,1,1);
    circle(4, 8, 7.5+bx, 144);
    circle(4, 8, 9+bx, 140);
    circle(4, 8, 14+bx, 145);
    circle(4, 8, 14+bx, 140);
    circle(4, 6, 17+bx, 142.5);

    glutPostRedisplay();

}



void drawStars()
{
    // Only draw stars if night mode is active.
    if (!nightMode)
        return;

    glColor3f(1, 1, 1);
    glPointSize(3.0);      // Size of the star points

    glBegin(GL_POINTS);
    // Place stars at fixed coordinates within your 200x160 area.
    glVertex2d(20, 140);
    glVertex2d(40, 155);

    glVertex2d(80, 150);
    glVertex2d(100, 145);

    glVertex2d(155, 155);
    glVertex2d(180, 140);
    glEnd();
}

void drawTree()
{

    //leaf
    glColor3f(0.212, 0.612, 0.145);
    circle(3, 4, 5, 87);
    circle(3, 4, 3, 88.5);
    circle(3, 4, 2, 92);
    circle(3, 4, 2, 95);
    circle(3, 4, 3, 96);
    circle(3, 4, 5, 98);
    circle(3, 4, 1, 99);
    circle(3, 4, 1.5, 101);
    circle(3, 4, 6, 96);
    circle(3, 4, 7, 100);
    circle(3, 4, 9, 98);
    circle(3, 4, 7.5, 93);
    circle(3, 4, 13.5, 87);
    circle(3, 4, 15.5, 90);
    circle(3, 4, 12.5, 93);
    circle(3, 4, 11, 98);
    circle(3, 4, 15, 96);
    circle(3, 4, 13, 102);
    circle(3, 4, 10.5, 100.5);
    circle(3, 4, 6, 104);

    glColor3f(0.961, 0.639, 0.035);
    glBegin(GL_QUADS);
    //tree er deho
    glVertex2f(4, 66);
    glVertex2f(6, 90);
    glVertex2f(12, 90);
    glVertex2f(14, 66);
    glEnd();

    glColor3f(0.961, 0.639, 0.035);
    glBegin(GL_QUADS);
    glVertex2f(8, 90);
    glVertex2f(4, 96);
    glVertex2f(5, 98);
    glVertex2f(10, 92);
    glEnd();


    //root
    glColor3f(0.961, 0.639, 0.035);
    circle(4, 2.5, 5.5, 65.3);
    circle(3,3, 8.7, 66);

    //green
    if (nightMode)
        glColor3f(0.314, 0.522, 0.322);
    else
        glColor3f(0.031, 0.859, 0.059);

    circle(5, 2.4, 4.6, 64.3);
    glColor3f(0.961, 0.639, 0.035);
    circle(1, 4, 7.5, 66.5);
    circle(1.5, 1.4, 7.2, 66);
    circle(2, 2, 14, 65.5);
    glColor3f(.031, 0.859, 0.059);
    circle(2, 2, 14, 64.2);
    circle(1, 1, 12.5, 65.5);
    glColor3f(0.961, 0.639, 0.035);

    //branch
    circle(5, 3, 11, 92);
    glColor3f(0.212, 0.612, 0.145);
    circle(5, 3, 11, 93.5);
    glColor3f(0.961, 0.639, 0.035);
    circle(1, 5, 10, 92);
    circle(4.5, 3, 6, 92);
    glColor3f(0.212, 0.612, 0.145);
    circle(4.5, 3, 4, 94);

    glColor3f(0.961, 0.639, 0.035);
    glBegin(GL_QUADS);
    glVertex2f(8, 90);
    glVertex2f(4, 96);
    glVertex2f(5, 97);
    glVertex2f(10, 91);
    glEnd();


    //tree
//Debdaru tree 01
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.275, 0);
    glVertex2d(114, 100);
    glVertex2d(114, 115);
    glVertex2d(119, 115);
    glVertex2d(119, 100);
    glEnd();

    //Debdaru tree 2
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.275, 0);
    glVertex2d(114+26, 100);
    glVertex2d(114+26, 115);
    glVertex2d(119+26, 115);
    glVertex2d(119+26, 100);
    glEnd();

//Debdaru tree 3
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.275, 0);
    glVertex2d(114+26+36, 100);
    glVertex2d(114+26+36, 115);
    glVertex2d(119+26+36, 115);
    glVertex2d(119+26+36, 100);
    glEnd();

    // samll tree 1
    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(10, 30);
    glVertex2d(10, 38);
    glVertex2d(14, 38);
    glVertex2d(14, 30);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.6, 0.275, 0);
    glVertex2d(10+20, 30);
    glVertex2d(10+20, 38);
    glVertex2d(14+20, 38);
    glVertex2d(14+20, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.275, 0);
    glVertex2d(10+60, 30);
    glVertex2d(10+60, 38);
    glVertex2d(14+60, 38);
    glVertex2d(14+60, 30);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.6, 0.275, 0);
    glVertex2d(10+80, 30);
    glVertex2d(10+80, 38);
    glVertex2d(14+80, 38);
    glVertex2d(14+80, 30);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.6, 0.275, 0);
    glVertex2d(10+115, 30);
    glVertex2d(10+115, 38);
    glVertex2d(14+115, 38);
    glVertex2d(14+115, 30);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.6, 0.275, 0);
    glVertex2d(10+135, 30);
    glVertex2d(10+135, 38);
    glVertex2d(14+135, 38);
    glVertex2d(14+135, 30);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.6, 0.275, 0);
    glVertex2d(10, 30);
    glVertex2d(10, 38);
    glVertex2d(14, 38);
    glVertex2d(14, 30);
    glEnd();

    glColor3f(0.212, 0.612, 0.145);
    circle(4,5, 27, 41);
    circle(3,4, 28.5, 44.5);   //+1.5
    circle(3,4, 31, 46.5);     //+2.5
    circle(3,4, 33.5, 44.5);   //+2.5
    circle(4,5, 36, 41);       //+2.5
    circle(3,4, 33, 41);       //-3

    circle(4,5, 27, 41);
    circle(4,5, 8, 41);
    circle(3,4, 9.5, 44.5);
    circle(3,4, 12, 46.5);
    circle(3,4, 14.5, 44.5);
    circle(4,5, 17, 41);
    circle(3,4, 14, 41);

    //circle();
    circle(4,5, 27, 41);
    circle(4,5, 68, 41);
    circle(3,4, 9.5, 44.5);
    circle(3,4, 69.5, 46.5);
    circle(3,4, 72, 44.5);
    circle(4,5, 74.5, 41);
    circle(3,4, 71.5, 41);

    //circle();
    circle(4,5, 27, 41);
    circle(4,5, 88.5, 41);
    circle(3,4, 90, 44.5);
    circle(3,4, 92.5, 46.5);
    circle(3,4, 95, 44.5);
    circle(4,5, 97.5, 41);
    circle(3,4, 94.5, 41);

    //circle();
    circle(4,5, 27, 41);
    circle(4,5, 123.5, 41);
    circle(3,4, 125, 44.5);
    circle(3,4, 127.5, 46.5);
    circle(3,4, 130, 44.5);
    circle(4,5, 132.5, 41);
    circle(3,4, 129.5, 41);

    //circle();
    circle(4,5, 27, 41);
    circle(4,5, 143.5, 41);
    circle(3,4, 145, 44.5);
    circle(3,4, 147.5, 46.5);
    circle(3,4, 150, 44.5);
    circle(4,5, 152.5, 41);
    circle(3,4, 149, 41);

    //tree 1
    glBegin(GL_TRIANGLES);
    glColor3f(0.212, 0.612, 0.145);
    glVertex2d(85.5+31, 109);
    glVertex2d(79.5+31, 103);
    glVertex2d(91.5+31, 103);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.212, 0.612, 0.145);
    glVertex2d(85.5+31, 112);
    glVertex2d(79.5+31, 106);
    glVertex2d(91.5+31, 106);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.212, 0.612, 0.145);
    glVertex2d(85.5+31, 115);
    glVertex2d(79.5+31, 109);
    glVertex2d(91.5+31, 109);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.212, 0.612, 0.145);
    glVertex2d(85.5+31, 118);
    glVertex2d(79.5+31, 112);
    glVertex2d(91.5+31, 112);
    glEnd();

// tree 2
    glBegin(GL_TRIANGLES);
    glColor3f(0.212, 0.612, 0.145);
    glVertex2d(85.5+57, 109);
    glVertex2d(79.5+57, 103);
    glVertex2d(91.5+57, 103);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.212, 0.612, 0.145);
    glVertex2d(85.5+57, 112);
    glVertex2d(79.5+57, 106);
    glVertex2d(91.5+57, 106);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.212, 0.612, 0.145);
    glVertex2d(85.5+57, 115);
    glVertex2d(79.5+57, 109);
    glVertex2d(91.5+57, 109);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.212, 0.612, 0.145);
    glVertex2d(85.5+57, 118);
    glVertex2d(79.5+57, 112);
    glVertex2d(91.5+57, 112);
    glEnd();


    // tree 3
    glBegin(GL_TRIANGLES);
    glColor3f(0.212, 0.612, 0.145);
    glVertex2d(85.5+57+36, 109);
    glVertex2d(79.5+57+36, 103);
    glVertex2d(91.5+57+36, 103);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.212, 0.612, 0.145);
    glVertex2d(85.5+57+36, 112);
    glVertex2d(79.5+57+36, 106);
    glVertex2d(91.5+57+36, 106);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.212, 0.612, 0.145);
    glVertex2d(85.5+57+36, 115);
    glVertex2d(79.5+57+36, 109);
    glVertex2d(91.5+57+36, 109);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.212, 0.612, 0.145);
    glVertex2d(85.5+57+36, 118);
    glVertex2d(79.5+57+36, 112);
    glVertex2d(91.5+57+36, 112);
    glEnd();

}


void line()
{

//Mosque upper lines
    glBegin(GL_LINES);
    glColor3f(0.176, 0.314, 0.78);
    glVertex2i(78, 100);
    glVertex2i(82, 92);
    //line
    glVertex2i(74, 100);
    glVertex2i(82, 86);
    //line
    glVertex2i(70, 100);
    glVertex2i(78, 86);
    //line
    glVertex2i(66, 100);
    glVertex2i(74, 86);
    //line
    glVertex2i(62, 100);
    glVertex2i(70, 86);
    //line
    glVertex2i(58, 100);
    glVertex2i(66, 86);


    glColor3f(0.176, 0.314, 0.78);
    glVertex2i(20, 92);
    glVertex2i(24, 100);
    //line
    glVertex2i(20, 86);
    glVertex2i(28, 100);
    //line
    glVertex2i(24, 86);
    glVertex2i(32, 100);
    //line
    glVertex2i(28, 86);
    glVertex2i(36, 100);
    //line
    glVertex2i(32, 86);
    glVertex2i(40, 100);
    //line
    glVertex2i(36, 86);
    glVertex2i(44, 100);

    glEnd();
    //glFlush();
}


void car()
{

    //bus

    glBegin(GL_QUADS);
    glColor3f(0.878 , 0.867, 0);
    glVertex2d(165 - shift1, 16);
    glVertex2d(166 - shift1, 28);
    glVertex2d(188 - shift1, 28);
    glVertex2d(188- shift1, 16);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0.584, 1);
    glVertex2d(165-shift1, 22);
    glVertex2d(165.5-shift1, 26);
    glVertex2d(168-shift1, 26);
    glVertex2d(168-shift1, 22);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(165-shift1, 18);
    glVertex2d(165-shift1, 19.5);
    glVertex2d(166-shift1, 19.5);
    glVertex2d(166-shift1, 18);
    glEnd();

    //window
    glBegin(GL_QUADS);
    glColor3f(0, 0.584, 1);
    glVertex2d(174-shift1, 22);
    glVertex2d(174-shift1, 26);
    glVertex2d(184-shift1, 26);
    glVertex2d(184-shift1, 22);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2d(177-shift1, 22);
    glVertex2d(177-shift1, 26);
    glVertex2d(177.2-shift1, 26);
    glVertex2d(177.2-shift1, 22);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2d(177+4-shift1, 22);
    glVertex2d(177+4-shift1, 26);
    glVertex2d(177.2+4-shift1, 26);
    glVertex2d(177.2+4-shift1, 22);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2d(169.5-shift1, 17.5);
    glVertex2d(169.5-shift1, 26.5);
    glVertex2d(172.5-shift1, 26.5);
    glVertex2d(172.5-shift1, 17.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0.584, 1);
    glVertex2d(170-shift1, 18);
    glVertex2d(170-shift1, 26);
    glVertex2d(172-shift1, 26);
    glVertex2d(172-shift1, 18);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex2d(171-shift1, 18);
    glVertex2d(171-shift1, 26);
    glVertex2d(171.2-shift1, 26);
    glVertex2d(171.2-shift1, 18);
    glEnd();


    glColor3f(0.039, 0.039, 0.039);
    circle(1.6, 3.2 , 169-shift1, 15);
    glColor3f(0.69, 0.69, 0.69);
    circle(1.2, 2.4, 169-shift1, 15);
    glColor3f(0.039, 0.039, 0.039);
    circle(.9, 1.8, 169-shift1, 15);
    glColor3f(0.69, 0.69, 0.69);
    circle(.6, 1.2, 169-shift1, 15);
    //circle();
    glColor3f(0.039, 0.039, 0.039);
    circle(1.6, 3.2 , 184-shift1, 15);
    glColor3f(0.69, 0.69, 0.69);
    circle(1.2, 2.4, 184-shift1, 15);
    glColor3f(0.039, 0.039, 0.039);
    circle(.9, 1.8, 184-shift1, 15);
    glColor3f(0.69, 0.69, 0.69);
    circle(.6, 1.2, 184-shift1, 15);



    //car 02

    glBegin(GL_QUADS);
    glColor3f(0.196, 0.141, 0.91);
    glVertex2d(10+shift3, 2);
    glVertex2d(10+shift3, 6);
    glVertex2d(20+shift3,6);
    glVertex2d(20+shift3,2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.196, 0.141, 0.91);
    glVertex2d(20+shift3, 2);
    glVertex2d(20+shift3, 6);
    glVertex2d(25+shift3, 4);
    glVertex2d(25+shift3, 2);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.196, 0.141, 0.91);
    glVertex2d(10+shift3, 2);
    glVertex2d(10+shift3, 6);
    glVertex2d(8+shift3, 5);
    glVertex2d(8+shift3, 2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.196, 0.141, 0.91);
    glVertex2d(10+shift3, 6);
    glVertex2d(10+shift3, 9);
    glVertex2d(20+shift3, 9);
    glVertex2d(20+shift3, 6);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.231, 0.231, 0.231);
    glVertex2d(11+shift3, 6.5);
    glVertex2d(11+shift3, 8);
    glVertex2d(14+shift3, 8);
    glVertex2d(14+shift3, 6.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.231, 0.231, 0.231);
    glVertex2d(15.5+shift3, 6.5);
    glVertex2d(15.5+shift3, 8);
    glVertex2d(18.5+shift3, 8);
    glVertex2d(18.5+shift3, 6.5);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.89, 0.89, 0.89);
    glVertex2d(25+shift3, 2);
    glVertex2d(25+shift3, 4);
    glVertex2d(25.3+shift3, 4);
    glVertex2d(25.3+shift3, 2);
    glEnd();



    glColor3f(0.039, 0.039, 0.039);
    circle(1, 2, 13+shift3, 2);
    glColor3f(0.69, 0.69, 0.69);
    circle(.8, 1.6, 13+shift3, 2);
    glColor3f(0.039, 0.039, 0.039);
    circle(.6, 1.2, 13+shift3, 2);
    glColor3f(0.69, 0.69, 0.69);
    circle(.3, .6, 13+shift3, 2);

    //circle();
    glColor3f(0.039, 0.039, 0.039);
    circle(1, 2, 18+shift3, 2);
    glColor3f(0.69, 0.69, 0.69);
    circle(.8, 1.6, 18+shift3, 2);
    glColor3f(0.039, 0.039, 0.039);
    circle(.6, 1.2, 18+shift3, 2);
    glColor3f(0.69, 0.69, 0.69);
    circle(.3, .6, 18+shift3, 2);

}

void drawRain()
{

    if (!rainOn)
        return; //Do not draw rain if the flag is false
    glColor3f(1, 1, 1);
    glLineWidth(1);          // Set a thin line for rain drops
    glBegin(GL_LINES);

    for (float x = 0; x <= 200; x += 8)
    {
        for (float y = 160; y >= 0; y -= 20)
        {
            glVertex2f(x, y + rainOffset);
            glVertex2f(x, y - 2 + rainOffset);
        }
    }
    glEnd();
}


void drawSnow()
{
    if (!snowOn)
        return;

    glColor3f(1, 1, 1);
    glPointSize(3);
    glBegin(GL_POINTS);

    for (float x = 0; x <= 200; x += 5)
    {
        for (float y = 0; y <= 160; y += 20)
        {
            glVertex2f(x, y + snowOffset);
        }
    }
    glEnd();

    snowOffset -= 0.1;

    if (snowOffset < -20)
        snowOffset = 0;
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //sky
    if (nightMode)
        glColor3f(0.4, 0.431, 0.459);
    else
        glColor3f(0.412, 0.8, 1.0);


    glBegin(GL_QUADS);
    glVertex2d(0, 0);
    glVertex2d(0, 160);
    glVertex2d(200, 160);
    glVertex2d(200, 0);
    glEnd();

    if (shift3<200)
    {
        shift3+=0.5;
    }
    else
    {
        shift3-=250;
    }
    if (shift1<200)
    {
        shift1+=0.2;
    }
    else
    {
        shift1-=250;
    }

    // road
    glBegin(GL_QUADS);
    glColor3f(0.663, 0.663, 0.663);
    glVertex2d(0, 0);
    glVertex2d(0, 20);
    glVertex2d(200, 20);
    glVertex2d(200, 0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2, 10);
    glVertex2d(2, 11);
    glVertex2d(6, 11);
    glVertex2d(6, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+8, 10);
    glVertex2d(2+8, 11);
    glVertex2d(6+8, 11);
    glVertex2d(6+8, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+16, 10);
    glVertex2d(2+16, 11);
    glVertex2d(6+16, 11);
    glVertex2d(6+16, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+24, 10);
    glVertex2d(2+24, 11);
    glVertex2d(6+24, 11);
    glVertex2d(6+24, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+32, 10);
    glVertex2d(2+32, 11);
    glVertex2d(6+32, 11);
    glVertex2d(6+32, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+40, 10);
    glVertex2d(2+40, 11);
    glVertex2d(6+40, 11);
    glVertex2d(6+40, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+48, 10);
    glVertex2d(2+48, 11);
    glVertex2d(6+48, 11);
    glVertex2d(6+48, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+56, 10);
    glVertex2d(2+56, 11);
    glVertex2d(6+56, 11);
    glVertex2d(6+56, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+64, 10);
    glVertex2d(2+64, 11);
    glVertex2d(6+64, 11);
    glVertex2d(6+64, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+72, 10);
    glVertex2d(2+72, 11);
    glVertex2d(6+72, 11);
    glVertex2d(6+72, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+80, 10);
    glVertex2d(2+80, 11);
    glVertex2d(6+80, 11);
    glVertex2d(6+80, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+88, 10);
    glVertex2d(2+88, 11);
    glVertex2d(6+88, 11);
    glVertex2d(6+88, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+96, 10);
    glVertex2d(2+96, 11);
    glVertex2d(6+96, 11);
    glVertex2d(6+96, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+104, 10);
    glVertex2d(2+104, 11);
    glVertex2d(6+104, 11);
    glVertex2d(6+104, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+112, 10);
    glVertex2d(2+112, 11);
    glVertex2d(6+112, 11);
    glVertex2d(6+112, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+120, 10);
    glVertex2d(2+120, 11);
    glVertex2d(6+120, 11);
    glVertex2d(6+120, 10);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+128, 10);
    glVertex2d(2+128, 11);
    glVertex2d(6+128, 11);
    glVertex2d(6+128, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+136, 10);
    glVertex2d(2+136, 11);
    glVertex2d(6+136, 11);
    glVertex2d(6+136, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+144, 10);
    glVertex2d(2+144, 11);
    glVertex2d(6+144, 11);
    glVertex2d(6+144, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+152, 10);
    glVertex2d(2+152, 11);
    glVertex2d(6+152, 11);
    glVertex2d(6+152, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+160, 10);
    glVertex2d(2+160, 11);
    glVertex2d(6+160, 11);
    glVertex2d(6+160, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+168, 10);
    glVertex2d(2+168, 11);
    glVertex2d(6+168, 11);
    glVertex2d(6+168, 10);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+176, 10);
    glVertex2d(2+176, 11);
    glVertex2d(6+176, 11);
    glVertex2d(6+176, 10);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+184, 10);
    glVertex2d(2+184, 11);
    glVertex2d(6+184, 11);
    glVertex2d(6+184, 10);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+192, 10);
    glVertex2d(2+192, 11);
    glVertex2d(6+192, 11);
    glVertex2d(6+192, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+200, 10);
    glVertex2d(2+200, 11);
    glVertex2d(6+200, 11);
    glVertex2d(6+200, 10);
    glEnd();

    //background field

    if (nightMode)
        glColor3f(0.314, 0.522, 0.322);
    else
        glColor3f(0.031, 0.859, 0.059);

    glBegin(GL_QUADS);
    //glColor3f(0.031, 0.859, 0.059);
    glVertex2d(0, 30);
    glVertex2d(0, 100);
    glVertex2d(200, 100);
    glVertex2d(200, 30);
    glEnd();

    // road dark green boarder
    glBegin(GL_QUADS);
    glColor3f(0.196, 0.451, 0.196);
    glVertex2d(0, 24);
    glVertex2d(0, 30);
    glVertex2d(200, 30);
    glVertex2d(200, 24);
    glEnd();

    //backgroung building

    if (nightMode)
        glColor3f(0.271, 0.271, 0.271);
    else
        glColor3f(0.847, 0.906, 0.961);

    glBegin(GL_QUADS);
    //glColor3f(0.847, 0.906, 0.961);
    glVertex2d(0, 100);
    glVertex2d(0, 136);
    glVertex2d(4, 136);
    glVertex2d(4, 100);
    glEnd();


    glBegin(GL_QUADS);
    //glColor3f(0.729, 0.839, 0.941);
    glVertex2d(4, 100);
    glVertex2d(4, 130);
    glVertex2d(6, 130);
    glVertex2d(6, 100);
    glEnd();

    glBegin(GL_QUADS);
    //glColor3f(0.729, 0.839, 0.941);
    glVertex2d(6, 100);
    glVertex2d(6, 136);
    glVertex2d(10, 136);
    glVertex2d(10, 100);
    glEnd();

    glBegin(GL_QUADS);
    // glColor3f(0.729, 0.839, 0.941);
    glVertex2d(10, 100);
    glVertex2d(10, 140);
    glVertex2d(16, 140);
    glVertex2d(16, 100);
    glEnd();


    glBegin(GL_QUADS);
    //glColor3f(0.729, 0.839, 0.941);
    glVertex2d(24, 100);
    glVertex2d(24, 142);
    glVertex2d(40, 142);
    glVertex2d(40, 100);
    glEnd();



    glBegin(GL_QUADS);
    //glColor3f(0.729, 0.839, 0.941);
    glVertex2d(40,100);
    glVertex2d(40, 146);
    glVertex2d(44, 146);
    glVertex2d(44, 100);
    glEnd();



    glBegin(GL_QUADS);
    //glColor3f(0.729, 0.839, 0.941);
    glVertex2d(44, 100);
    glVertex2d(44, 150);
    glVertex2d(48, 150);
    glVertex2d(48, 100);
    glEnd();



    glBegin(GL_QUADS);
    //glColor3f(0.729, 0.839, 0.941);
    glVertex2d(48, 100);
    glVertex2d(48, 154);
    glVertex2d(56, 154);
    glVertex2d(56, 100);
    glEnd();



    glBegin(GL_QUADS);
    // glColor3f(0.729, 0.839, 0.941);
    glVertex2d(56, 100);
    glVertex2d(56, 158);
    glVertex2d(58, 158);
    glVertex2d(58, 100);
    glEnd();



    glBegin(GL_QUADS);
    //glColor3f(0.729, 0.839, 0.941);
    glVertex2d(58, 100);
    glVertex2d(58, 152);
    glVertex2d(66, 152);
    glVertex2d(66, 100);
    glEnd();



    glBegin(GL_QUADS);
    //glColor3f(0.729, 0.839, 0.941);
    glVertex2d(66, 100);
    glVertex2d(66, 140);
    glVertex2d(76, 140);
    glVertex2d(76, 100);
    glEnd();



    glBegin(GL_QUADS);
    //glColor3f(0.729, 0.839, 0.941);
    glVertex2d(76, 100);
    glVertex2d(76, 120);
    glVertex2d(90, 120);
    glVertex2d(90, 100);
    glEnd();



    glBegin(GL_QUADS);
    //glColor3f(0.729, 0.839, 0.941);
    glVertex2d(110, 100);
    glVertex2d(110, 140);
    glVertex2d(120, 140);
    glVertex2d(120, 100);
    glEnd();

    glBegin(GL_QUADS);
    //glColor3f(0.729, 0.839, 0.941);
    glVertex2d(120, 100);
    glVertex2d(120, 148);
    glVertex2d(134, 148);
    glVertex2d(134, 100);
    glEnd();



    glBegin(GL_QUADS);
    //glColor3f(0.729, 0.839, 0.941);
    glVertex2d(134, 100);
    glVertex2d(134, 156);
    glVertex2d(152, 156);
    glVertex2d(152, 100);
    glEnd();

    glBegin(GL_QUADS);
    //glColor3f(0.729, 0.839, 0.941);
    glVertex2d(152, 100);
    glVertex2d(152, 150);
    glVertex2d(160, 150);
    glVertex2d(160, 100);
    glEnd();

    glBegin(GL_QUADS);
    //glColor3f(0.729, 0.839, 0.941);
    glVertex2d(160, 100);
    glVertex2d(160, 154);
    glVertex2d(168, 154);
    glVertex2d(168, 100);
    glEnd();

    glBegin(GL_QUADS);
    // glColor3f(0.729, 0.839, 0.941);
    glVertex2d(168, 100);
    glVertex2d(168, 144);
    glVertex2d(176, 144);
    glVertex2d(176, 100);
    glEnd();

    glBegin(GL_QUADS);
    //glColor3f(0.729, 0.839, 0.941);
    glVertex2d(180, 100);
    glVertex2d(180, 120);
    glVertex2d(186, 120);
    glVertex2d(186, 100);
    glEnd();

    glBegin(GL_QUADS);
    //glColor3f(0.729, 0.839, 0.941);
    glVertex2d(186, 100);
    glVertex2d(186, 130);
    glVertex2d(194, 130);
    glVertex2d(194, 100);
    glEnd();

    glBegin(GL_QUADS);
    //glColor3f(0.729, 0.839, 0.941);
    glVertex2d(194, 100);
    glVertex2d(194, 140);
    glVertex2d(202, 140);
    glVertex2d(202, 100);
    glEnd();


    // mosque

    glColor3f(1, 1, 1);
    circle(2, 3.2, 22, 119.5);
    circle(2, 3.2, 30, 111.5);
    circle(3, 4, 39, 106);
    circle(3, 4.5, 51, 110.1);
    circle(3, 4, 63, 106);
    circle(2.1, 3.2, 72, 111.5);
    circle(2.1, 3.2, 80, 119.5);


    glBegin(GL_QUADS);
    glColor3f(1, 0.796, 0.361);
    glVertex2d(20, 60);
    glVertex2d(20, 100);
    glVertex2d(82, 100);
    glVertex2d(82, 60);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 0.796, 0.361);
    glVertex2d(20, 100);
    glVertex2d(20, 120);
    glVertex2d(24, 120);
    glVertex2d(24, 100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 0.796, 0.361);
    glVertex2d(28, 100);
    glVertex2d(28, 112);
    glVertex2d(32, 112);
    glVertex2d(32, 100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 0.796, 0.361);
    glVertex2d(36, 100);
    glVertex2d(36, 106);
    glVertex2d(42, 106);
    glVertex2d(42, 100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 0.796, 0.361);
    glVertex2d(47, 100);
    glVertex2d(47, 105);
    glVertex2d(55, 105);
    glVertex2d(55, 100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.631, 0.573, 0.153);
    glVertex2d(48, 107);
    glVertex2d(48, 110);
    glVertex2d(54, 110);
    glVertex2d(54, 107);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 0.906, 0.216);
    glVertex2d(47, 105);
    glVertex2d(46, 107);
    glVertex2d(56, 107);
    glVertex2d(55, 105);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 0.796, 0.361);
    glVertex2d(60, 100);
    glVertex2d(60, 106);
    glVertex2d(66, 106);
    glVertex2d(66, 100);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 0.796, 0.361);
    glVertex2d(70, 100);
    glVertex2d(70, 112);
    glVertex2d(74, 112);
    glVertex2d(74, 100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 0.796, 0.361);
    glVertex2d(78, 100);
    glVertex2d(78, 120);
    glVertex2d(82, 120);
    glVertex2d(82, 100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.71, 0.553, 0.22);
    glVertex2d(16, 52);
    glVertex2d(20, 60);
    glVertex2d(82, 60);
    glVertex2d(86, 52);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.361, 0.306, 0.184);
    glVertex2d(16, 50);
    glVertex2d(16, 52);
    glVertex2d(86, 52);
    glVertex2d(86, 50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.51, 0.212, 0.082);
    glVertex2d(42, 24);
    glVertex2d(46,50);
    glVertex2d(56, 50);
    glVertex2d(60, 24);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.878, 0.537, 0.137);
    glVertex2d(44, 60);
    glVertex2d(44, 90);
    glVertex2d(45, 90);
    glVertex2d(45, 60);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.878, 0.537, 0.137);
    glVertex2d(44+13.5, 60);
    glVertex2d(44+13.5, 90);
    glVertex2d(45+13.5, 90);
    glVertex2d(45+13.5, 60);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.878, 0.537, 0.137);
    glVertex2d(44, 89);
    glVertex2d(44, 90);
    glVertex2d(57.5, 90);
    glVertex2d(57.5, 89);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.341, 0.341, 0.318);
    glVertex2d(51, 84);
    glVertex2d(48, 80);
    glVertex2d(54, 80);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.341, 0.341, 0.318);
    glVertex2d(48, 60);
    glVertex2d(48, 80);
    glVertex2d(54, 80);
    glVertex2d(54, 60);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.341, 0.341, 0.318);
    glVertex2d(51-14, 84);
    glVertex2d(48-14, 80);
    glVertex2d(54-14, 80);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.341, 0.341, 0.318);
    glVertex2d(51-27, 84);
    glVertex2d(48-27, 80);
    glVertex2d(54-27, 80);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.341, 0.341, 0.318);
    glVertex2d(51+14, 84);
    glVertex2d(48+14, 80);
    glVertex2d(54+14, 80);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.341, 0.341, 0.318);
    glVertex2d(51+27, 84);
    glVertex2d(48+27, 80);
    glVertex2d(54+27, 80);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.341, 0.341, 0.318);
    glVertex2d(48-14, 60+10);
    glVertex2d(48-14, 80);
    glVertex2d(54-14, 80);
    glVertex2d(54-14, 60+10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.341, 0.341, 0.318);
    glVertex2d(48-27, 60+10);
    glVertex2d(48-27, 80);
    glVertex2d(54-27, 80);
    glVertex2d(54-27, 60+10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.341, 0.341, 0.318);
    glVertex2d(48+14, 60+10);
    glVertex2d(48+14, 80);
    glVertex2d(54+14, 80);
    glVertex2d(54+14, 60+10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.341, 0.341, 0.318);
    glVertex2d(48+27, 60+10);
    glVertex2d(48+27, 80);
    glVertex2d(54+27, 80);
    glVertex2d(54+27, 60+10);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.878, 0.537, 0.137);
    glVertex2d(58, 86);
    glVertex2d(58, 87);
    glVertex2d(82, 87);
    glVertex2d(82, 86);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.878, 0.537, 0.137);
    glVertex2d(20, 86);
    glVertex2d(20, 87);
    glVertex2d(44, 87);
    glVertex2d(44, 86);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.176, 0.314, 0.78);
    glVertex2d(44, 90);
    glVertex2d(44, 82);
    glVertex2d(52, 90);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.176, 0.314, 0.78);
    glVertex2d(58, 90);
    glVertex2d(58, 82);
    glVertex2d(50, 90);
    glEnd();

    glColor3f(1, 0.796, 0.361);
    circle(1.4, 2, 46.5, 84.5);
    circle(1.4, 2, 48, 86.5);
    //circle();
    circle(1.4, 2, 55, 84.5);
    circle(1.4, 2, 53.5, 86.5);



    //mosque moon 01
    glColor3f(1, 0.796, 0.361);
    circle(1.2,2.4, 22+8.5, 125.5-8);

    if (nightMode)
        glColor3f(0.271, 0.271, 0.271);
    else
        glColor3f(0.847, 0.906, 0.961);
    circle(1.2,2.4, 21.5+8.5, 126.5-8);

    //mosque moon 02
    glColor3f(1, 0.796, 0.361);
    circle(1.2,2.4, 22+16.8, 125.5-12);

    if (nightMode)
        glColor3f(0.271, 0.271, 0.271);
    else
        glColor3f(0.847, 0.906, 0.961);
    circle(1.2,2.4, 21.5+16.8, 126.5-12);

    //mosque moon 03
    glColor3f(1, 0.796, 0.361);
    circle(1.4,2.8, 22+16.8+11.5, 125.5-12+5);

    if (nightMode)
        glColor3f(0.271, 0.271, 0.271);
    else
        glColor3f(0.847, 0.906, 0.961);
    circle(1.4,2.8, 21.5+16.8+11.5, 126.5-12+5);

    //mosque moon 04
    glColor3f(1, 0.796, 0.361);
    circle(1.2,2.4, 22+40.5, 125.5-12);

    if (nightMode)
        glColor3f(0.271, 0.271, 0.271);
    else
        glColor3f(0.847, 0.906, 0.961);
    circle(1.2,2.4, 21.5+40.5, 126.5-12);

    //mosque moon 05
    glColor3f(1, 0.796, 0.361);
    circle(1.2,2.4, 22+49.5, 125.5-8);

    if (nightMode)
        glColor3f(0.271, 0.271, 0.271);
    else
        glColor3f(0.847, 0.906, 0.961);
    circle(1.2,2.4, 21.5+49.5, 126.5-8);


    //dolna

    //shadow

    glBegin(GL_QUADS);
    glColor3f(0.565, 0.553, 0.569);
    glVertex2d(160, 47);
    glVertex2d(161, 49);
    glVertex2d(174.5, 51);
    glVertex2d(175.5, 50);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.565, 0.553, 0.569);
    glVertex2d(182, 40);
    glVertex2d(182, 41);
    glVertex2d(196, 45);
    glVertex2d(196, 44);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(1, 0.098, 0);
    glVertex2d(158, 46.5);
    glVertex2d(170, 74);
    glVertex2d(170, 72);
    glVertex2d(161, 46.5);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(1, 0.098, 0);
    glVertex2d(174,50);
    glVertex2d(170, 72);
    glVertex2d(170,74);
    glVertex2d(176, 50);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 0.098, 0);
    glVertex2d(170, 72);
    glVertex2d(170, 74);
    glVertex2d(190, 70);
    glVertex2d(190, 68);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 0.098, 0);
    glVertex2d(182, 40);
    glVertex2d(190, 70);
    glVertex2d(191, 70);
    glVertex2d(184, 40);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 0.098, 0);
    glVertex2d(195, 44);
    glVertex2d(188, 70);
    glVertex2d(190, 70);
    glVertex2d(197, 44);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 0.098, 0);
    glVertex2d(165, 58);
    glVertex2d(166, 60);
    glVertex2d(172, 60);
    glVertex2d(173, 58);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 0.098, 0);
    glVertex2d(185, 50);
    glVertex2d(186, 52);
    glVertex2d(194, 52);
    glVertex2d(194, 50);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 0.098, 0);
    glVertex2d(168+1, 58-1);
    glVertex2d(182+1, 58-1);
    glVertex2d(184+1, 54-1);
    glVertex2d(170+1, 54-1);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(170, 56);
    glVertex2d(174, 73.1);
    glVertex2d(174.5, 73.1);
    glVertex2d(170.5, 56.5);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(181, 56);
    glVertex2d(184, 70.7);
    glVertex2d(184.5, 70.7);
    glVertex2d(181.5, 56);
    glEnd();


    //sleeper
    glBegin(GL_QUADS);
    glColor3f(0.624, 0.024, 1);
    glVertex2d(100, 68);
    glVertex2d(100, 100);
    glVertex2d(102, 100);
    glVertex2d(102, 68);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.624, 0.024, 1);
    glVertex2d(108, 70);
    glVertex2d(108, 102);
    glVertex2d(110, 102);
    glVertex2d(110, 70);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.624, 0.024, 1);
    glVertex2d(102, 78-2);
    glVertex2d(102, 80-2);
    glVertex2d(110, 80-2);
    glVertex2d(110, 78-2);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.624, 0.024, 1);
    glVertex2d(102, 78+3);
    glVertex2d(102, 80+3);
    glVertex2d(110, 80+3);
    glVertex2d(110, 78+3);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.624, 0.024, 1);
    glVertex2d(102, 78+7.5);
    glVertex2d(102, 80+7.5);
    glVertex2d(110, 80+7.5);
    glVertex2d(110, 78+7.5);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.624, 0.024, 1);
    glVertex2d(102, 78+11.5);
    glVertex2d(102, 80+11.5);
    glVertex2d(110, 80+11.5);
    glVertex2d(110, 78+11.5);
    glEnd();



    //shadow
    glBegin(GL_QUADS);
    glColor3f(0.565, 0.553, 0.569);
    glVertex2d(137, 56);
    glVertex2d(100, 68);
    glVertex2d(108, 70);
    glVertex2d(141, 62);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.286, 0.58, 0.859);
    glVertex2d(102, 94);
    glVertex2d(108, 97);
    glVertex2d(141, 62);
    glVertex2d(137, 56);
    glEnd();


    //buildings 01


    glBegin(GL_QUADS);
    glColor3f(0.91, 0.761, 0.392);
    glVertex2d(90, 100);
    glVertex2d(90, 120);
    glVertex2d(110, 120);
    glVertex2d(110, 100);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);
    glVertex2d(100, 130);
    glVertex2d(88, 118);
    glVertex2d(112, 118);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.91, 0.761, 0.392);
    glVertex2d(100, 126);
    glVertex2d(93, 118);
    glVertex2d(107, 118);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(98, 118);
    glVertex2d(98, 122);
    glVertex2d(102, 122);
    glVertex2d(102, 118);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0, 0.345, 1);
    glVertex2d(99, 119);
    glVertex2d(99, 121);
    glVertex2d(101, 121);
    glVertex2d(101, 119);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.004, 0.345, 0.988);
    glVertex2d(92, 110);
    glVertex2d(92, 116);
    glVertex2d(98, 116);
    glVertex2d(98, 110);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.004, 0.345, 0.988);
    glVertex2d(92+10, 110);
    glVertex2d(92+10, 116);
    glVertex2d(98+10, 116);
    glVertex2d(98+10, 110);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.004, 0.345, 0.988);
    glVertex2d(92, 110-8);
    glVertex2d(92, 116-8);
    glVertex2d(98, 116-8);
    glVertex2d(98, 110-8);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.004, 0.345, 0.988);
    glVertex2d(92+10, 110-8);
    glVertex2d(92+10, 116-8);
    glVertex2d(98+10, 116-8);
    glVertex2d(98+10, 110-8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(94.5, 110);
    glVertex2d(94.5, 116);
    glVertex2d(95.5, 116);
    glVertex2d(95.5, 110);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(94.5+10, 110);
    glVertex2d(94.5+10, 116);
    glVertex2d(95.5+10, 116);
    glVertex2d(95.5+10, 110);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(94.5, 110-8);
    glVertex2d(94.5, 116-8);
    glVertex2d(95.5, 116-8);
    glVertex2d(95.5, 110-8);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(94.5+10, 110-8);
    glVertex2d(94.5+10, 116-8);
    glVertex2d(95.5+10, 116-8);
    glVertex2d(95.5+10, 110-8);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(92,112.5);
    glVertex2d(92, 113.5);
    glVertex2d(98, 113.5);
    glVertex2d(98, 112.5);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(92+10,112.5);
    glVertex2d(92+10, 113.5);
    glVertex2d(98+10, 113.5);
    glVertex2d(98+10, 112.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(92,112.5-8);
    glVertex2d(92, 113.5-8);
    glVertex2d(98, 113.5-8);
    glVertex2d(98, 112.5-8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(92+10,112.5-8);
    glVertex2d(92+10, 113.5-8);
    glVertex2d(98+10, 113.5-8);
    glVertex2d(98+10, 112.5-8);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.451, 0.294, 0);
    glVertex2d(92, 116);
    glVertex2d(91.5, 117);
    glVertex2d(98.5, 117);
    glVertex2d(98, 116);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.451, 0.294, 0);
    glVertex2d(92+10, 116);
    glVertex2d(91.5+10, 117);
    glVertex2d(98.5+10, 117);
    glVertex2d(98+10, 116);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.451, 0.294, 0);
    glVertex2d(92, 116-8);
    glVertex2d(91.5, 117-8);
    glVertex2d(98.5, 117-8);
    glVertex2d(98, 116-8);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.451, 0.294, 0);
    glVertex2d(92+10, 116-8);
    glVertex2d(91.5+10, 117-8);
    glVertex2d(98.5+10, 117-8);
    glVertex2d(98+10, 116-8);
    glEnd();



    //building 2

    glBegin(GL_QUADS);
    glColor3f(0.141, 0.216, 0.38);
    glVertex2d(124, 100);
    glVertex2d(124, 130);
    glVertex2d(136, 130);
    glVertex2d(136, 100);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.141, 0.216, 0.38);
    glVertex2d(124, 130);
    glVertex2d(123, 131);
    glVertex2d(137, 131);
    glVertex2d(136, 130);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.922, 0.922, 0.922);
    glVertex2d(132, 124);
    glVertex2d(132, 126);
    glVertex2d(134, 126);
    glVertex2d(134, 124);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.922, 0.922, 0.922);
    glVertex2d(132, 124-10);
    glVertex2d(132, 126-10);
    glVertex2d(134, 126-10);
    glVertex2d(134, 124-10);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.922, 0.922, 0.922);
    glVertex2d(132, 124-20);
    glVertex2d(132, 126-20);
    glVertex2d(134, 126-20);
    glVertex2d(134, 124-20);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0.318, 1);
    glVertex2d(125, 120);
    glVertex2d(125, 128);
    glVertex2d(131, 128);
    glVertex2d(131, 120);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(126, 121);
    glVertex2d(126, 127);
    glVertex2d(130, 127);
    glVertex2d(130, 121);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    glVertex2d(125, 120);
    glVertex2d(125, 123);
    glVertex2d(131, 123);
    glVertex2d(131, 120);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0.318, 1);
    glVertex2d(125, 120-10);
    glVertex2d(125, 128-10);
    glVertex2d(131, 128-10);
    glVertex2d(131, 120-10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0, 0.318, 1);
    glVertex2d(125, 120-20);
    glVertex2d(125, 128-20);
    glVertex2d(131, 128-20);
    glVertex2d(131, 120-20);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(126, 121-10);
    glVertex2d(126, 127-10);
    glVertex2d(130, 127-10);
    glVertex2d(130, 121-10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(126, 121-20);
    glVertex2d(126, 127-20);
    glVertex2d(130, 127-20);
    glVertex2d(130, 121-20);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    glVertex2d(125, 120-10);
    glVertex2d(125, 123-10);
    glVertex2d(131, 123-10);
    glVertex2d(131, 120-10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4, 0.4, 0.4);
    glVertex2d(125, 120-20);
    glVertex2d(125, 123-20);
    glVertex2d(131, 123-20);
    glVertex2d(131, 120-20);
    glEnd();

    //building 03

    glBegin(GL_QUADS);
    glColor3f(0.91, 0.761, 0.392);
    glVertex2d(90+60, 100);
    glVertex2d(90+60, 120);
    glVertex2d(110+60, 120);
    glVertex2d(110+60, 100);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);
    glVertex2d(100+60, 130);
    glVertex2d(88+60, 118);
    glVertex2d(112+60, 118);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.91, 0.761, 0.392);
    glVertex2d(100+60, 126);
    glVertex2d(93+60, 118);
    glVertex2d(107+60, 118);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(98+60, 118);
    glVertex2d(98+60, 122);
    glVertex2d(102+60, 122);
    glVertex2d(102+60, 118);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0, 0.345, 1);
    glVertex2d(99+60, 119);
    glVertex2d(99+60, 121);
    glVertex2d(101+60, 121);
    glVertex2d(101+60, 119);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.004, 0.345, 0.988);
    glVertex2d(92+60, 110);
    glVertex2d(92+60, 116);
    glVertex2d(98+60, 116);
    glVertex2d(98+60, 110);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.004, 0.345, 0.988);
    glVertex2d(92+10+60, 110);
    glVertex2d(92+10+60, 116);
    glVertex2d(98+10+60, 116);
    glVertex2d(98+10+60, 110);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.004, 0.345, 0.988);
    glVertex2d(92+60, 110-8);
    glVertex2d(92+60, 116-8);
    glVertex2d(98+60, 116-8);
    glVertex2d(98+60, 110-8);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.004, 0.345, 0.988);
    glVertex2d(92+10+60, 110-8);
    glVertex2d(92+10+60, 116-8);
    glVertex2d(98+10+60, 116-8);
    glVertex2d(98+10+60, 110-8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(94.5+60, 110);
    glVertex2d(94.5+60, 116);
    glVertex2d(95.5+60, 116);
    glVertex2d(95.5+60, 110);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(94.5+10+60, 110);
    glVertex2d(94.5+10+60, 116);
    glVertex2d(95.5+10+60, 116);
    glVertex2d(95.5+10+60, 110);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(94.5+60, 110-8);
    glVertex2d(94.5+60, 116-8);
    glVertex2d(95.5+60, 116-8);
    glVertex2d(95.5+60, 110-8);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(94.5+10+60, 110-8);
    glVertex2d(94.5+10+60, 116-8);
    glVertex2d(95.5+10+60, 116-8);
    glVertex2d(95.5+10+60, 110-8);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(92+60,112.5);
    glVertex2d(92+60, 113.5);
    glVertex2d(98+60, 113.5);
    glVertex2d(98+60, 112.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(92+10+60,112.5);
    glVertex2d(92+10+60, 113.5);
    glVertex2d(98+10+60, 113.5);
    glVertex2d(98+10+60, 112.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(92+60,112.5-8);
    glVertex2d(92+60, 113.5-8);
    glVertex2d(98+60, 113.5-8);
    glVertex2d(98+60, 112.5-8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(92+10+60,112.5-8);
    glVertex2d(92+10+60, 113.5-8);
    glVertex2d(98+10+60, 113.5-8);
    glVertex2d(98+10+60, 112.5-8);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.451, 0.294, 0);
    glVertex2d(92+60, 116);
    glVertex2d(91.5+60, 117);
    glVertex2d(98.5+60, 117);
    glVertex2d(98+60, 116);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.451, 0.294, 0);
    glVertex2d(92+10+60, 116);
    glVertex2d(91.5+10+60, 117);
    glVertex2d(98.5+10+60, 117);
    glVertex2d(98+10+60, 116);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.451, 0.294, 0);
    glVertex2d(92+60, 116-8);
    glVertex2d(91.5+60, 117-8);
    glVertex2d(98.5+60, 117-8);
    glVertex2d(98+60, 116-8);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.451, 0.294, 0);
    glVertex2d(92+10+60, 116-8);
    glVertex2d(91.5+10+60, 117-8);
    glVertex2d(98.5+10+60, 117-8);
    glVertex2d(98+10+60, 116-8);
    glEnd();

    //sun

    if (nightMode)
    {
        //moon
        glColor3f(1.0, 1.0, 1.0);
        circle(4.5, 5.5, 190, 150);
        glColor3f(0.4, 0.431, 0.459);
        circle(4.5, 5.5, 188.5, 151);

    }
    else
    {
        //sun
        glColor3f(0.957, 1, 0.047);
        circle(4, 5, 190, 150);
    }


    // road
    glBegin(GL_QUADS);
    glColor3f(0.663, 0.663, 0.663);
    glVertex2d(0, 0);
    glVertex2d(0, 20);
    glVertex2d(200, 20);
    glVertex2d(200, 0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2, 10);
    glVertex2d(2, 11);
    glVertex2d(6, 11);
    glVertex2d(6, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+8, 10);
    glVertex2d(2+8, 11);
    glVertex2d(6+8, 11);
    glVertex2d(6+8, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+16, 10);
    glVertex2d(2+16, 11);
    glVertex2d(6+16, 11);
    glVertex2d(6+16, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+24, 10);
    glVertex2d(2+24, 11);
    glVertex2d(6+24, 11);
    glVertex2d(6+24, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+32, 10);
    glVertex2d(2+32, 11);
    glVertex2d(6+32, 11);
    glVertex2d(6+32, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+40, 10);
    glVertex2d(2+40, 11);
    glVertex2d(6+40, 11);
    glVertex2d(6+40, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+48, 10);
    glVertex2d(2+48, 11);
    glVertex2d(6+48, 11);
    glVertex2d(6+48, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+56, 10);
    glVertex2d(2+56, 11);
    glVertex2d(6+56, 11);
    glVertex2d(6+56, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+64, 10);
    glVertex2d(2+64, 11);
    glVertex2d(6+64, 11);
    glVertex2d(6+64, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+72, 10);
    glVertex2d(2+72, 11);
    glVertex2d(6+72, 11);
    glVertex2d(6+72, 10);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+80, 10);
    glVertex2d(2+80, 11);
    glVertex2d(6+80, 11);
    glVertex2d(6+80, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+88, 10);
    glVertex2d(2+88, 11);
    glVertex2d(6+88, 11);
    glVertex2d(6+88, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+96, 10);
    glVertex2d(2+96, 11);
    glVertex2d(6+96, 11);
    glVertex2d(6+96, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+104, 10);
    glVertex2d(2+104, 11);
    glVertex2d(6+104, 11);
    glVertex2d(6+104, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+112, 10);
    glVertex2d(2+112, 11);
    glVertex2d(6+112, 11);
    glVertex2d(6+112, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+120, 10);
    glVertex2d(2+120, 11);
    glVertex2d(6+120, 11);
    glVertex2d(6+120, 10);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+128, 10);
    glVertex2d(2+128, 11);
    glVertex2d(6+128, 11);
    glVertex2d(6+128, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+136, 10);
    glVertex2d(2+136, 11);
    glVertex2d(6+136, 11);
    glVertex2d(6+136, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+144, 10);
    glVertex2d(2+144, 11);
    glVertex2d(6+144, 11);
    glVertex2d(6+144, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+152, 10);
    glVertex2d(2+152, 11);
    glVertex2d(6+152, 11);
    glVertex2d(6+152, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+160, 10);
    glVertex2d(2+160, 11);
    glVertex2d(6+160, 11);
    glVertex2d(6+160, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+168, 10);
    glVertex2d(2+168, 11);
    glVertex2d(6+168, 11);
    glVertex2d(6+168, 10);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+176, 10);
    glVertex2d(2+176, 11);
    glVertex2d(6+176, 11);
    glVertex2d(6+176, 10);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+184, 10);
    glVertex2d(2+184, 11);
    glVertex2d(6+184, 11);
    glVertex2d(6+184, 10);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+192, 10);
    glVertex2d(2+192, 11);
    glVertex2d(6+192, 11);
    glVertex2d(6+192, 10);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1, 1, 1);
    glVertex2d(2+200, 10);
    glVertex2d(2+200, 11);
    glVertex2d(6+200, 11);
    glVertex2d(6+200, 10);
    glEnd();


    // road boarder white
    glBegin(GL_QUADS);
    glColor3f(0.969, 0.969, 0.969);
    glVertex2d(0, 20);
    glVertex2d(0, 24);
    glVertex2d(200, 24);
    glVertex2d(200, 20);
    glEnd();

    //grass 01

    glBegin(GL_QUADS);
    glColor3f(0.196, 0.451, 0.196);
    glVertex2d(160, 78);
    glVertex2d(160, 80);
    glVertex2d(174, 80);
    glVertex2d(174, 78);
    glEnd();

    //circle();
    circle(2, 3, 160, 81);
    circle(2, 3, 162, 83);
    circle(2, 3, 164, 81);
    circle(2, 3, 165, 81);
    circle(2, 3, 160, 84);
    circle(2, 3, 165, 83);
    circle(2, 3, 166, 81);
    circle(2, 3, 167, 85);
    circle(2, 3, 168, 84.5);
    circle(2, 3, 169, 82.5);
    circle(2, 3, 171, 81);
    circle(2, 3, 172, 84);
    circle(2, 3, 174, 81);



    //grass 02

    glBegin(GL_QUADS);
    glColor3f(0.196, 0.451, 0.196);
    glVertex2d(160+2, 78-42);
    glVertex2d(160+2, 80-42);
    glVertex2d(174+2, 80-42);
    glVertex2d(174+2, 78-42);
    glEnd();

    //circle();
    circle(2, 3, 160+2, 81-42);
    circle(2, 3, 162+2, 83-42);
    circle(2, 3, 164+2, 81-42);
    circle(2, 3, 165+2, 81-42);
    circle(2, 3, 160+2, 84-42);
    circle(2, 3, 165+2, 83-42);
    circle(2, 3, 166+2, 81-42);
    circle(2, 3, 167+2, 85-42);
    circle(2, 3, 168+2, 84.5-42);
    circle(2, 3, 169+2, 82.5-42);
    circle(2, 3, 171+2, 81-42);
    circle(2, 3, 172+2, 84-42);
    circle(2, 3, 174+2, 81-42);

    drawRain();

    rainOffset -= .5;
    if (rainOffset < -20)
        rainOffset = 0;

    drawSnow();



    car();
    clouds();
    drawStars();
    drawTree();
    line();


    glFlush();
    glutSwapBuffers();
}

void normalKey(unsigned char key, int x, int y)
{
    switch (key)
    {
        //rain
    case 'r':
    case 'R':
        rainOn = !rainOn;
        break;
        //snow
    case 's':
    case 'S':
        snowOn = !snowOn;
        break;
    }

    if (key == 'n' || key == 'N')
    {
        nightMode = !nightMode;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Daffodil Society Mosque Complex");
    init();
    glutDisplayFunc(display);
    //glutSpecialFunc(key);
    glutKeyboardFunc(normalKey);
    glutMainLoop();
    return 0;
}
