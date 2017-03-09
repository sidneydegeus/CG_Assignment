//Made by Jordan Munk & Sidney de Geus

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "glsl.h"

using namespace std;
void initRendering();
void drawScene();
void handleResize(int w, int h);
void changeRotate(int value);
void changeScale(int value);
void changeTransition(int value);
void specialInput(int key, int x, int y);

const char * FSH = "fragmentshader.fsh";
const char * VSH = "vertexshader.vsh";

GLuint shaderID;
GLuint vbo1, vbo2, vao;

float angle = 0.0;
float cameraAngle = 0.0;
float scale = 1.0;
float transitionX = 0.0;
float transitionY = 0.0;

void specialInput(int key, int x, int y)
{
	switch (key) {
		case GLUT_KEY_UP:
			changeTransition(0);
			break;
		case GLUT_KEY_DOWN:
			changeTransition(1);
			break;
		case GLUT_KEY_LEFT:
			changeRotate(0);
			break;
		case GLUT_KEY_RIGHT:
			changeRotate(1);
			break;
		case GLUT_KEY_PAGE_UP:
			changeScale(0);
			break;
		case GLUT_KEY_PAGE_DOWN:
			changeScale(1);
			break;
	}
	glutPostRedisplay();
}

void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glScalef(scale, scale, 1.0f);
	glTranslatef(transitionX, transitionY, -5.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f); //rotating object continuously by 2 degree

	glLineWidth(3);
	glBegin(GL_LINE_LOOP);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0, 0.4, 0.0);
	glVertex3f(-0.1, 0.2, 0.0);
	glVertex3f(-0.2, 0.2, 0.0);
	glVertex3f(-0.2, 0.1, 0.0);

	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(-0.4, 0.0, 0.0);
	glVertex3f(-0.2, -0.1, 0.0);
	glVertex3f(-0.2, -0.2, 0.0);
	glVertex3f(-0.1, -0.2, 0.0);

	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0, -0.4, 0.0);
	glVertex3f(0.1, -0.2, 0.0);
	glVertex3f(0.2, -0.2, 0.0);
	glVertex3f(0.2, -0.1, 0.0);

	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.4, 0.0, 0.0);
	glVertex3f(0.2, 0.1, 0.0);
	glVertex3f(0.2, 0.2, 0.0);
	glVertex3f(0.1, 0.2, 0.0);

	glEnd();

	glPopMatrix();
	glutSwapBuffers();
}

void changeRotate(int value) {
	if (value == 0)
		angle += 2.0f;
	else
		angle -= 2.0f;

	if (angle>360.f)
	{
		angle -= 360;
	}
	glutPostRedisplay();
}

void changeScale(int value) {
	if (value == 0)
		scale += 0.01;
	else
		scale -= 0.01;

	glutPostRedisplay();
}

void changeTransition(int value) {
	if (value == 0) 
		transitionX += 0.01;
	else 
		transitionY += 0.01;

	glutPostRedisplay();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 600);

	glutCreateWindow("Hello OpenGL");
	initRendering();

	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);

	glutDisplayFunc(drawScene);
	glutSpecialFunc(specialInput);
	glutReshapeFunc(handleResize);

	glutMainLoop();

	return 0;
}