#include "camera.hpp"





float radians(float degrees)
{
	return degrees * PI / 180.0f;
}
float degrees(float radians)
{
	return radians * 180.0f / PI;
}



mat4 perspective(float fov, float aspectRatio, float near, float far)
{
	float x = (near * (1.0f - cos(fov))) / sin(fov);
	float y = x / aspectRatio;
	float div = -1.0f / (far - near);
	return mat4
	(
		near / x,       0.0f,               0.0f,            0.0f,
		  0.0f,      near / y ,             0.0f,            0.0f,
		  0.0f,         0.0f,       div * (far + near),     -1.0f,
		  0.0f,         0.0f,      2 * div * far * near,     0.0f
	);
}

mat4 lookAt(vec3 eye, vec3 target, vec3 up)
{
	vec3 forward = norm(target - eye);
	vec3 right = norm(cross(forward, up));
	vec3 upVec = norm(cross(right, forward));

	return mat4
	(
		     right.x,          upVec.x,        -forward.x,     0.0f,
		     right.y,          upVec.y,        -forward.y,     0.0f,
		     right.z,          upVec.z,        -forward.z,     0.0f,
		-dot(right, eye), -dot(upVec, eye), dot(forward, eye), 1.0f
	);
}