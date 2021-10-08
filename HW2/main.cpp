/*******************************************************
 * Homework 2: OpenGL                                  *
 *-----------------------------------------------------*
 * First, you should fill in problem1(), problem2(),   *
 * and problem3() as instructed in the written part of *
 * the problem set.  Then, express your creativity     *
 * with problem4()!                                    *
 *                                                     *
 * Note: you will only need to add/modify code where   *
 * it says "TODO".                                     *
 *                                                     *
 * The left mouse button rotates, the right mouse      *
 * button zooms, and the keyboard controls which       *
 * problem to display.                                 *
 *                                                     *
 * For Linux/OS X:                                     *
 * To compile your program, just type "make" at the    *
 * command line.  Typing "make clean" will remove all  *
 * computer-generated files.  Run by typing "./hw2"    *
 *                                                     *
 * For Visual Studio:                                  *
 * You can create a project with this main.cpp and     *
 * build and run the executable as you normally would. *
 *******************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#include "./freeglut-3.2.1/include/GL/freeglut.h"

using namespace std;

bool leftDown = false, rightDown = false;
int lastPos[2];
float cameraPos[4] = {0,1,4,1};
int windowWidth = 640, windowHeight = 480;
double yRot = 0;
int curProblem = 1; // TODO: change this number to try different examples

float specular[] = { 1.0, 1.0, 1.0, 1.0 };
float shininess[] = { 50.0 };

void problem1() {
  // this loop creates each teapot beginning with the rightmost one, rotating through counter clockwise
    for(int i = 0; i < 10; i++) {
      glutSolidTeapot(0.3);
      glTranslatef(-.25,0.75,0); // move into position for next teapot
      glRotatef(36,0,0,1.0); // rotate to proper angle for next teapot
    }
    glTranslatef(-1.25,0,0); // return to origin
}

void problem2() {
    for(int i = 1; i < 16; i++) {
      for(int j = 0; j < i; j++) {
        glutSolidCube(.3);
        glTranslatef(-.3,0,0); // shift horizontally to place next cube
      }
      glTranslatef(.3*i,-.1,0.0); // reset horizontal position and shift vertically for next row
    }
    glTranslatef(-1.9,0,0); 
}

void problem3() {
    for(int i = 0; i < 6; i++) {
      glTranslatef(-.4,-.4,0); // position next pyramid layer
      for(int j = 0; j < i+1; j++) {
        glutSolidTeapot(.2);
        glTranslatef(.8,0,0); // shift horizontally for each teapot in row
      }
      glTranslatef(-.8*(i+1),0,0.2); // reset horizontal position for next row
    }
    glTranslatef(2,1,0);
}

void problem4() {
// this function creates a 3-tier birthday bundt cake with chocolate shards decorating the sides and lit candles on the top

glPushMatrix();

  glRotatef(-90, 1.0, 0.0, 0.0);
  glutSolidTorus(0.8, 1.6, 20, 100); // bottom cake layer
  glTranslatef(0.0,0.0,1.0);
  glutSolidTorus(0.6, 1.2, 15, 75); // middle cake layer
  glTranslatef(0.0,0.0,0.8);
  glutSolidTorus(0.4, 0.8, 10, 50); // top cake layer

  glPushMatrix();

    glRotatef(90, 1.0, 0.0, 0.0);
    glTranslatef(0.55, 0.4, 0.6);

    // these loops draw the candles on top of the cake
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 10; j++) {
        glutSolidCube(.1);
        glTranslatef(0.25, 0.0, -0.45);
        glRotatef(36, 0.0, 1.0, 0.0);
      }
      glTranslatef(0.0, 0.08, 0.0);
    }

    glTranslatef(0.0, 0.04, 0.0);

    // add "flames" to the candles
    for (int i = 0; i < 10; i++) {
      glutSolidSphere(0.05, 50, 50);
      glTranslatef(0.25, 0.0, -0.45);
      glRotatef(36, 0.0, 1.0, 0.0);
    }
    
  glPopMatrix();

glPopMatrix();

// these triangles are the decorative chocolate shards sticking out of the second cake tier
glBegin(GL_TRIANGLES);

        glColor3f(  1.0,  0.0, 0.0);
        glVertex3f( 2.0, 2.0, 0.0);
        glColor3f(  0.0,  1.0, 0.0);
        glVertex3f( 1.0, 1.0, 0.0);
        glColor3f(  0.0,  0.0, 1.0);
        glVertex3f( -2.0,  0.0, 0.0);

        glColor3f(  1.0,  0.0, 0.0);
        glVertex3f(-2.0, 2.0, 0.0);
        glColor3f(  0.0,  1.0, 0.0);
        glVertex3f( -1.0, 1.0, 0.0);
        glColor3f(  0.0,  0.0, 1.0);
        glVertex3f( 2.0,  0.0, 0.0);

        glColor3f(  1.0,  0.0, 0.0);
        glVertex3f( 0.0, 2.0, 2.0);
        glColor3f(  0.0,  1.0, 0.0);
        glVertex3f( 0.0, 1.0, 1.0);
        glColor3f(  0.0,  0.0, 1.0);
        glVertex3f( 0.0,  0.0, -2.0);

        glColor3f(  1.0,  0.0, 0.0);
        glVertex3f( 0.0, 2.0, -2.0);
        glColor3f(  0.0,  1.0, 0.0);
        glVertex3f( 0.0, 1.0, -1.0);
        glColor3f(  0.0,  0.0, 1.0);
        glVertex3f( 0.0,  0.0, 2.0);

        glEnd();

}

void display() {
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glBegin(GL_LINES);
		glColor3f(1,0,0); glVertex3f(0,0,0); glVertex3f(1,0,0); // x axis
		glColor3f(0,1,0); glVertex3f(0,0,0); glVertex3f(0,1,0); // y axis
		glColor3f(0,0,1); glVertex3f(0,0,0); glVertex3f(0,0,1); // z axis
	glEnd(/*GL_LINES*/);

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glEnable(GL_LIGHT0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,windowWidth,windowHeight);

	float ratio = (float)windowWidth / (float)windowHeight;
	gluPerspective(50, ratio, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2], 0, 0, 0, 0, 1, 0);

	glLightfv(GL_LIGHT0, GL_POSITION, cameraPos);

	glRotatef(yRot,0,1,0);

	if (curProblem == 1) problem1();
	if (curProblem == 2) problem2();
	if (curProblem == 3) problem3();
	if (curProblem == 4) problem4();

	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) leftDown = (state == GLUT_DOWN);
	else if (button == GLUT_RIGHT_BUTTON) rightDown = (state == GLUT_DOWN);

	lastPos[0] = x;
	lastPos[1] = y;
}

void mouseMoved(int x, int y) {
	if (leftDown) yRot += (x - lastPos[0])*.1;
	if (rightDown) {
		for (int i = 0; i < 3; i++)
			cameraPos[i] *= pow(1.1,(y-lastPos[1])*.1);
	}


	lastPos[0] = x;
	lastPos[1] = y;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	curProblem = key-'0';
    if (key == 'q' || key == 'Q' || key == 27){
        exit(0);
    }
	glutPostRedisplay();
}

void reshape(int width, int height) {
	windowWidth = width;
	windowHeight = height;
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("HW2");

	glutDisplayFunc(display);
	glutMotionFunc(mouseMoved);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}
