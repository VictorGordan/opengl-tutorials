#include<iostream>

#include"glad/glad.h"
#include"GLFW/glfw3.h"



const unsigned int SCREEN_WIDTH = 1024;
const unsigned int SCREEN_HEIGHT = 1024;

const unsigned short OPENGL_MAJOR_VERSION = 4;
const unsigned short OPENGL_MINOR_VERSION = 6;

bool vSync = true;


const char* screenVertexShaderSource = R"(#version 460 core
const vec4 vertexData[4] =
{
    //    Positions    UVs
    vec4( -1.0, -1.0,  0.0, 0.0),
    vec4(  1.0, -1.0,  1.0, 0.0),
    vec4(  1.0,  1.0,  1.0, 1.0),
    vec4( -1.0,  1.0,  0.0, 1.0)
};
out vec2 UVs;
void main()
{
	vec4 vertex = vertexData[gl_VertexID];
	gl_Position = vec4(vertex.xy, 0.0, 1.0);
	UVs = vertex.zw;
})";
const char* screenFragmentShaderSource = R"(#version 460 core
out vec4 FragColor;
layout(binding = 0) uniform sampler2D screen;
in vec2 UVs;
void main()
{
	FragColor = texture(screen, UVs);
})";
const char* screenComputeShaderSource = R"(#version 460 core
layout(local_size_x = 8, local_size_y = 4, local_size_z = 1) in;

// Using the restrict qualifier we promise OpenGL that this is the only variable through
// which we modify the memory represented by it which "...allows the compiler to optimize reads/writes better."
layout(rgba32f, binding = 0) restrict writeonly uniform image2D screen;

void main()
{
	vec4 pixel = vec4(0.075, 0.133, 0.173, 1.0);
	ivec2 pixel_coords = ivec2(gl_GlobalInvocationID.xy);
	
	ivec2 dims = imageSize(screen);
	
	// The OpenGL pixel center is defined to be offseted from the lower left corner by (0.5, 0.5)
	// this is why we add 0.5
	vec2 ndc = (pixel_coords + 0.5) / dims * 2.0 - 1.0; // transforms to [-1.0, 1.0]

	float fov = 90.0;
	vec3 cam_o = vec3(0.0, 0.0, -tan(fov / 2.0));
	vec3 ray_o = vec3(ndc, 0.0);
	vec3 ray_d = normalize(ray_o - cam_o);

	vec3 sphere_c = vec3(0.0, 0.0, -5.0);
	float sphere_r = 1.0;

	vec3 o_c = ray_o - sphere_c;
	float b = dot(ray_d, o_c);
	float c = dot(o_c, o_c) - sphere_r * sphere_r;
	float intersectionState = b * b - c;
	vec3 intersection = ray_o + ray_d * (-b + sqrt(b * b - c));

	if (intersectionState >= 0.0)
	{
		pixel = vec4((normalize(intersection - sphere_c) + 1.0) / 2.0, 1.0);
	}

	imageStore(screen, pixel_coords, pixel);
})";


int main()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_MAJOR_VERSION);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_MINOR_VERSION);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "OpenGL Compute Shaders", NULL, NULL);
	if (!window)
	{
		std::cout << "Failed to create the GLFW window\n";
		glfwTerminate();
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(vSync);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize OpenGL context" << std::endl;
	}

	GLuint screenTex;
	glCreateTextures(GL_TEXTURE_2D, 1, &screenTex);
	glTextureParameteri(screenTex, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTextureParameteri(screenTex, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTextureParameteri(screenTex, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTextureParameteri(screenTex, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTextureStorage2D(screenTex, 1, GL_RGBA32F, SCREEN_WIDTH, SCREEN_HEIGHT);

	GLuint screenVertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(screenVertexShader, 1, &screenVertexShaderSource, NULL);
	glCompileShader(screenVertexShader);
	GLuint screenFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(screenFragmentShader, 1, &screenFragmentShaderSource, NULL);
	glCompileShader(screenFragmentShader);

	GLuint screenShaderProgram = glCreateProgram();
	glAttachShader(screenShaderProgram, screenVertexShader);
	glAttachShader(screenShaderProgram, screenFragmentShader);
	glLinkProgram(screenShaderProgram);

	glDeleteShader(screenVertexShader);
	glDeleteShader(screenFragmentShader);


	GLuint computeShader = glCreateShader(GL_COMPUTE_SHADER);
	glShaderSource(computeShader, 1, &screenComputeShaderSource, NULL);
	glCompileShader(computeShader);

	GLuint computeProgram = glCreateProgram();
	glAttachShader(computeProgram, computeShader);
	glLinkProgram(computeProgram);

	glDeleteShader(computeShader);


	int work_grp_cnt[3];
	glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 0, &work_grp_cnt[0]);
	glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 1, &work_grp_cnt[1]);
	glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 2, &work_grp_cnt[2]);
	std::cout << "Max work groups per compute shader" << 
		" x:" << work_grp_cnt[0] <<
		" y:" << work_grp_cnt[1] <<
		" z:" << work_grp_cnt[2] << "\n";

	int work_grp_size[3];
	glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 0, &work_grp_size[0]);
	glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 1, &work_grp_size[1]);
	glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 2, &work_grp_size[2]);
	std::cout << "Max work group sizes" <<
		" x:" << work_grp_size[0] <<
		" y:" << work_grp_size[1] <<
		" z:" << work_grp_size[2] << "\n";

	int work_grp_inv;
	glGetIntegerv(GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS, &work_grp_inv);
	std::cout << "Max invocations count per work group: " << work_grp_inv << "\n";


	while (!glfwWindowShouldClose(window))
	{
		glUseProgram(computeProgram);
		glBindImageTexture(0, screenTex, 0, GL_FALSE, 0, GL_WRITE_ONLY, GL_RGBA32F);
		glDispatchCompute(ceil(SCREEN_WIDTH / 8), ceil(SCREEN_HEIGHT / 4), 1);
		// The ressource the compute shader wrote to (an image) will later be used to make texture fetches from.
		// Therefore use GL_TEXTURE_FETCH_BARRIER_BIT as the appropriate barrier to insure said writes will be visible.
		glMemoryBarrier(GL_TEXTURE_FETCH_BARRIER_BIT);

		glUseProgram(screenShaderProgram);
		glBindTextureUnit(0, screenTex);
		glDrawArrays(GL_QUADS, 0, 4);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}


	glfwDestroyWindow(window);
	glfwTerminate();
}