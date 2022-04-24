#include "mat3.hpp"





const mat3 mat3::identity = mat3(
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f);
const mat3 mat3::zero = mat3(
	0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 0.0f);





mat3::mat3(float val)
{
	a00 =  val;    a01 = 0.0f;    a02 = 0.0f;
	a10 = 0.0f;    a11 =  val;    a12 = 0.0f;
	a20 = 0.0f;    a21 = 0.0f;    a22 = val;
}
mat3::mat3(const float matrix[3][3])
{
	a00 = matrix[0][0];    a01 = matrix[1][0];    a02 = matrix[2][0];
	a10 = matrix[0][1];    a11 = matrix[1][1];    a12 = matrix[2][1];
	a20 = matrix[0][2];    a21 = matrix[1][2];    a22 = matrix[2][2];
}
mat3::mat3(const vec3 v0, const vec3 v1, const vec3 v2)
{
	a00 = v0.x;    a01 = v1.x;    a02 = v2.x;
	a10 = v0.y;    a11 = v1.y;    a12 = v2.y;
	a20 = v0.z;    a21 = v1.z;    a22 = v2.z;
}

mat3& mat3::operator =(const mat3& mat)
{
	a00 = mat.a00;    a01 = mat.a01;    a02 = mat.a02;
	a10 = mat.a10;    a11 = mat.a11;    a12 = mat.a12;
	a20 = mat.a20;    a21 = mat.a21;    a22 = mat.a22;
	return *this;
}
mat3& mat3::operator+=(const mat3& mat)
{
	a00 += mat.a00;    a01 += mat.a01;    a02 += mat.a02;
	a10 += mat.a10;    a11 += mat.a11;    a12 += mat.a12;
	a20 += mat.a20;    a21 += mat.a21;    a22 += mat.a22;
	return *this;
}
mat3& mat3::operator-=(const mat3& mat)
{
	a00 -= mat.a00;    a01 -= mat.a01;    a02 -= mat.a02;
	a10 -= mat.a10;    a11 -= mat.a11;    a12 -= mat.a12;
	a20 -= mat.a20;    a21 -= mat.a21;    a22 -= mat.a22;
	return *this;
}

mat3 mat3::operator+(const mat3& mat) const
{
	mat3 out = mat3::zero;
	out.a00 = a00 + mat.a00;    out.a01 = a01 + mat.a01;    out.a02 = a02 + mat.a02;
	out.a10 = a10 + mat.a10;    out.a11 = a11 + mat.a11;    out.a12 = a12 + mat.a12;
	out.a20 = a20 + mat.a20;    out.a21 = a21 + mat.a21;    out.a22 = a22 + mat.a22;
	return out;
}
mat3 mat3::operator-(const mat3& mat) const
{
	mat3 out = mat3::zero;
	out.a00 = a00 - mat.a00;    out.a01 = a01 - mat.a01;    out.a02 = a02 - mat.a02;
	out.a10 = a10 - mat.a10;    out.a11 = a11 - mat.a11;    out.a12 = a12 - mat.a12;
	out.a20 = a20 - mat.a20;    out.a21 = a21 - mat.a21;    out.a22 = a22 - mat.a22;
	return out;
}

mat3 mat3::operator-() const
{
	mat3 out = mat3::zero;
	out.a00 = -a00;    out.a01 = -a01;    out.a02 = -a02;
	out.a10 = -a10;    out.a11 = -a11;    out.a12 = -a12;
	out.a20 = -a20;    out.a21 = -a21;    out.a22 = -a22;
	return out;
}

