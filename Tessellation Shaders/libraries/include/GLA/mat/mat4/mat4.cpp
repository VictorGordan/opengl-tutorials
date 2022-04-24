#include "mat4.hpp"





const mat4 mat4::identity = mat4(
	1.0f, 0.0f, 0.0f, 0.0f, 
	0.0f, 1.0f, 0.0f, 0.0f, 
	0.0f, 0.0f, 1.0f, 0.0f, 
	0.0f, 0.0f, 0.0f, 1.0f);
const mat4 mat4::zero = mat4(
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 0.0f);





mat4::mat4(float val)
{
	a00 =  val;    a01 = 0.0f;    a02 = 0.0f;    a03 = 0.0f;
	a10 = 0.0f;    a11 =  val;    a12 = 0.0f;    a13 = 0.0f;
	a20 = 0.0f;    a21 = 0.0f;    a22 =  val;    a23 = 0.0f;
	a30 = 0.0f;    a31 = 0.0f;    a32 = 0.0f;    a33 = val;
}
mat4::mat4(const float matrix[4][4])
{
	a00 = matrix[0][0];    a01 = matrix[1][0];    a02 = matrix[2][0];    a03 = matrix[3][0];
	a10 = matrix[0][1];    a11 = matrix[1][1];    a12 = matrix[2][1];    a13 = matrix[3][1];
	a20 = matrix[0][2];    a21 = matrix[1][2];    a22 = matrix[2][2];    a23 = matrix[3][2];
	a30 = matrix[0][3];    a31 = matrix[1][3];    a32 = matrix[2][3];    a33 = matrix[3][3];
}
mat4::mat4(const vec4 v0, const vec4 v1, const vec4 v2, const vec4 v3)
{
	a00 = v0.x;    a01 = v1.x;    a02 = v2.x;    a03 = v3.x;
	a10 = v0.y;    a11 = v1.y;    a12 = v2.y;    a13 = v3.y;
	a20 = v0.z;    a21 = v1.z;    a22 = v2.z;    a23 = v3.z;
	a30 = v0.w;    a31 = v1.w;    a32 = v2.w;    a33 = v3.w;
}

mat4& mat4::operator =(const mat4& mat)
{
	a00 = mat.a00;    a01 = mat.a01;    a02 = mat.a02;    a03 = mat.a03;
	a10 = mat.a10;    a11 = mat.a11;    a12 = mat.a12;    a13 = mat.a13;
	a20 = mat.a20;    a21 = mat.a21;    a22 = mat.a22;    a23 = mat.a23;
	a30 = mat.a30;    a31 = mat.a31;    a32 = mat.a32;    a33 = mat.a33;
	return *this;
}
mat4& mat4::operator+=(const mat4& mat)
{
	a00 += mat.a00;    a01 += mat.a01;    a02 += mat.a02;    a03 += mat.a03;
	a10 += mat.a10;    a11 += mat.a11;    a12 += mat.a12;    a13 += mat.a13;
	a20 += mat.a20;    a21 += mat.a21;    a22 += mat.a22;    a23 += mat.a23;
	a30 += mat.a30;    a31 += mat.a31;    a32 += mat.a32;    a33 += mat.a33;
	return *this;
}
mat4& mat4::operator-=(const mat4& mat)
{
	a00 -= mat.a00;    a01 -= mat.a01;    a02 -= mat.a02;    a03 -= mat.a03;
	a10 -= mat.a10;    a11 -= mat.a11;    a12 -= mat.a12;    a13 -= mat.a13;
	a20 -= mat.a20;    a21 -= mat.a21;    a22 -= mat.a22;    a23 -= mat.a23;
	a30 -= mat.a30;    a31 -= mat.a31;    a32 -= mat.a32;    a33 -= mat.a33;
	return *this;
}

