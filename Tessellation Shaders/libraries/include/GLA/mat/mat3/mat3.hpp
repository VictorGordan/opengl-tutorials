#ifndef MAT3_H
#define MAT3_H

#include "..\mat2\mat2.hpp"



struct mat3
{
	float a00;
	float a10;
	float a20;
	float a01;
	float a11;
	float a21;
	float a02;
	float a12;
	float a22;

	// mat3(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f) column-major
	static const mat3 identity;
	// mat3(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f) column-major
	static const mat3 zero;


	// The default constructor is mat3(0.0f)
	mat3(float a00, float a10, float a20, 
		 float a01, float a11, float a21, 
		 float a02, float a12, float a22):
		 a00(a00), a10(a10), a20(a20), 
		 a01(a01), a11(a11), a21(a21), 
		 a02(a02), a12(a12), a22(a22) {}

	// Mat3 with val on the diagonal from the top left to the bottom right and the rest 0.0f
	mat3(float val = 0.0f);
	// Note that the 2D array must be column-major
	mat3(const float matrix[3][3]);
	// Construct mat3 (column-major) out of vec3s
	mat3(const vec3 v0, const vec3 v1, const vec3 v2);

	mat3& operator =(const mat3& mat);
	mat3& operator+=(const mat3& mat);
	mat3& operator-=(const mat3& mat);

	mat3 operator+(const mat3& mat) const;
	mat3 operator-(const mat3& mat) const;

	mat3 operator-() const;

	mat3 operator*(const float& val) const;
	mat3 operator*(const mat3& mat) const;
	vec3 operator*(const vec3& vec) const;
	mat3 operator/(const float& val) const;

	bool operator==(const mat3& mat) const;
	bool operator!=(const mat3& mat) const;
};



// Allows for multiplication of mat by a float from the left side as well
mat3 operator*(const float& lhs, const mat3& rhs);


// Returns a transpose of the matrix
mat3 T(const mat3& mat);

// Returns the determinant of the matrix
float det(const mat3& mat);

// Returns the adjugate/adjoint of the matrix
mat3 adj(const mat3& mat);

// Returns the inverse of the matrix
mat3 inv(const mat3& mat);


// Prints the matrix
void print(const mat3& mat);
#endif