#version 430 core
in vec4 vColor;
out vec4 color;

void main() {
	//color = vec4(1.0, 1.0, 0.0, 1.0);
	color = vColor;
}