#ifndef MAT4_H
#define MAT4_H

#include "..\mat3\mat3.hpp"



struct mat4
{
	float a00;
	float a10;
	float a20;
	float a30;
	float a01;
	float a11;
	float a21;
	float a31;
	float a02;
	float a12;
	float a22;
	float a32;
	float a03;
	float a13;
	float a23;
	float a33;

	// mat4(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f) column-major
	static const mat4 identity;
	// mat4(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f) column-major
	static const mat4 zero;


	// The default constructor is mat4(0.0f)
	mat4(float a00, float a10, float a20, float a30, 
		 float a01, float a11, float a21, float a31, 
		 float a02, float a12, float a22, float a32, 
		 float a03, float a13, float a23, float a33):
		 a00(a00), a10(a10), a20(a20), a30(a30), 
		 a01(a01), a11(a11), a21(a21), a31(a31), 
		 a02(a02), a12(a12), a22(a22), a32(a32), 
		 a03(a03), a13(a13), a23(a23), a33(a33) {}

	// Mat4 with val on the diagonal from the top left to the bottom right and the rest 0.0f
	mat4(float val = 0.0f);
	// Note that the 2D array must be column-major
	mat4(const float matrix[4][4]);
	// Construct mat4 (column-major) out of vec4s
	mat4(const vec4 v0, const vec4 v1, const vec4 v2, const vec4 v3);

	mat4& operator =(const mat4& mat);
	mat4& operator+=(const mat4& mat);
	mat4& operator-=(const mat4& mat);

	mat4 operator+(const mat4& mat) const;
	mat4 operator-(const mat4& mat) const;

	mat4 operator-() const;

	mat4 operator*(const float& val) const;
	mat4 operator*(const mat4& mat) const;
	vec4 operator*(const vec4& vec) const;
	mat4 operator/(const float& val) const;

	bool operator==(const mat4& mat) const;
	bool operator!=(const mat4& mat) const;
};



// Allows for multiplication of mat by a float from the left side as well
mat4 operator*(const float& lhs, const mat4& rhs);


// Returns a transpose of the matrix
mat4 T(const mat4& mat);

// Returns the determinant of the matrix
float det(const mat4& mat);

// Returns the adjugate/adjoint of the matrix
mat4 adj(const mat4& mat);

// Returns the inverse of the matrix
mat4 inv(const mat4& mat);


// Prints the matrix
void print(const mat4& mat);
#endif