mat4 mat4::operator+(const mat4& mat) const
{
	mat4 out = mat4::zero;
	out.a00 = a00 + mat.a00;    out.a01 = a01 + mat.a01;    out.a02 = a02 + mat.a02;    out.a03 = a03 + mat.a03;
	out.a10 = a10 + mat.a10;    out.a11 = a11 + mat.a11;    out.a12 = a12 + mat.a12;    out.a13 = a13 + mat.a13;
	out.a20 = a20 + mat.a20;    out.a21 = a21 + mat.a21;    out.a22 = a22 + mat.a22;    out.a23 = a23 + mat.a23;
	out.a30 = a30 + mat.a30;    out.a31 = a31 + mat.a31;    out.a32 = a32 + mat.a32;    out.a33 = a33 + mat.a33;
	return out;
}
mat4 mat4::operator-(const mat4& mat) const
{
	mat4 out = mat4::zero;
	out.a00 = a00 - mat.a00;    out.a01 = a01 - mat.a01;    out.a02 = a02 - mat.a02;    out.a03 = a03 - mat.a03;
	out.a10 = a10 - mat.a10;    out.a11 = a11 - mat.a11;    out.a12 = a12 - mat.a12;    out.a13 = a13 - mat.a13;
	out.a20 = a20 - mat.a20;    out.a21 = a21 - mat.a21;    out.a22 = a22 - mat.a22;    out.a23 = a23 - mat.a23;
	out.a30 = a30 - mat.a30;    out.a31 = a31 - mat.a31;    out.a32 = a32 - mat.a32;    out.a33 = a33 - mat.a33;
	return out;
}

mat4 mat4::operator-() const
{
	mat4 out = mat4::zero;
	out.a00 = -a00;    out.a01 = -a01;    out.a02 = -a02;    out.a03 = -a03;
	out.a10 = -a10;    out.a11 = -a11;    out.a12 = -a12;    out.a13 = -a13;
	out.a20 = -a20;    out.a21 = -a21;    out.a22 = -a22;    out.a23 = -a23;
	out.a30 = -a30;    out.a31 = -a31;    out.a32 = -a32;    out.a33 = -a33;
	return out;
}

mat4 mat4::operator*(const float& val) const
{
	mat4 out = mat4::zero;
	out.a00 = a00 * val;    out.a01 = a01 * val;    out.a02 = a02 * val;    out.a03 = a03 * val;
	out.a10 = a10 * val;    out.a11 = a11 * val;    out.a12 = a12 * val;    out.a13 = a13 * val;
	out.a20 = a20 * val;    out.a21 = a21 * val;    out.a22 = a22 * val;    out.a23 = a23 * val;
	out.a30 = a30 * val;    out.a31 = a31 * val;    out.a32 = a32 * val;    out.a33 = a33 * val;
	return out;
}
mat4 mat4::operator*(const mat4& mat) const
{
	mat4 out = mat4::zero;
	out.a00 = a00 * mat.a00 + a01 * mat.a10 + a02 * mat.a20 + a03 * mat.a30;    out.a01 = a00 * mat.a01 + a01 * mat.a11 + a02 * mat.a21 + a03 * mat.a31;    out.a02 = a00 * mat.a02 + a01 * mat.a12 + a02 * mat.a22 + a03 * mat.a32;    out.a03 = a00 * mat.a03 + a01 * mat.a13 + a02 * mat.a23 + a03 * mat.a33;
	out.a10 = a10 * mat.a00 + a11 * mat.a10 + a12 * mat.a20 + a13 * mat.a30;    out.a11 = a10 * mat.a01 + a11 * mat.a11 + a12 * mat.a21 + a13 * mat.a31;    out.a12 = a10 * mat.a02 + a11 * mat.a12 + a12 * mat.a22 + a13 * mat.a32;    out.a13 = a10 * mat.a03 + a11 * mat.a13 + a12 * mat.a23 + a13 * mat.a33;
	out.a20 = a20 * mat.a00 + a21 * mat.a10 + a22 * mat.a20 + a23 * mat.a30;    out.a21 = a20 * mat.a01 + a21 * mat.a11 + a22 * mat.a21 + a23 * mat.a31;    out.a22 = a20 * mat.a02 + a21 * mat.a12 + a22 * mat.a22 + a23 * mat.a32;    out.a23 = a20 * mat.a03 + a21 * mat.a13 + a22 * mat.a23 + a23 * mat.a33;
	out.a30 = a30 * mat.a00 + a31 * mat.a10 + a32 * mat.a20 + a33 * mat.a30;    out.a31 = a30 * mat.a01 + a31 * mat.a11 + a32 * mat.a21 + a33 * mat.a31;    out.a32 = a30 * mat.a02 + a31 * mat.a12 + a32 * mat.a22 + a33 * mat.a32;    out.a33 = a30 * mat.a03 + a31 * mat.a13 + a32 * mat.a23 + a33 * mat.a33;
	return out;
}
vec4 mat4::operator*(const vec4& vec) const
{
	vec4 out = vec4::zero;
	out.x = a00 * vec.x + a01 * vec.y + a02 * vec.z + a03 * vec.w;
	out.y = a10 * vec.x + a11 * vec.y + a12 * vec.z + a13 * vec.w;
	out.z = a20 * vec.x + a21 * vec.y + a22 * vec.z + a23 * vec.w;
	out.w = a30 * vec.x + a31 * vec.y + a32 * vec.z + a33 * vec.w;
	return out;
}
mat4 operator*(const float& lhs, const mat4& rhs)
{
	mat4 out = mat4::zero;
	out.a00 = lhs * rhs.a00;    out.a01 = lhs * rhs.a01;    out.a02 = lhs * rhs.a02;    out.a03 = lhs * rhs.a03;
	out.a10 = lhs * rhs.a10;    out.a11 = lhs * rhs.a11;    out.a12 = lhs * rhs.a12;    out.a13 = lhs * rhs.a13;
	out.a20 = lhs * rhs.a20;    out.a21 = lhs * rhs.a21;    out.a22 = lhs * rhs.a22;    out.a23 = lhs * rhs.a23;
	out.a30 = lhs * rhs.a30;    out.a31 = lhs * rhs.a31;    out.a32 = lhs * rhs.a32;    out.a33 = lhs * rhs.a33;
	return out;
}
mat4 mat4::operator/(const float& val) const
{
	mat4 out = mat4::zero;
	out.a00 = a00 / val;    out.a01 = a01 / val;    out.a02 = a02 / val;    out.a03 = a03 / val;
	out.a10 = a10 / val;    out.a11 = a11 / val;    out.a12 = a12 / val;    out.a13 = a13 / val;
	out.a20 = a20 / val;    out.a21 = a21 / val;    out.a22 = a22 / val;    out.a23 = a23 / val;
	out.a30 = a30 / val;    out.a31 = a31 / val;    out.a32 = a32 / val;    out.a33 = a33 / val;
	return out;
}

