#include<windows.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse (int button, int state, int x,int y);
void ukuran(int, int);
void mouseMotion(int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;

int is_depth;
int p1 = 0, q1 = 0, angle = 0, s1 = 0;
float scaleX = 1, scaleY = 1, scaleZ = 1;

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(50, 80);
    glutCreateWindow("TR");
    init();
    glutDisplayFunc(tampil);
    glutReshapeFunc(ukuran);

    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutKeyboardFunc(keyboard);

    glutIdleFunc(tampil);
    glutMainLoop();
    return 0;
}

void init(void)
{
    glClearColor(0.0, 0.7, 1.0, 0.0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth =1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);
}

void tampil(void)
{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glScalef(scaleX, scaleY, scaleZ);
        gluLookAt(0.0f,0.0f,3.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f); // untuk mengatur penglihatan mata/objek
        glRotatef(xrot, 1.0f,0.0f,0.0f);
        glRotatef(yrot, 0.0f, 1.0f,0.0f);
        glPushMatrix();
//tengah
//depan
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(-85.0, -45.0, 90.0);
    glVertex3f(-85.0, 500.0, 90.0);
    glVertex3f(85.0, 500.0, 90.0);
    glVertex3f(85.0, -45.0, 90.0);
    glEnd();
//gedung kanan kecil depan
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(85.0, -45.0, 80.0);
    glVertex3f(85.0, 250.0, 80.0);
    glVertex3f(400.0, 250.0,80.0);
    glVertex3f(400.0, -45.0,80.0);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
   glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(-85.0, -45.0, -90.0);
    glVertex3f(-85.0, 500.0, -90.0);
    glVertex3f(85.0, 500.0, -90.0);
    glVertex3f(85.0, -45.0, -90.0);
    glEnd();
    //gedung kanan belakang
    glBegin(GL_QUADS);
   glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(-0.0, -45.0, -90.0);
    glVertex3f(-0.0, 250.0, -90.0);
    glVertex3f(400.0, 250.0, -90.0);
    glVertex3f(400.0, -45.0, -90.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(85.0, 500.0, 90.0);
    glVertex3f(85.0, -45.0, 90.0);
    glVertex3f(85.0, -45.0, -90.0);
    glVertex3f(85.0, 500.0, -90.0);
    glEnd();
     //gedung kanan kanan
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(400.0, 250.0, 90.0);
    glVertex3f(400.0, -45.0, 90.0);
    glVertex3f(400.0, -45.0, -90.0);
    glVertex3f(400.0, 250.0, -90.0);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(-85.0, 250.0, 90.0);
    glVertex3f(-85.0, -45.0, 90.0);
    glVertex3f(-85.0, -45.0, -90.0);
    glVertex3f(-85.0, 250.0, -90.0);
    glEnd();

    //kiri
    //depan
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(-85.0, -45.0, 80.0);
    glVertex3f(-85.0, 250.0, 80.0);
    glVertex3f(-400.0, 250.0, 80.0);
    glVertex3f(-400.0, -45.0, 80.0);
    glEnd();
    //kiri depan kecil
    //belakang
    glBegin(GL_QUADS);
   glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(-86.0, -45.0, -90.0);
    glVertex3f(-86.0, 250.0, -90.0);
    glVertex3f(-400.0, 250.0, -90.0);
    glVertex3f(-400.0, -45.0, -90.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(-85.0, 500.0, 90.0);
    glVertex3f(-85.0, -45.0, 90.0);
    glVertex3f(-85.0, -45.0, -90.0);
    glVertex3f(-85.0, 500.0, -90.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);
    glVertex3f(-400.0, 250.0, 90.0);
    glVertex3f(-400.0, -45.0, 90.0);
    glVertex3f(-400.0, -45.0, -90.0);
    glVertex3f(-400.0, 250.0, -90.0);
    glEnd();

    //pembatas kiri
        glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(-85.0, -45.0, 90.0);
    glVertex3f(-85.0, 500.0, 90.0);
    glEnd();
    //pembatas kiri belakang
        glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(-85.0, -45.0, -90.0);
    glVertex3f(-85.0, 500.0, -90.0);
    glEnd();

    //pembatas kanan
        glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(85.0, -45.0, 90.0);
    glVertex3f(85.0, 500.0, 90.0);
    glEnd();
    //pembatas kiri kanan
        glBegin(GL_LINES);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(85.0, -45.0, -90.0);
    glVertex3f(85.0, 500.0, -90.0);
    glEnd();
    //TANAH
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.2, 0.0);
    glVertex3f(700.0, -45.0, 600.0);
    glVertex3f(700.0, -45.0, -600.0);
    glVertex3f(-700.0, -45, -600.0);
    glVertex3f(-700.0,-45.0, 600.0);
    glEnd();

        //ATAP GEDUNG
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(85.0, 500.0, 100.0);
    glVertex3f(85.0, 500.0, -100.0);
    glVertex3f(-90.0, 500.0, -100.0);
    glVertex3f(-90.0, 500.0, 100.0);
    glEnd();
     //atap gedung kanan
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(400.0,   250.0, 100.0);
    glVertex3f(400.0,   250.0, -100.0);
    glVertex3f(85.0,    250.0, -100.0);
    glVertex3f(85.0,    250.0, 100.0);
    glEnd();


        //ATAP GEDUNG KIRI
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(-85.0, 250.0, 100.0);
    glVertex3f(-85.0, 250.0, -100.0);
    glVertex3f(-400, 250.0, -100.0);
    glVertex3f(-400.0, 250.0, 100.0);
    glEnd();

 //jendela 1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-80.0, 450.0, 100.1);
    glVertex3f(-80.0, 420.0, 100.1);
    glVertex3f(-60.0, 420.0, 100.1);
    glVertex3f(-60.0, 450.0, 100.1);
    glEnd();
 //jendela 2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-50.0, 450.0, 100.1);
    glVertex3f(-50.0, 420.0, 100.1);
    glVertex3f(-30.0, 420.0, 100.1);
    glVertex3f(-30.0, 450.0, 100.1);
    glEnd();
    //jendela 3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-20.0, 450.0, 100.1);
    glVertex3f(-20.0, 420.0, 100.1);
    glVertex3f(10.0, 420.0, 100.1);
    glVertex3f(10.0, 450.0, 100.1);
    glEnd();
     //jendela 4
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(20.0, 450.0, 100.1);
    glVertex3f(20.0, 420.0, 100.1);
    glVertex3f(40.0, 420.0, 100.1);
    glVertex3f(40.0, 450.0, 100.1);
    glEnd();
       //jendela 5
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(50.0, 450.0, 100.1);
    glVertex3f(50.0, 420.0, 100.1);
    glVertex3f(70.0, 420.0, 100.1);
    glVertex3f(70.0, 450.0, 100.1);
    glEnd();


//ke 2

     //jendela 1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-80.0, 400.0, 100.1);
    glVertex3f(-80.0, 370.0, 100.1);
    glVertex3f(-60.0, 370.0, 100.1);
    glVertex3f(-60.0, 400.0, 100.1);
    glEnd();
 //jendela 2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-50.0, 400.0, 100.1);
    glVertex3f(-50.0, 370.0, 100.1);
    glVertex3f(-30.0, 370.0, 100.1);
    glVertex3f(-30.0, 400.0, 100.1);
    glEnd();
    //jendela 3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-20.0, 400.0, 100.1);
    glVertex3f(-20.0, 370.0, 100.1);
    glVertex3f(10.0, 370.0, 100.1);
    glVertex3f(10.0, 400.0, 100.1);
    glEnd();
     //jendela 4
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(20.0, 400.0, 100.1);
    glVertex3f(20.0, 370.0, 100.1);
    glVertex3f(40.0, 370.0, 100.1);
    glVertex3f(40.0, 400.0, 100.1);
    glEnd();
       //jendela 5
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(50.0, 400.0, 100.1);
    glVertex3f(50.0, 370.0, 100.1);
    glVertex3f(70.0, 370.0, 100.1);
    glVertex3f(70.0, 400.0, 100.1);
    glEnd();

//ke 3

     //jendela 1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-80.0, 350.0, 100.1);
    glVertex3f(-80.0, 320.0, 100.1);
    glVertex3f(-60.0, 320.0, 100.1);
    glVertex3f(-60.0, 350.0, 100.1);
    glEnd();
 //jendela 2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-50.0, 350.0, 100.1);
    glVertex3f(-50.0, 320.0, 100.1);
    glVertex3f(-30.0, 320.0, 100.1);
    glVertex3f(-30.0, 350.0, 100.1);
    glEnd();
    //jendela 3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-20.0, 350.0, 100.1);
    glVertex3f(-20.0, 320.0, 100.1);
    glVertex3f(10.0, 320.0, 100.1);
    glVertex3f(10.0, 350.0, 100.1);
    glEnd();
     //jendela 4
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(20.0, 350.0, 100.1);
    glVertex3f(20.0, 320.0, 100.1);
    glVertex3f(40.0, 320.0, 100.1);
    glVertex3f(40.0, 350.0, 100.1);
    glEnd();
       //jendela 5
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(50.0, 350.0, 100.1);
    glVertex3f(50.0, 320.0, 100.1);
    glVertex3f(70.0, 320.0, 100.1);
    glVertex3f(70.0, 350.0, 100.1);
    glEnd();

    //ke 4

     //jendela 1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-80.0, 300.0, 100.1);
    glVertex3f(-80.0, 270.0, 100.1);
    glVertex3f(-60.0, 270.0, 100.1);
    glVertex3f(-60.0, 300.0, 100.1);
    glEnd();
 //jendela 2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-50.0, 300.0, 100.1);
    glVertex3f(-50.0, 270.0, 100.1);
    glVertex3f(-30.0, 270.0, 100.1);
    glVertex3f(-30.0, 300.0, 100.1);
    glEnd();
    //jendela 3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-20.0, 300.0, 100.1);
    glVertex3f(-20.0, 270.0, 100.1);
    glVertex3f(10.0, 270.0, 100.1);
    glVertex3f(10.0, 300.0, 100.1);
    glEnd();
     //jendela 4
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(20.0, 300.0, 100.1);
    glVertex3f(20.0, 270.0, 100.1);
    glVertex3f(40.0, 270.0, 100.1);
    glVertex3f(40.0, 300.0, 100.1);
    glEnd();
       //jendela 5
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(50.0, 300.0, 100.1);
    glVertex3f(50.0, 270.0, 100.1);
    glVertex3f(70.0, 270.0, 100.1);
    glVertex3f(70.0, 300.0, 100.1);
    glEnd();

      //ke 5

     //jendela 1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-80.0, 250.0, 100.1);
    glVertex3f(-80.0, 220.0, 100.1);
    glVertex3f(-60.0, 220.0, 100.1);
    glVertex3f(-60.0, 250.0, 100.1);
    glEnd();
 //jendela 2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-50.0, 250.0, 100.1);
    glVertex3f(-50.0, 220.0, 100.1);
    glVertex3f(-30.0, 220.0, 100.1);
    glVertex3f(-30.0, 250.0, 100.1);
    glEnd();
    //jendela 3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-20.0, 250.0, 100.1);
    glVertex3f(-20.0, 220.0, 100.1);
    glVertex3f(10.0, 220.0, 100.1);
    glVertex3f(10.0, 250.0, 100.1);
    glEnd();
     //jendela 4
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(20.0, 250.0, 100.1);
    glVertex3f(20.0, 220.0, 100.1);
    glVertex3f(40.0, 220.0, 100.1);
    glVertex3f(40.0, 250.0, 100.1);
    glEnd();
       //jendela 5
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(50.0, 250.0, 100.1);
    glVertex3f(50.0, 220.0, 100.1);
    glVertex3f(70.0, 220.0, 100.1);
    glVertex3f(70.0, 250.0, 100.1);
    glEnd();

          //ke 6

     //jendela 1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-80.0, 200.0, 100.1);
    glVertex3f(-80.0, 170.0, 100.1);
    glVertex3f(-60.0, 170.0, 100.1);
    glVertex3f(-60.0, 200.0, 100.1);
    glEnd();
 //jendela 2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-50.0, 200.0, 100.1);
    glVertex3f(-50.0, 170.0, 100.1);
    glVertex3f(-30.0, 170.0, 100.1);
    glVertex3f(-30.0, 200.0, 100.1);
    glEnd();
    //jendela 3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-20.0, 200.0, 100.1);
    glVertex3f(-20.0, 170.0, 100.1);
    glVertex3f(10.0, 170.0, 100.1);
    glVertex3f(10.0, 200.0, 100.1);
    glEnd();
     //jendela 4
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(20.0, 200.0, 100.1);
    glVertex3f(20.0, 170.0, 100.1);
    glVertex3f(40.0, 170.0, 100.1);
    glVertex3f(40.0, 200.0, 100.1);
    glEnd();
       //jendela 5
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(50.0, 200.0, 100.1);
    glVertex3f(50.0, 170.0, 100.1);
    glVertex3f(70.0, 170.0, 100.1);
    glVertex3f(70.0, 200.0, 100.1);
    glEnd();



          //ke 7

     //jendela 1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-80.0, 150.0, 100.1);
    glVertex3f(-80.0, 120.0, 100.1);
    glVertex3f(-60.0, 120.0, 100.1);
    glVertex3f(-60.0, 150.0, 100.1);
    glEnd();
 //jendela 2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-50.0, 150.0, 100.1);
    glVertex3f(-50.0, 120.0, 100.1);
    glVertex3f(-30.0, 120.0, 100.1);
    glVertex3f(-30.0, 150.0, 100.1);
    glEnd();
    //jendela 3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-20.0, 150.0, 100.1);
    glVertex3f(-20.0, 120.0, 100.1);
    glVertex3f(10.0, 120.0, 100.1);
    glVertex3f(10.0, 150.0, 100.1);
    glEnd();
     //jendela 4
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(20.0, 150.0, 100.1);
    glVertex3f(20.0, 120.0, 100.1);
    glVertex3f(40.0, 120.0, 100.1);
    glVertex3f(40.0, 150.0, 100.1);
    glEnd();
       //jendela 5
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(50.0, 150.0, 100.1);
    glVertex3f(50.0, 120.0, 100.1);
    glVertex3f(70.0, 120.0, 100.1);
    glVertex3f(70.0, 150.0, 100.1);
    glEnd();

    //ke 8

     //jendela 1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-80.0, 100.0, 100.1);
    glVertex3f(-80.0, 70.0, 100.1);
    glVertex3f(-60.0, 70.0, 100.1);
    glVertex3f(-60.0, 100.0, 100.1);
    glEnd();
 //jendela 2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-50.0, 100.0, 100.1);
    glVertex3f(-50.0, 70.0, 100.1);
    glVertex3f(-30.0, 70.0, 100.1);
    glVertex3f(-30.0, 100.0, 100.1);
    glEnd();
    //jendela 3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-20.0, 100.0, 100.1);
    glVertex3f(-20.0, 70.0, 100.1);
    glVertex3f(10.0, 70.0, 100.1);
    glVertex3f(10.0, 100.0, 100.1);
    glEnd();
     //jendela 4
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(20.0, 100.0, 100.1);
    glVertex3f(20.0, 70.0, 100.1);
    glVertex3f(40.0, 70.0, 100.1);
    glVertex3f(40.0, 100.0, 100.1);
    glEnd();
       //jendela 5
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(50.0, 100.0, 100.1);
    glVertex3f(50.0, 70.0, 100.1);
    glVertex3f(70.0, 70.0, 100.1);
    glVertex3f(70.0, 100.0, 100.1);
    glEnd();

    //Pintu
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-10.0, -40.0, 100.1);
    glVertex3f(-10.0, 20.0, 100.1);
    glVertex3f(40.0, 20.0, 100.1);
    glVertex3f(40.0, -40.0, 100.1);
    glEnd();

    //Pintu Belakang
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-10.0, -45.0, -100.1);
    glVertex3f(-10.0, 20.0, -100.1);
    glVertex3f(40.0, 20.0, -100.1);
    glVertex3f(40.0, -45.0, -100.1);
    glEnd();
    //jendela 1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-80.0, 450.0, -91.1);
    glVertex3f(-80.0, 420.0, -91.1);
    glVertex3f(-60.0, 420.0, -91.1);
    glVertex3f(-60.0, 450.0, -91.1);
    glEnd();
 //jendela 2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-50.0, 450.0, -91.1);
    glVertex3f(-50.0, 420.0, -91.1);
    glVertex3f(-30.0, 420.0, -91.1);
    glVertex3f(-30.0, 450.0, -91.1);
    glEnd();
    //jendela 3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-20.0, 450.0, -91.1);
    glVertex3f(-20.0, 420.0, -91.1);
    glVertex3f(10.0, 420.0, -91.1);
    glVertex3f(10.0, 450.0, -91.1);
    glEnd();
     //jendela 4
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(20.0, 450.0, -91.1);
    glVertex3f(20.0, 420.0, -91.1);
    glVertex3f(40.0, 420.0, -91.1);
    glVertex3f(40.0, 450.0, -91.1);
    glEnd();
       //jendela 5
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(50.0, 450.0, -91.1);
    glVertex3f(50.0, 420.0, -91.1);
    glVertex3f(70.0, 420.0, -91.1);
    glVertex3f(70.0, 450.0, -91.1);
    glEnd();


