#ifndef VEC3_H
#define VEC3_H

#include "..\..\ulp\ulp.hpp"
#include "..\vec4\vec4.hpp"



struct vec3
{
	float x;
	float y;
	float z;

	// vec3(0.0f, 1.0f, 0.0f)
	static const vec3 up;
	// vec3(0.0f, -1.0f, 0.0f)
	static const vec3 down;
	// vec3(1.0f, 0.0f, 0.0f)
	static const vec3 right;
	// vec3(-1.0f, 1.0f, 0.0f)
	static const vec3 left;
	// vec3(0.0f, 0.0f, -1.0f)
	static const vec3 forward;
	// vec3(0.0f, 1.0f, 1.0f)
	static const vec3 backward;

	// vec3(1.0f, 1.0f, 1.0f)
	static const vec3 one;
	// vec3(0.0f, 0.0f, 0.0f)
	static const vec3 zero;


	// The default constructor is vec3(0.0f)
	vec3(float x, float y, float z) :x(x), y(y), z(z) {};
	// Construct vec3 out of vec4
	explicit vec3(const vec4& vec) : x(vec.x), y(vec.y), z(vec.z) {};

	// Vec3 filled with val
	vec3(float val = 0.0f);
	// Construct vec3 out of an array
	vec3(const float vector[3]);
	

	vec3& operator =(const vec3& a);
	vec3& operator+=(const vec3& a);
	vec3& operator-=(const vec3& a);

	vec3 operator+(const vec3& a) const;
	vec3 operator-(const vec3& a) const;

	vec3 operator-() const;

	vec3 operator*(const float& a) const;
	vec3 operator/(const float& a) const;

	bool operator==(const vec3& a) const;
	bool operator!=(const vec3& a) const;
};



// Allows for multiplication of vec by a float from the left side as well
vec3 operator*(const float& lhs, const vec3& rhs);


// Returns the dot product of two vec3s
float dot(const vec3& v0, const vec3& v1);
// Returns the cross product of two vec3s
vec3 cross(const vec3& v0, const vec3& v1);

// Returns the magnitude/length of a vec3. Note that this is slower than magSqr()
float mag(const vec3& vec);
// Returns the squared magnitude/length of a vec3. Note that this is faster than mag()
float magSqr(const vec3& vec);

// Returns a normalized version of the vec
vec3 norm(const vec3& vec);

// Returns the distance between two vec3s
float dist(const vec3& vec0, const vec3& vec1);


// Prints the vector like so [x, y, z]
void print(const vec3& vec);
#endif