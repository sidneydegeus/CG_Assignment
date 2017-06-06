#version 430 core

in vec4 position;
in vec4 color;

out vec4 s_color;

void main()
{
	s_color = color;
    gl_Position = position;
}