bool mat4::operator==(const mat4& mat) const
{
	return
		almostEqual(a00, mat.a00) && almostEqual(a01, mat.a01) && almostEqual(a02, mat.a02) && almostEqual(a03, mat.a03) &&
		almostEqual(a10, mat.a10) && almostEqual(a11, mat.a11) && almostEqual(a12, mat.a12) && almostEqual(a13, mat.a13) &&
		almostEqual(a20, mat.a20) && almostEqual(a21, mat.a21) && almostEqual(a22, mat.a22) && almostEqual(a23, mat.a23) &&
		almostEqual(a30, mat.a30) && almostEqual(a31, mat.a31) && almostEqual(a32, mat.a32) && almostEqual(a33, mat.a33);
}
bool mat4::operator!=(const mat4& mat) const
{
	return
		!almostEqual(a00, mat.a00) || !almostEqual(a01, mat.a01) || !almostEqual(a02, mat.a02) || !almostEqual(a03, mat.a03) ||
		!almostEqual(a10, mat.a10) || !almostEqual(a11, mat.a11) || !almostEqual(a12, mat.a12) || !almostEqual(a13, mat.a13) ||
		!almostEqual(a20, mat.a20) || !almostEqual(a21, mat.a21) || !almostEqual(a22, mat.a22) || !almostEqual(a23, mat.a23) ||
		!almostEqual(a30, mat.a30) || !almostEqual(a31, mat.a31) || !almostEqual(a32, mat.a32) || !almostEqual(a33, mat.a33);
}





mat4 T(const mat4& mat)
{
	mat4 out = mat4::zero;
	out.a00 = mat.a00;    out.a01 = mat.a10;    out.a02 = mat.a20;    out.a03 = mat.a30;
	out.a10 = mat.a01;    out.a11 = mat.a11;    out.a12 = mat.a21;    out.a13 = mat.a31;
	out.a20 = mat.a02;    out.a21 = mat.a12;    out.a22 = mat.a22;    out.a23 = mat.a32;
	out.a30 = mat.a03;    out.a31 = mat.a13;    out.a32 = mat.a23;    out.a33 = mat.a33;
	return out;
}


