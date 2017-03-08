#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glsl.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

const char * FSH = "fragmentshader.fsh";
const char * VSH = "vertexshader.vsh";

glm::vec4 blue = glm::vec4(0.0, 0.0, 0.4, 1.0);

void keyboard(unsigned char key, int x, int y);

void Render()
{
	//const glm::vec4 blue = glm::vec4(0.0, 0.0, 0.4, 1.0);
	glClearBufferfv(GL_COLOR, 0, glm::value_ptr(blue));

	glLineWidth(8.f);
	glDrawArrays(GL_LINE_LOOP, 0, 16);

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		case 'r':
			blue = glm::vec4(1.0, 0.4, 0.0, 0.0);
			break;
		case 's':

			break;

		default:
			break;
	}
	glutPostRedisplay();
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
	
	glUseProgram(shaderID);
	#pragma endregion

	glutKeyboardFunc(keyboard);
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);

	glutMainLoop();

	return 0;
}