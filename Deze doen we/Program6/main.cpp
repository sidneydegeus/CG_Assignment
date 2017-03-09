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
void update(int value);
void keyboard(unsigned char key, int x, int y);

const char * FSH = "fragmentshader.fsh";
const char * VSH = "vertexshader.vsh";

GLuint shaderID;
GLuint vbo1, vbo2, vao;

float angle = 0.0;
float cameraAngle = 0.0;

const GLfloat vertices[] = 
{
	0.0, 0.4, 0.0, 1.0,
	-0.1, 0.2, 0.0, 1.0,
	-0.2, 0.2, 0.0, 1.0,
	-0.2, 0.1, 0.0, 1.0,
	-0.4, 0.0, 0.0, 1.0,
	-0.2, -0.1, 0.0, 1.0,
	-0.2, -0.2, 0.0, 1.0,
	-0.1, -0.2, 0.0, 1.0,
	0.0, -0.4, 0.0, 1.0,
	0.1, -0.2, 0.0, 1.0,
	0.2, -0.2, 0.0, 1.0,
	0.2, -0.1, 0.0, 1.0,
	0.4, 0.0, 0.0, 1.0,
	0.2, 0.1, 0.0, 1.0,
	0.2, 0.2, 0.0, 1.0,
	0.1, 0.2, 0.0, 1.0,
	0.0, 0.4, 0.0, 1.0
};

const GLfloat colors[] =
{
	1.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f
};

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'r':
		update(0);
		break;
	case 's':
		break;
	case 27:
		exit(0);
		break;
	default:
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
	glScalef(0.8f, 0.8f, 0.8f);
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(angle, 0.0f, 0.0f, 1.0f); //rotating object continuously by 2 degree

	glBegin(GL_QUADS);

	glVertex3f(-0.7f, 0.0f, 0.0);
	glVertex3f(0.7f, 0.0f, 0.0);
	glVertex3f(0.5f, 2.0f, 0.0);
	glVertex3f(-0.5f, 2.0f, 0.0);

	glEnd();

	glPopMatrix();
	glutSwapBuffers();
}

void update(int value) {
	angle += 2.0f;
	if (angle>360.f)
	{
		angle -= 360;
	}
	glutPostRedisplay();
	//glutTimerFunc(25, update, 0);
}

void Render()
{

	const glm::vec4 blue = glm::vec4(0.0f, 0.0f, 0.4f, 1.0f);
	glClearBufferfv(GL_COLOR, 0, glm::value_ptr(blue));

	glLoadIdentity();
	glRotatef(cameraAngle, 1.0f, 0.0f, 0.0f); //rotate object by 30 degree with respect to y-axis
	glTranslatef(0.0f, 0.0f, -10.0f);



	//placeholder begin
	glBindBuffer(GL_ARRAY_BUFFER, vbo1);
	GLuint positionID = glGetAttribLocation(shaderID, "position");
	glVertexAttribPointer(positionID, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(positionID);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glTranslatef(5.0f, -1.0f, 0.0f);
	glScalef(2.0f, 2.0f, 2.0f);
	glRotatef(angle, 1.0f, 0.0f, 0.0f); //rotating object continuously by 2 degree

	glBindBuffer(GL_ARRAY_BUFFER, vbo2);
	GLuint colorID = glGetAttribLocation(shaderID, "color");
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(colorID);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	//placeholder end

	//glBindVertexArray(vao);
	glLineWidth(8.f);

	glDrawArrays(GL_LINE_LOOP, 0, 16);
	//glBindVertexArray(0);

	
	glDisableVertexAttribArray(positionID); //!!
	glDisableVertexAttribArray(colorID);	//!!

	glutSwapBuffers();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(800, 600);

	glutCreateWindow("Hello OpenGL");
	initRendering();

	//glutDisplayFunc(Render);
//
//	glewInit();
//
//	#pragma region << * * * * * * Shader Stuff * * * * * >>
//	char * fragshader = glsl::readFile(FSH);
//	GLuint fshID = glsl::makeFragmentShader(fragshader);
//
//	char * vertexshader = glsl::readFile(VSH);
//	GLuint vshID = glsl::makeVertexShader(vertexshader);
//
//	shaderID = glsl::makeShaderProgram(vshID, fshID);
//	
//	#pragma endregion
//
//#pragma region << * * * * * * Buffer Stuff * * * * * >>
//
//	glGenBuffers(1, &vbo1);															
//	glBindBuffer(GL_ARRAY_BUFFER, vbo1);											
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);		
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//	glGenBuffers(1, &vbo2);															
//	glBindBuffer(GL_ARRAY_BUFFER, vbo2);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//
//	//glGenVertexArrays(1, &vao);													
//	//glBindVertexArray(vao);														
//	
//	//place holder
//
//	//glBindVertexArray(0);															
//
//	glUseProgram(shaderID);
//#pragma endregion
//
//	HWND hWnd = GetConsoleWindow();
//	ShowWindow(hWnd, SW_HIDE);

	glutDisplayFunc(drawScene);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(handleResize);

	//glutTimerFunc(25, update, 0);
	//this call the function update in every 25 millsecond
	//so value of angle of rotation change and object rotates continuously

	glutMainLoop();

	return 0;
}