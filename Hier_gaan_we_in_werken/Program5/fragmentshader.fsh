#version 430 core


in vec4 s_color;
out vec4 color;

void main()
{
    //color = vec4(0.0, 1.0, 1.0, 1.0);
    color = s_color;
}