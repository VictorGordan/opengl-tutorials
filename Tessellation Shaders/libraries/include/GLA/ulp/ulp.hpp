#ifndef ULP_H
#define ULP_H

#include <iomanip>
#include <iostream>





const float PI = 3.14159265358979323846f;

const unsigned short FLOAT_PRECISION = 5;
const unsigned int ULP_PRECISION = 10;


// Function from: https://bitbashing.io/comparing-floats.html
int32_t ulpsDistance(const float a, const float b);
// Compares two floats using ULP distance and decides if they are approximately equal or not
bool almostEqual(float x, float y);

#endif