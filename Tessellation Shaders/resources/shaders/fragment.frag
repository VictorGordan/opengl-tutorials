#version 460 core

out vec4 FragColor;
in vec2 uvs;

uniform sampler2D screen;

void main()
{
	//FragColor = vec4(0.965, 0.318, 0.000, 1.0);
	FragColor = vec4(uvs + 1.0, 0.000, 1.0)/2.0;
}