float det(const mat4& mat)
{
	return
		  mat.a00 * det(mat3(mat.a11, mat.a21, mat.a31, mat.a12, mat.a22, mat.a32, mat.a13, mat.a23, mat.a33))
		- mat.a01 * det(mat3(mat.a10, mat.a20, mat.a30, mat.a12, mat.a22, mat.a32, mat.a13, mat.a23, mat.a33))
		+ mat.a02 * det(mat3(mat.a10, mat.a20, mat.a30, mat.a11, mat.a21, mat.a31, mat.a13, mat.a23, mat.a33))
		- mat.a03 * det(mat3(mat.a10, mat.a20, mat.a30, mat.a11, mat.a21, mat.a31, mat.a12, mat.a22, mat.a32));
}


mat4 adj(const mat4& mat)
{
	mat4 out = mat4::zero;
	out.a00 =  det(mat3(mat.a11, mat.a21, mat.a31, mat.a12, mat.a22, mat.a32, mat.a13, mat.a23, mat.a33));    out.a01 = -det(mat3(mat.a01, mat.a21, mat.a31, mat.a02, mat.a22, mat.a32, mat.a03, mat.a23, mat.a33));    out.a02 =  det(mat3(mat.a01, mat.a11, mat.a31, mat.a02, mat.a12, mat.a32, mat.a03, mat.a13, mat.a33));    out.a03 = -det(mat3(mat.a01, mat.a11, mat.a21, mat.a02, mat.a12, mat.a22, mat.a03, mat.a13, mat.a23));
	out.a10 = -det(mat3(mat.a10, mat.a20, mat.a30, mat.a12, mat.a22, mat.a32, mat.a13, mat.a23, mat.a33));    out.a11 =  det(mat3(mat.a00, mat.a20, mat.a30, mat.a02, mat.a22, mat.a32, mat.a03, mat.a23, mat.a33));    out.a12 = -det(mat3(mat.a00, mat.a10, mat.a30, mat.a02, mat.a12, mat.a32, mat.a03, mat.a13, mat.a33));    out.a13 =  det(mat3(mat.a00, mat.a10, mat.a20, mat.a02, mat.a12, mat.a22, mat.a03, mat.a13, mat.a23));
	out.a20 =  det(mat3(mat.a10, mat.a20, mat.a30, mat.a11, mat.a21, mat.a31, mat.a13, mat.a23, mat.a33));    out.a21 = -det(mat3(mat.a00, mat.a20, mat.a30, mat.a01, mat.a21, mat.a31, mat.a03, mat.a23, mat.a33));    out.a22 =  det(mat3(mat.a00, mat.a10, mat.a30, mat.a01, mat.a11, mat.a31, mat.a03, mat.a13, mat.a33));    out.a23 = -det(mat3(mat.a00, mat.a10, mat.a20, mat.a01, mat.a11, mat.a21, mat.a03, mat.a13, mat.a23));
	out.a30 = -det(mat3(mat.a10, mat.a20, mat.a30, mat.a11, mat.a21, mat.a31, mat.a12, mat.a22, mat.a32));    out.a31 =  det(mat3(mat.a00, mat.a20, mat.a30, mat.a01, mat.a21, mat.a31, mat.a02, mat.a22, mat.a32));    out.a32 = -det(mat3(mat.a00, mat.a10, mat.a30, mat.a01, mat.a11, mat.a31, mat.a02, mat.a12, mat.a32));    out.a33 =  det(mat3(mat.a00, mat.a10, mat.a20, mat.a01, mat.a11, mat.a21, mat.a02, mat.a12, mat.a22));
	return out;
}


mat4 inv(const mat4& mat)
{
	return adj(mat) / det(mat);
}





void print(const mat4& mat)
{
	std::cout << std::fixed << std::setprecision(FLOAT_PRECISION) << char(218) << mat.a00 << " " << mat.a01 << " " << mat.a02 << " " << mat.a03 << char(191) << std::endl;
	std::cout << std::fixed << std::setprecision(FLOAT_PRECISION) << char(179) << mat.a10 << " " << mat.a11 << " " << mat.a12 << " " << mat.a13 << char(179) << std::endl;
	std::cout << std::fixed << std::setprecision(FLOAT_PRECISION) << char(179) << mat.a20 << " " << mat.a21 << " " << mat.a22 << " " << mat.a23 << char(179) << std::endl;
	std::cout << std::fixed << std::setprecision(FLOAT_PRECISION) << char(192) << mat.a30 << " " << mat.a31 << " " << mat.a32 << " " << mat.a33 << char(217) << std::endl;
}