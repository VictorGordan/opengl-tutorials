#version 330 core

// Positions/Coordinates
layout (location = 0) in vec3 aPos;
// Normals (not necessarily normalized)
layout (location = 1) in vec3 aNormal;
// Colors
layout (location = 2) in vec3 aColor;
// Texture Coordinates
layout (location = 3) in vec2 aTex;


out DATA
{
    vec3 Normal;
	vec3 color;
	vec2 texCoord;
    mat4 projection;
} data_out;



// Imports the camera matrix
uniform mat4 camMatrix;
// Imports the transformation matrices
uniform mat4 model;
uniform mat4 translation;
uniform mat4 rotation;
uniform mat4 scale;

// translation on the y-axis by -1.0
// then mirror on the x-axis
const mat3 coordinateCorrectionMatrix = mat3(vec3(1.0, 0.0, 0.0),
                                             vec3(0.0,-1.0, 0.0),
                                             vec3(0.0, 1.0, 1.0));
void main()
{
	gl_Position = model * translation * rotation * scale * vec4(aPos, 1.0f);
	data_out.Normal = aNormal;
	data_out.color = aColor;
	data_out.texCoord = vec2(coordinateCorrectionMatrix * vec3(aTex, 1.0));
	data_out.projection = camMatrix;
}
