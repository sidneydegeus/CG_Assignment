#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "glsl.h"

using namespace std;

bool* keyStates = new bool[256]; // Create an array of boolean values of length 256 (0-255)  
const char *FSH = "fragmentshader.fsh";
const char *VSH = "vertexshader.vsh";

const GLfloat vertices[] =
{
	0.5, -0.5, 0.0, 1.0,
	-0.5, -0.5, 0.0, 1.0,
	0.0, 0.5, 0.0, 1.0
};

const GLfloat colors[] =
{
	1.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f
};


GLuint shaderID;
GLuint vbo1, vbo2;

void keyOperations(void) {
	if (keyStates['a']) { // If the 'a' key has been pressed  
		cout << "test";			  // Perform 'a' key operations  
	}
}

void keyPressed(unsigned char key, int x, int y) {
	keyStates[key] = true; // Set the state of the current key to pressed  
}

void keyUp(unsigned char key, int x, int y) {
	keyStates[key] = false; // Set the state of the current key to not pressed  
}

void Render()
{
	keyOperations();
	static const GLfloat blue[] = { 0.0, 0.0, 0.4, 1.0 };
	glClearBufferfv(GL_COLOR, 0, blue);
	
	glUseProgram(shaderID);

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

	//glm::vec4 position = glm::vec4(0.0f, 0.0f, 0.5f, 1.0f);
	//GLuint positionID = glGetUniformLocation(shaderID, "position");
	//glUniform4fv(positionID, 1, glm::value_ptr(position));

	//glm::vec4 color = glm::vec4(1.0f, -0.0f, 0.0f, 1.0f);
	//GLuint colorID = glGetUniformLocation(shaderID, "color");
	//glUniform4fv(colorID, 1, glm::value_ptr(color));

	//glPointSize(40.0f);

	glDrawArrays(GL_TRIANGLES, 0, 3);


	//glBegin(GL_TRIANGLES);

	//glColor3f(1.0, 1.0, 0.0);
	//glVertex2f(-0.5, -0.5);

	//glColor3f(1.0, 0.0, 0.0);
	//glVertex2f(0.5, -0.5);

	//glColor3f(0.0, 0.0, 1.0);
	//glVertex2f(0, 0.5);

	//glEnd();
	glutSwapBuffers();
}

int main(int argc, char ** argv)
{
	#pragma region << * * * * * * Setup GLut & GLew * * * * * >>

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA);

	glutInitWindowSize(800, 600);

	glutCreateWindow("Hello OpenGL");

	glutDisplayFunc(Render);

	glutKeyboardFunc(keyPressed); // Tell GLUT to use the method "keyPressed" for key presses 

	glutKeyboardUpFunc(keyUp); // Tell GLUT to use the method "keyUp" for key up events  

	glewInit();

	

#pragma endregion

	#pragma region << * * * * * * Shader Stuff * * * * * >>

	char *fragmentshader = glsl::readFile(FSH);
	GLuint fshID = glsl::makeFragmentShader(fragmentshader);

	char *vertexshader = glsl::readFile(VSH);
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

#pragma endregion

	#pragma region << * * * * * * Start GameLoop * * * * * >>
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);

	glutMainLoop();
#pragma endregion
	return 0;
}