mat3 mat3::operator*(const float& val) const
{
	mat3 out = mat3::zero;
	out.a00 = a00 * val;    out.a01 = a01 * val;    out.a02 = a02 * val;
	out.a10 = a10 * val;    out.a11 = a11 * val;    out.a12 = a12 * val;
	out.a20 = a20 * val;    out.a21 = a21 * val;    out.a22 = a22 * val;
	return out;
}
mat3 mat3::operator*(const mat3& mat) const
{
	mat3 out = mat3::zero;
	out.a00 = a00 * mat.a00 + a01 * mat.a10 + a02 * mat.a20;    out.a01 = a00 * mat.a01 + a01 * mat.a11 + a02 * mat.a21;    out.a02 = a00 * mat.a02 + a01 * mat.a12 + a02 * mat.a22;
	out.a10 = a10 * mat.a00 + a11 * mat.a10 + a12 * mat.a20;    out.a11 = a10 * mat.a01 + a11 * mat.a11 + a12 * mat.a21;    out.a12 = a10 * mat.a02 + a11 * mat.a12 + a12 * mat.a22;
	out.a20 = a20 * mat.a00 + a21 * mat.a10 + a22 * mat.a20;    out.a21 = a20 * mat.a01 + a21 * mat.a11 + a22 * mat.a21;    out.a22 = a20 * mat.a02 + a21 * mat.a12 + a22 * mat.a22;
	return out;
}
vec3 mat3::operator*(const vec3& vec) const
{
	vec3 out = vec3::zero;
	out.x = a00 * vec.x + a01 * vec.y + a02 * vec.z;
	out.y = a10 * vec.x + a11 * vec.y + a12 * vec.z;
	out.z = a20 * vec.x + a21 * vec.y + a22 * vec.z;
	return out;
}
mat3 operator*(const float& lhs, const mat3& rhs)
{
	mat3 out = mat3::zero;
	out.a00 = lhs * rhs.a00;    out.a01 = lhs * rhs.a01;    out.a02 = lhs * rhs.a02;
	out.a10 = lhs * rhs.a10;    out.a11 = lhs * rhs.a11;    out.a12 = lhs * rhs.a12;
	out.a20 = lhs * rhs.a20;    out.a21 = lhs * rhs.a21;    out.a22 = lhs * rhs.a22;
	return out;
}
mat3 mat3::operator/(const float& val) const
{
	mat3 out = mat3::zero;
	out.a00 = a00 / val;    out.a01 = a01 / val;    out.a02 = a02 / val;
	out.a10 = a10 / val;    out.a11 = a11 / val;    out.a12 = a12 / val;
	out.a20 = a20 / val;    out.a21 = a21 / val;    out.a22 = a22 / val;
	return out;
}

bool mat3::operator==(const mat3& mat) const
{
	return
		almostEqual(a00, mat.a00) && almostEqual(a01, mat.a01) && almostEqual(a02, mat.a02) &&
		almostEqual(a10, mat.a10) && almostEqual(a11, mat.a11) && almostEqual(a12, mat.a12) &&
		almostEqual(a20, mat.a20) && almostEqual(a21, mat.a21) && almostEqual(a22, mat.a22);
}
bool mat3::operator!=(const mat3& mat) const
{
	return
		!almostEqual(a00, mat.a00) || !almostEqual(a01, mat.a01) || !almostEqual(a02, mat.a02) ||
		!almostEqual(a10, mat.a10) || !almostEqual(a11, mat.a11) || !almostEqual(a12, mat.a12) ||
		!almostEqual(a20, mat.a20) || !almostEqual(a21, mat.a21) || !almostEqual(a22, mat.a22);
}





mat3 T(const mat3& mat)
{
	mat3 out = mat3::zero;
	out.a00 = mat.a00;    out.a01 = mat.a10;    out.a02 = mat.a20;
	out.a10 = mat.a01;    out.a11 = mat.a11;    out.a12 = mat.a21;
	out.a20 = mat.a02;    out.a21 = mat.a12;    out.a22 = mat.a22;
	return out;
}


float det(const mat3& mat)
{
	return 
		  mat.a00 * det(mat2(mat.a11, mat.a21, mat.a12, mat.a22))
		- mat.a01 * det(mat2(mat.a10, mat.a20, mat.a12, mat.a22))
		+ mat.a02 * det(mat2(mat.a10, mat.a20, mat.a11, mat.a21));
}


mat3 adj(const mat3& mat)
{
	mat3 out = mat3::zero;
	out.a00 =  det(mat2(mat.a11, mat.a21, mat.a12, mat.a22));    out.a01 = -det(mat2(mat.a01, mat.a21, mat.a02, mat.a22));    out.a02 =  det(mat2(mat.a01, mat.a11, mat.a02, mat.a12));
	out.a10 = -det(mat2(mat.a10, mat.a20, mat.a12, mat.a22));    out.a11 =  det(mat2(mat.a00, mat.a20, mat.a02, mat.a22));    out.a12 = -det(mat2(mat.a00, mat.a10, mat.a02, mat.a12));
	out.a20 =  det(mat2(mat.a10, mat.a20, mat.a11, mat.a21));    out.a21 = -det(mat2(mat.a00, mat.a20, mat.a01, mat.a21));    out.a22 =  det(mat2(mat.a00, mat.a10, mat.a01, mat.a11));
	return out;
}


mat3 inv(const mat3& mat)
{
	return adj(mat) / det(mat);
}





void print(const mat3& mat)
{
	std::cout << std::fixed << std::setprecision(FLOAT_PRECISION) << char(218) << mat.a00 << " " << mat.a01 << " " << mat.a02 << char(191) << std::endl;
	std::cout << std::fixed << std::setprecision(FLOAT_PRECISION) << char(179) << mat.a10 << " " << mat.a11 << " " << mat.a12 << char(179) << std::endl;
	std::cout << std::fixed << std::setprecision(FLOAT_PRECISION) << char(192) << mat.a20 << " " << mat.a21 << " " << mat.a22 << char(217) << std::endl;
}