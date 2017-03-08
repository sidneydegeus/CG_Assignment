#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glsl.h"
#include <glm/glm.hpp>

using namespace std;

const char * FSH = "fragmentshader.fsh";
const char * VSH = "vertexshader.vsh";

//struct Vector
//{
//	float x, y, z, w;
//};
//
//struct Color
//{
//	float r, g, b, a;
//};

struct VertexFormat
{
	glm::vec4 position;
	glm::vec4 color;

	VertexFormat(glm::vec4 &pos, glm::vec4 &col)
	{
		position = pos;
		color = col;
	}
};

VertexFormat tri[] =
{
	VertexFormat(glm::vec4(0.5f, -0.5f, 0.0f, 1.0f),  glm::vec4(1.0f, 0.0f, 0.0f, 1.0f)),
	VertexFormat(glm::vec4(-0.5f, -0.5f, 0.0f, 1.0f), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)),
	VertexFormat(glm::vec4(0.0f, 0.5, 0.0f, 1.0f),    glm::vec4(0.0f, 0.0f, 1.0f, 1.0f))
};

GLuint vao, vbo;
GLuint positionID;
GLuint colorID;
float f = 0.5f;
unsigned const int DELTA = 10;
bool up = true;

void Render()
{
	static const GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
	glClearBufferfv(GL_COLOR, 0, black);

	glBindVertexArray(vao); //use vao
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0); //release vao

	glutSwapBuffers();

	if (up)
	{
		if (f >= 1.0f)
			up = false;
		f += 0.01f;
	}
	else
	{
		if (f <= -0.5f)
			up = true;
		f -= 0.01;
	}

	glm::vec4 v = glm::vec4(0.0f, f, 0.0f, 1.0f);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);											//bind to type
	glBufferSubData(GL_ARRAY_BUFFER, 4 * sizeof(glm::vec4), sizeof(glm::vec4), &v);
	glBindBuffer(GL_ARRAY_BUFFER, 0);											//bind to type

	//glutPostRedisplay();
}

void Render(int n)
{
	Render();
	glutTimerFunc(DELTA, Render, 0);
	//glutPostRedisplay();
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

	GLuint shaderID = glsl::makeShaderProgram(vshID, fshID);
	
	#pragma region << * * * * * * Buffer Stuff * * * * * >>
	
	glGenBuffers(1, &vbo);															//create vbo for position
	glBindBuffer(GL_ARRAY_BUFFER, vbo);											//bind to type
	glBufferData(GL_ARRAY_BUFFER, sizeof(tri), tri, GL_STATIC_DRAW);		//create buffer and fill with data
	
	
	glGenVertexArrays(1, &vao);														//create vao id
	glBindVertexArray(vao);															//create vao	
	glBindBuffer(GL_ARRAY_BUFFER, vbo);											//bind vbo1 to vao
	positionID = glGetAttribLocation(shaderID, "pos");								//get id's of shader attribute
	glVertexAttribPointer(positionID, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), 0);					//set pointer to start of vbo1
	glEnableVertexAttribArray(positionID);											//assign attribute to pointer of vbo1

	colorID = glGetAttribLocation(shaderID, "col");
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(sizeof(glm::vec4)));
	glEnableVertexAttribArray(colorID);

	glBindBuffer(GL_ARRAY_BUFFER, 0);												//binding buffers is done

	glBindVertexArray(0);

	glUseProgram(shaderID);
	glDeleteProgram(shaderID);
	#pragma endregion
	#pragma endregion

	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);

	glutTimerFunc(DELTA, Render, 0);

	//glutMainLoopEvent();
	glutMainLoop();

	return 0;
}