//ke 2

     //jendela 1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-80.0, 400.0, -91.1);
    glVertex3f(-80.0, 370.0, -91.1);
    glVertex3f(-60.0, 370.0, -91.1);
    glVertex3f(-60.0, 400.0, -91.1);
    glEnd();
 //jendela 2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-50.0, 400.0, -91.1);
    glVertex3f(-50.0, 370.0, -91.1);
    glVertex3f(-30.0, 370.0, -91.1);
    glVertex3f(-30.0, 400.0, -91.1);
    glEnd();
    //jendela 3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-20.0, 400.0, -91.1);
    glVertex3f(-20.0, 370.0, -91.1);
    glVertex3f(10.0, 370.0, -91.1);
    glVertex3f(10.0, 400.0, -91.1);
    glEnd();
     //jendela 4
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(20.0, 400.0, -91.1);
    glVertex3f(20.0, 370.0, -91.1);
    glVertex3f(40.0, 370.0, -91.1);
    glVertex3f(40.0, 400.0, -91.1);
    glEnd();
       //jendela 5
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(50.0, 400.0, -91.1);
    glVertex3f(50.0, 370.0, -91.1);
    glVertex3f(70.0, 370.0, -91.1);
    glVertex3f(70.0, 400.0, -91.1);
    glEnd();

