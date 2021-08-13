#version 330 core

out vec4 FragColor;
in vec2 texCoords;

uniform sampler2D screenTexture;
uniform sampler2D bloomTexture;
uniform float gamma;

void main()
{
    vec3 fragment = texture(screenTexture, texCoords).rgb;
    vec3 bloom = texture(bloomTexture, texCoords).rgb;

    vec3 color = fragment + bloom;

    float exposure = 0.8f;
    vec3 toneMapped = vec3(1.0f) - exp(-color * exposure);

    FragColor.rgb = pow(toneMapped, vec3(1.0f / gamma));
}