#ifndef INFO_H
#define INFO_H

#include <iostream>
#include <GL/freeglut.h>
#include <GL/glew.h>

void Info()
{
	std::cout << "Settings: " << glutGet(GLUT_VERSION) << std::endl;
	std::cout << "\tUsing freeglut " << glutGet(GLUT_VERSION) << std::endl;
	std::cout << "\tUsing glew " << glewGetString(GLEW_VERSION) << std::endl;
	std::cout << "\tVendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "\tRenderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "\tVersion: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "\tGLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}
#endif //INFO_H