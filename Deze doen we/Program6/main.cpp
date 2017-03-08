#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "glsl.h"

using namespace std;

const char * FSH = "fragmentshader.fsh";
const char * VSH = "vertexshader.vsh";

GLuint shaderID;

GLuint vbo1, vbo2, vao;

void keyboard(unsigned char key, int x, int y);

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

		break;
	case 's':
		break;

	default:
		break;
	}
	glutPostRedisplay();
}

void Render()
{
	const glm::vec4 blue = glm::vec4(0.0f, 0.0f, 0.4f, 1.0f);
	glClearBufferfv(GL_COLOR, 0, glm::value_ptr(blue));

	//placeholder begin
	glBindBuffer(GL_ARRAY_BUFFER, vbo1);
	GLuint positionID = glGetAttribLocation(shaderID, "position");
	glVertexAttribPointer(positionID, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(positionID);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

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

	glutDisplayFunc(Render);

	glewInit();

	#pragma region << * * * * * * Shader Stuff * * * * * >>
	char * fragshader = glsl::readFile(FSH);
	GLuint fshID = glsl::makeFragmentShader(fragshader);

	char * vertexshader = glsl::readFile(VSH);
	GLuint vshID = glsl::makeVertexShader(vertexshader);

	shaderID = glsl::makeShaderProgram(vshID, fshID);
	
	#pragma endregion

#pragma region << * * * * * * Buffer Stuff * * * * * >>

	glGenBuffers(1, &vbo1);															
	glBindBuffer(GL_ARRAY_BUFFER, vbo1);											
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);		
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &vbo2);															
	glBindBuffer(GL_ARRAY_BUFFER, vbo2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


	//glGenVertexArrays(1, &vao);													
	//glBindVertexArray(vao);														
	
	//place holder

	//glBindVertexArray(0);															

	glUseProgram(shaderID);
#pragma endregion

	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);
	glutKeyboardFunc(keyboard);
	glutMainLoop();

	return 0;
}