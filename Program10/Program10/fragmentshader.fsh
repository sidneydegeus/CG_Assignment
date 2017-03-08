#version 330 core


in VS_OUT
{
    vec4 color;
} vs;

out vec4 color;

void main()
{
  color = vs.color;
}