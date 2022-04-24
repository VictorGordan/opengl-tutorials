#ifndef CAMERA_H
#define CAMERA_H

#include "..\mat\mat4\mat4.hpp"





// Converts degrees to radians
float radians(float degrees);
// Converts radians to degrees
float degrees(float radians);



// Creates a perspective matrix
// - the fov needs to be in radians and represents the horizontal angle from one edge to the other
// - the aspect ratio is width / height
mat4 perspective(float fov, float aspectRatio, float near, float far);

// Creates a matrix that moves the camera to position "from" and looks at position "to"
// the "up" vector indicates the camera's up direction
mat4 lookAt(vec3 eye, vec3 target, vec3 up);

#endif