//ke 3

     //jendela 1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-80.0, 350.0, -91.1);
    glVertex3f(-80.0, 320.0, -91.1);
    glVertex3f(-60.0, 320.0, -91.1);
    glVertex3f(-60.0, 350.0, -91.1);
    glEnd();
 //jendela 2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-50.0, 350.0, -91.1);
    glVertex3f(-50.0, 320.0, -91.1);
    glVertex3f(-30.0, 320.0, -91.1);
    glVertex3f(-30.0, 350.0, -91.1);
    glEnd();
    //jendela 3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-20.0, 350.0, -91.1);
    glVertex3f(-20.0, 320.0, -91.1);
    glVertex3f(10.0, 320.0, -91.1);
    glVertex3f(10.0, 350.0, -91.1);
    glEnd();
     //jendela 4
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(20.0, 350.0, -91.1);
    glVertex3f(20.0, 320.0, -91.1);
    glVertex3f(40.0, 320.0, -91.1);
    glVertex3f(40.0, 350.0, -91.1);
    glEnd();
       //jendela 5
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(50.0, 350.0, -91.1);
    glVertex3f(50.0, 320.0, -91.1);
    glVertex3f(70.0, 320.0, -91.1);
    glVertex3f(70.0, 350.0, -91.1);
    glEnd();

    //ke 4

     //jendela 1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-80.0, 300.0, -91.1);
    glVertex3f(-80.0, 270.0, -91.1);
    glVertex3f(-60.0, 270.0, -91.1);
    glVertex3f(-60.0, 300.0, -91.1);
    glEnd();
 //jendela 2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-50.0, 300.0, -91.1);
    glVertex3f(-50.0, 270.0,    -91.1);
    glVertex3f(-30.0, 270.0, -91.1);
    glVertex3f(-30.0, 300.0, -91.1);
    glEnd();
    //jendela 3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-20.0, 300.0, -91.1);
    glVertex3f(-20.0, 270.0, -91.1);
    glVertex3f(10.0, 270.0, -91.1);
    glVertex3f(10.0, 300.0, -91.1);
    glEnd();
     //jendela 4
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(20.0, 300.0, -91.1);
    glVertex3f(20.0, 270.0, -91.1);
    glVertex3f(40.0, 270.0, -91.1);
    glVertex3f(40.0, 300.0, -91.1);
    glEnd();
       //jendela 5
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(50.0, 300.0, -91.1);
    glVertex3f(50.0, 270.0, -91.1);
    glVertex3f(70.0, 270.0, -91.1);
    glVertex3f(70.0, 300.0, -91.1);
    glEnd();

      //ke 5

     //jendela 1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-80.0, 250.0, -91.1);
    glVertex3f(-80.0, 220.0, -91.1);
    glVertex3f(-60.0, 220.0, -91.1);
    glVertex3f(-60.0, 250.0, -91.1);
    glEnd();
 //jendela 2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-50.0, 250.0, -91.1);
    glVertex3f(-50.0, 220.0, -91.1);
    glVertex3f(-30.0, 220.0, -91.1);
    glVertex3f(-30.0, 250.0, -91.1);
    glEnd();
    //jendela 3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-20.0, 250.0, -91.1);
    glVertex3f(-20.0, 220.0, -91.1);
    glVertex3f(10.0, 220.0, -91.1);
    glVertex3f(10.0, 250.0, -91.1);
    glEnd();
     //jendela 4
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(20.0, 250.0, -91.1);
    glVertex3f(20.0, 220.0, -91.1);
    glVertex3f(40.0, 220.0, -91.1);
    glVertex3f(40.0, 250.0, -91.1);
    glEnd();
       //jendela 5
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(50.0, 250.0, -91.1);
    glVertex3f(50.0, 220.0, -91.1);
    glVertex3f(70.0, 220.0, -91.1);
    glVertex3f(70.0, 250.0, -91.1);
    glEnd();

          //ke 6

     //jendela 1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-80.0, 200.0, -91.1);
    glVertex3f(-80.0, 170.0, -91.1);
    glVertex3f(-60.0, 170.0, -91.1);
    glVertex3f(-60.0, 200.0, -91.1);
    glEnd();
 //jendela 2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-50.0, 200.0, -91.1);
    glVertex3f(-50.0, 170.0, -91.1);
    glVertex3f(-30.0, 170.0, -91.1);
    glVertex3f(-30.0, 200.0, -91.1);
    glEnd();
    //jendela 3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-20.0, 200.0, -91.1);
    glVertex3f(-20.0, 170.0, -91.1);
    glVertex3f(10.0, 170.0, -91.1);
    glVertex3f(10.0, 200.0, -91.1);
    glEnd();
     //jendela 4
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(20.0, 200.0, -91.1);
    glVertex3f(20.0, 170.0, -91.1);
    glVertex3f(40.0, 170.0, -91.1);
    glVertex3f(40.0, 200.0, -91.1);
    glEnd();
       //jendela 5
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(50.0, 200.0, -91.1);
    glVertex3f(50.0, 170.0, -91.1);
    glVertex3f(70.0, 170.0, -91.1);
    glVertex3f(70.0, 200.0, -91.1);
    glEnd();



          //ke 7

     //jendela 1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-80.0, 150.0, -91.1);
    glVertex3f(-80.0, 120.0, -91.1);
    glVertex3f(-60.0, 120.0, -91.1);
    glVertex3f(-60.0, 150.0, -91.1);
    glEnd();
 //jendela 2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-50.0, 150.0, -91.1);
    glVertex3f(-50.0, 120.0, -91.1);
    glVertex3f(-30.0, 120.0, -91.1);
    glVertex3f(-30.0, 150.0, -91.1);
    glEnd();
    //jendela 3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-20.0, 150.0, -91.1);
    glVertex3f(-20.0, 120.0,-91.1);
    glVertex3f(10.0, 120.0, -91.1);
    glVertex3f(10.0, 150.0, -91.1);
    glEnd();
     //jendela 4
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(20.0, 150.0, -91.1);
    glVertex3f(20.0, 120.0, -91.1);
    glVertex3f(40.0, 120.0, -91.1);
    glVertex3f(40.0, 150.0, -91.1);
    glEnd();
       //jendela 5
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(50.0, 150.0, -91.1);
    glVertex3f(50.0, 120.0, -91.1);
    glVertex3f(70.0, 120.0, -91.1);
    glVertex3f(70.0, 150.0, -91.1);
    glEnd();

    //ke 8

     //jendela 1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-80.0, 100.0, -91.1);
    glVertex3f(-80.0, 70.0, -91.1);
    glVertex3f(-60.0, 70.0, -91.1);
    glVertex3f(-60.0, 100.0, -91.1);
    glEnd();
 //jendela 2
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-50.0, 100.0, -91.1);
    glVertex3f(-50.0, 70.0, -91.1);
    glVertex3f(-30.0, 70.0, -91.1);
    glVertex3f(-30.0, 100.0, -91.1);
    glEnd();
    //jendela 3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-20.0, 100.0, -91.1);
    glVertex3f(-20.0, 70.0, -91.1);
    glVertex3f(10.0, 70.0, -91.1);
    glVertex3f(10.0, 100.0, -91.1);
    glEnd();
     //jendela 4
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(20.0, 100.0, -91.1);
    glVertex3f(20.0, 70.0, -91.1);
    glVertex3f(40.0, 70.0, -91.1);
    glVertex3f(40.0, 100.0, -91.1);
    glEnd();
       //jendela 5
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(50.0, 100.0, -91.1);
    glVertex3f(50.0, 70.0, -91.1);
    glVertex3f(70.0, 70.0, -91.1);
    glVertex3f(70.0, 100.0, -91.1);
    glEnd();

  glPopMatrix();
    glutSwapBuffers();
}

void idle()
{
    if(!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouseMotion(int x,int y)
{
    if(mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}

void mouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void keyboard(unsigned char key, int x, int y){
switch (key)
    {
    case '1': //fungsi keyboard untuk melihat interior
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else{
        is_depth = 1;
        glEnable(GL_DEPTH_TEST);
        }
}
tampil();
}

void ukuran(int lebar, int tinggi)
{
	    if (tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(110.0, lebar / tinggi, 5.0, 1000.0);
    glTranslatef(0.0, -200.0, -600.0);
    glMatrixMode(GL_MODELVIEW);
}
