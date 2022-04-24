#ifndef VEC2_H
#define VEC2_H

#include "..\..\ulp\ulp.hpp"
#include "..\vec3\vec3.hpp"



struct vec2
{
	float x;
	float y;

	// vec2(0.0f, 1.0f)
	static const vec2 up;
	// vec2(0.0f, -1.0f)
	static const vec2 down;
	// vec2(1.0f, 0.0f)
	static const vec2 right;
	// vec2(-1.0f, 1.0f)
	static const vec2 left;

	// vec2(1.0f, 1.0f)
	static const vec2 one;
	// vec2(0.0f, 0.0f)
	static const vec2 zero;


	// The default constructor is vec2(0.0f)
	vec2(float x, float y) :x(x), y(y) {};
	// Construct vec2 out of vec4
	explicit vec2(const vec4& vec) : x(vec.x), y(vec.y) {};
	// Construct vec2 out of vec3
	explicit vec2(const vec3& vec) : x(vec.x), y(vec.y) {};

	// Vec2 filled with val
	vec2(float val = 0.0f);
	// Construct vec2 out of an array
	vec2(const float vector[2]);


	vec2& operator =(const vec2& a);
	vec2& operator+=(const vec2& a);
	vec2& operator-=(const vec2& a);

	vec2 operator+(const vec2& a) const;
	vec2 operator-(const vec2& a) const;

	vec2 operator-() const;

	vec2 operator*(const float& a) const;
	vec2 operator/(const float& a) const;

	bool operator==(const vec2& a) const;
	bool operator!=(const vec2& a) const;
};



// Allows for multiplication of vec by a float from the left side as well
vec2 operator*(const float& lhs, const vec2& rhs);


// Returns the dot product of two vec2s
float dot(const vec2& v0, const vec2& v1);

// Returns the magnitude/length of a vec2. Note that this is slower than magSqr()
float mag(const vec2& vec);
// Returns the squared magnitude/length of a vec2. Note that this is faster than mag()
float magSqr(const vec2& vec);

// Returns a normalized version of the vec
vec2 norm(const vec2& vec);

// Returns the distance between two vec2s
float dist(const vec2& vec0, const vec2& vec1);


// Prints the vector like so [x, y]
void print(const vec2& vec);
#endif