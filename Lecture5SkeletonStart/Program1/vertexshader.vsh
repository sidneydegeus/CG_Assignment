#version 430 core

//uniform vec4 position;
//uniform vec4 color;

in vec4 position;
in vec4 color;

out vec4 vColor;

void main() {

	//gl_Position = vec4(0.0, 0.0, 0.5, 1.0);
//	gl_Position = vertices[gl_VertexID];
//	vColor = colors[gl_VertexID];
	gl_Position = position;
	vColor = color;
}