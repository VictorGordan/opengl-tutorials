#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H

#include "..\mat\mat4\mat4.hpp"





// Create a translation matrix
mat4 translation(float x, float y, float z);
// Create a translation matrix
mat4 translation(vec3 translation);
// Creates a rotation matrix (Euler angles)
mat4 rotation(float x, float y, float z);
// Creates a rotation matrix (Euler angles)
mat4 rotation(vec3 rotation);
// Create a scale matrix
mat4 scale(float x, float y, float z);
// Create a scale matrix
mat4 scale(vec3 scale);

// Transforms an angle in radians into a quaternion for a certain axis
vec4 angle2quaternion(vec3 axis, float angle);
// Transforms a quaternion into a matrix
mat4 quaternion2matrix(float x, float y, float z, float w);
// Transforms a quaternion into a matrix
mat4 quaternion2matrix(vec4 quaternion);

#endif