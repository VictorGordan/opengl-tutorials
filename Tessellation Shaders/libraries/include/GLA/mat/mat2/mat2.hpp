#ifndef MAT2_H
#define MAT2_H

#include "..\..\vec\vec2\vec2.hpp"



struct mat2
{
	float a00;
	float a10;
	float a01;
	float a11;

	// mat2(1.0f, 0.0f, 0.0f, 1.0f) column-major
	static const mat2 identity;
	// mat2(0.0f, 0.0f, 0.0f, 0.0f) column-major
	static const mat2 zero;


	// The default constructor is mat2(0.0f)
	mat2(float a00, float a10, 
		 float a01, float a11):
		 a00(a00), a10(a10), 
		 a01(a01), a11(a11) {}

	// Mat2 with val on the diagonal from the top left to the bottom right and the rest 0.0f
	mat2(float val = 0.0f);
	// Note that the 2D array must be column-major
	mat2(const float matrix[2][2]);
	// Construct mat2 (column-major) out of vec2s
	mat2(const vec2 v0, const vec2 v1);

	mat2& operator =(const mat2& mat);
	mat2& operator+=(const mat2& mat);
	mat2& operator-=(const mat2& mat);

	mat2 operator+(const mat2& mat) const;
	mat2 operator-(const mat2& mat) const;

	mat2 operator-() const;

	mat2 operator*(const float& val) const;
	mat2 operator*(const mat2& mat) const;
	vec2 operator*(const vec2& vec) const;
	mat2 operator/(const float& val) const;

	bool operator==(const mat2& mat) const;
	bool operator!=(const mat2& mat) const;
};



// Allows for multiplication of mat by a float from the left side as well
mat2 operator*(const float& lhs, const mat2& rhs);


// Returns a transpose of the matrix
mat2 T(const mat2& mat);

// Returns the determinant of the matrix
float det(const mat2& mat);

// Returns the adjugate/adjoint of the matrix
mat2 adj(const mat2& mat);

// Returns the inverse of the matrix
mat2 inv(const mat2& mat);


// Prints the matrix
void print(const mat2& mat);
#endif