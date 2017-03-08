#version 430 core

in vec4 pos;
in vec4 col;

out VS_OUT
{
    vec4 color;
} vs;

void main()
{
    gl_Position = pos;
    vs.color = col;
}


