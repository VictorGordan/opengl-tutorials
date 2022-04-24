#include "transformations.hpp"





mat4 translation(float x, float y, float z)
{
	return mat4
	(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		 x,    y,    z,   1.0f
	);
}
mat4 translation(vec3 translation)
{
	return mat4
	(
		     1.0f,          0.0f,          0.0f,     0.0f,
		     0.0f,          1.0f,          0.0f,     0.0f,
		     0.0f,          0.0f,          1.0f,     0.0f,
		translation.x, translation.y, translation.z, 1.0f
	);
}

mat4 rotation(float X, float Y, float Z)
{
	mat4 aroundX = mat4(
		1.0f,   0.0f,    0.0f,  0.0f,
		0.0f,  cos(X),  sin(X), 0.0f,
		0.0f, -sin(X),  cos(X), 0.0f,
		0.0f,   0.0f,    0.0f,  1.0f
	);
	mat4 aroundY = mat4(
		cos(Y), 0.0f, -sin(Y), 0.0f,
		 0.0f,  1.0f,   0.0f,  0.0f,
		sin(Y), 0.0f,  cos(Y), 0.0f,
		 0.0f,  0.0f,   0.0f,  1.0f
	);
	mat4 aroundZ = mat4(
		 cos(Z),  sin(Z), 0.0f, 0.0f,
		-sin(Z),  cos(Z), 0.0f, 0.0f,
		  0.0f,    0.0f,  1.0f, 0.0f,
		  0.0f,    0.0f,  0.0f, 1.0f
	);

	return aroundZ * aroundY * aroundX;
}
mat4 rotation(vec3 rotation)
{
	mat4 aroundX = mat4(
		1.0f,        0.0f,             0.0f,      0.0f,
		0.0f,  cos(rotation.x),  sin(rotation.x), 0.0f,
		0.0f, -sin(rotation.x),  cos(rotation.x), 0.0f,
		0.0f,        0.0f,             0.0f,      1.0f
	);
	mat4 aroundY = mat4(
		cos(rotation.y), 0.0f, -sin(rotation.y), 0.0f,
		      0.0f,      1.0f,        0.0f,      0.0f,
		sin(rotation.y), 0.0f,  cos(rotation.y), 0.0f,
		      0.0f,      0.0f,        0.0f,      1.0f
	);
	mat4 aroundZ = mat4(
		 cos(rotation.z), sin(rotation.z), 0.0f, 0.0f,
		-sin(rotation.z), cos(rotation.z), 0.0f, 0.0f,
		       0.0f,            0.0f,      1.0f, 0.0f,
		       0.0f,            0.0f,      0.0f, 1.0f
	);

	return aroundZ * aroundY * aroundX;
}

mat4 scale(float x, float y, float z)
{
	return mat4
	(
		 x,   0.0f, 0.0f, 0.0f,
		0.0f,  y,   0.0f, 0.0f,
		0.0f, 0.0f,  z,   0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	);
}
mat4 scale(vec3 scale)
{
	return mat4
	(
		scale.x, 0.0f,   0.0f,   0.0f,
		 0.0f,  scale.y, 0.0f,   0.0f,
		 0.0f,   0.0f,  scale.z, 0.0f,
		 0.0f,   0.0f,   0.0f,   1.0f
	);
}


vec4 angle2quaternion(vec3 axis, float angle)
{
	float sinus = sin(angle / 2.0f);
	return norm(vec4
	(
		axis.x * sinus,
		axis.y * sinus,
		axis.z * sinus,
		cos(angle / 2.0f)
	));
}

mat4 quaternion2matrix(float x, float y, float z, float w)
{
	return mat4
	(
		1.0f - 2.0f * y * y - 2.0f * z * z,     2.0f * x * y + 2.0f * z * w,       2.0f * x * z - 2.0f * y * w,     0.0f,
		    2.0f * x * y - 2.0f * z * w,    1.0f - 2.0f * x * x - 2.0f * z * z,    2.0f * y * z + 2.0f * x * w,     0.0f,
		    2.0f * x * z + 2.0f * y * w,        2.0f * y * z - 2.0f * x * w,    1.0f - 2.0f * x * x - 2.0f * y * y, 0.0f,
		              0.0f,                               0.0f,                              0.0f,                  1.0f
	);
}
mat4 quaternion2matrix(vec4 quaternion)
{
	return mat4
	(
		1.0f - 2.0f * quaternion.y * quaternion.y - 2.0f * quaternion.z * quaternion.z,    2.0f * quaternion.x * quaternion.y + 2.0f * quaternion.z * quaternion.w,        2.0f * quaternion.x * quaternion.z - 2.0f * quaternion.y * quaternion.w,     0.0f,
		   2.0f * quaternion.x * quaternion.y - 2.0f * quaternion.z * quaternion.w,     1.0f - 2.0f * quaternion.x * quaternion.x - 2.0f * quaternion.z * quaternion.z,    2.0f * quaternion.y * quaternion.z + 2.0f * quaternion.x * quaternion.w,     0.0f,
		   2.0f * quaternion.x * quaternion.z + 2.0f * quaternion.y * quaternion.w,        2.0f * quaternion.y * quaternion.z - 2.0f * quaternion.x * quaternion.w,     1.0f - 2.0f * quaternion.x * quaternion.x - 2.0f * quaternion.y * quaternion.y, 0.0f,
		                                  0.0f,                                                                               0.0f,                                                                         0.0f,                                       1.0f
	);
}