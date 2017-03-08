#version 430 core

out vec4 s_color;

void main()
{
	const vec4 vertices[] = vec4[]
		(
			vec4(0.0, 0.4, 0.0, 1.0),
			vec4(-0.1, 0.2, 0.0, 1.0),
			vec4(-0.2, 0.2, 0.0, 1.0),
			vec4(-0.2, 0.1, 0.0, 1.0),
			vec4(-0.4, 0.0, 0.0, 1.0),
			vec4(-0.2, -0.1, 0.0, 1.0),
			vec4(-0.2, -0.2, 0.0, 1.0),
			vec4(-0.1, -0.2, 0.0, 1.0),
			vec4(0.0, -0.4, 0.0, 1.0),
			vec4(0.1, -0.2, 0.0, 1.0),
			vec4(0.2, -0.2, 0.0, 1.0),
			vec4(0.2, -0.1, 0.0, 1.0),
			vec4(0.4, 0.0, 0.0, 1.0),
			vec4(0.2, 0.1, 0.0, 1.0),
			vec4(0.2, 0.2, 0.0, 1.0),
			vec4(0.1, 0.2, 0.0, 1.0),
			vec4(0.0, 0.4, 0.0, 1.0)



			);

	const vec4 colors[] = vec4[]
		(
			vec4(1.0f, 0.0f, 0.0f, 1.0f),
			vec4(0.0f, 1.0f, 0.0f, 1.0f),
			vec4(0.0f, 0.0f, 1.0f, 1.0f),
			vec4(0.0f, 0.0f, 1.0f, 1.0f),
			vec4(0.0f, 0.0f, 1.0f, 1.0f),
			vec4(0.0f, 0.0f, 1.0f, 1.0f),
			vec4(0.0f, 0.0f, 1.0f, 1.0f),
			vec4(0.0f, 0.0f, 1.0f, 1.0f),
			vec4(0.0f, 0.0f, 1.0f, 1.0f),
			vec4(0.0f, 0.0f, 1.0f, 1.0f)
			);

	gl_Position = vertices[gl_VertexID];

	s_color = colors[gl_VertexID];
}