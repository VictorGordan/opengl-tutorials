#version 330 core

layout (location = 0) in vec3 aPos;
// Have this if using the second method showed in the tutorial
//layout (location = 1) in vec3 aNormal;


uniform mat4 camMatrix;
uniform mat4 model;
uniform mat4 translation;
uniform mat4 rotation;
uniform mat4 scale;
// Have this uniform if using the first or second methods showed in the tutorial
// uniform float outlining;

void main()
{
	// First Method
	//vec3 crntPos = vec3(model * translation * rotation * scale * outlining * vec4(aPos, 1.0f));
	//gl_Position = camMatrix * vec4(crntPos, 1.0);

	// Second Method
	//vec3 crntPos = vec3(model * translation * rotation * scale * vec4(aPos + aNormal * outlining, 1.0f));
	//gl_Position = camMatrix * vec4(crntPos, 1.0);

	// Third Method
	vec3 crntPos = vec3(model * translation * rotation * scale * vec4(aPos, 1.0f));
	gl_Position = camMatrix * vec4(crntPos, 1.0);
}