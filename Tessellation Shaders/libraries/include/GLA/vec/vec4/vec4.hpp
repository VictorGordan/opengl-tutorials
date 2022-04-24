#ifndef VEC4_H
#define VEC4_H

#include "..\..\ulp\ulp.hpp"



struct vec4
{
	float x;
	float y;
	float z;
	float w;

	// vec4(1.0f, 1.0f, 1.0f, 1.0f)
	static const vec4 one;
	// vec4(0.0f, 0.0f, 0.0f, 0.0f)
	static const vec4 zero;


	// The default constructor is vec4(0.0f)
	vec4(float x, float y, float z, float w) :x(x), y(y), z(z), w(w) {};

	// Vec4 filled with val
	vec4(float val = 0.0f);
	// Construct vec4 out of an array
	vec4(const float vector[4]);

	vec4& operator =(const vec4& a);
	vec4& operator+=(const vec4& a);
	vec4& operator-=(const vec4& a);

	vec4 operator+(const vec4& a) const;
	vec4 operator-(const vec4& a) const;

	vec4 operator-() const;

	vec4 operator*(const float& a) const;
	vec4 operator/(const float& a) const;

	bool operator==(const vec4& a) const;
	bool operator!=(const vec4& a) const;
};



// Allows for multiplication of vec by a float from the left side as well
vec4 operator*(const float& lhs, const vec4& rhs);


// Returns the dot product of two vec4s
float dot(const vec4& v0, const vec4& v1);

// Returns the magnitude/length of a vec4. Note that this is slower than magSqr()
float mag(const vec4& vec);
// Returns the squared magnitude/length of a vec4. Note that this is faster than mag()
float magSqr(const vec4& vec);

// Returns a normalized version of the vec
vec4 norm(const vec4& vec);

// Returns the distance between two vec4s
float dist(const vec4& vec0, const vec4& vec1);


// Prints the vector like so [x, y, z, w]
void print(const vec4& vec);
#endif