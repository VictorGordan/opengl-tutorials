#version 330 core
in vec4 FragPos;

uniform vec3 lightPos;
uniform float farPlane;

void main()
{
    // Manually sets depth map in the range [0, 1]
    gl_FragDepth = length(FragPos.xyz - lightPos) / farPlane;
}