#include "mat2.hpp"





const mat2 mat2::identity = mat2(
	1.0f, 0.0f,
	0.0f, 1.0f);
const mat2 mat2::zero = mat2(
	0.0f, 0.0f,
	0.0f, 0.0f);





mat2::mat2(float val)
{
	a00 = val;    a01 = 0.0f;
	a10 = 0.0f;    a11 = val;
}
mat2::mat2(const float matrix[2][2])
{
	a00 = matrix[0][0];    a01 = matrix[1][0];
	a10 = matrix[0][1];    a11 = matrix[1][1];
}
mat2::mat2(const vec2 v0, const vec2 v1)
{
	a00 = v0.x;    a01 = v1.x;
	a10 = v0.y;    a11 = v1.y;
}

mat2& mat2::operator =(const mat2& mat)
{
	a00 = mat.a00;    a01 = mat.a01;
	a10 = mat.a10;    a11 = mat.a11;
	return *this;
}
mat2& mat2::operator+=(const mat2& mat)
{
	a00 += mat.a00;    a01 += mat.a01;
	a10 += mat.a10;    a11 += mat.a11;
	return *this;
}
mat2& mat2::operator-=(const mat2& mat)
{
	a00 -= mat.a00;    a01 -= mat.a01;
	a10 -= mat.a10;    a11 -= mat.a11;
	return *this;
}

mat2 mat2::operator+(const mat2& mat) const
{
	mat2 out = mat2::zero;
	out.a00 = a00 + mat.a00;    out.a01 = a01 + mat.a01;
	out.a10 = a10 + mat.a10;    out.a11 = a11 + mat.a11;
	return out;
}
mat2 mat2::operator-(const mat2& mat) const
{
	mat2 out = mat2::zero;
	out.a00 = a00 - mat.a00;    out.a01 = a01 - mat.a01;
	out.a10 = a10 - mat.a10;    out.a11 = a11 - mat.a11;
	return out;
}

mat2 mat2::operator-() const
{
	mat2 out = mat2::zero;
	out.a00 = -a00;    out.a01 = -a01;
	out.a10 = -a10;    out.a11 = -a11;
	return out;
}

mat2 mat2::operator*(const float& val) const
{
	mat2 out = mat2::zero;
	out.a00 = a00 * val;    out.a01 = a01 * val;
	out.a10 = a10 * val;    out.a11 = a11 * val;
	return out;
}
mat2 mat2::operator*(const mat2& mat) const
{
	mat2 out = mat2::zero;
	out.a00 = a00 * mat.a00 + a01 * mat.a10;    out.a01 = a00 * mat.a01 + a01 * mat.a11;
	out.a10 = a10 * mat.a00 + a11 * mat.a10;    out.a11 = a10 * mat.a01 + a11 * mat.a11;
	return out;
}
vec2 mat2::operator*(const vec2& vec) const
{
	vec2 out = vec2::zero;
	out.x = a00 * vec.x + a01 * vec.y;
	out.y = a10 * vec.x + a11 * vec.y;
	return out;
}
mat2 operator*(const float& lhs, const mat2& rhs)
{
	mat2 out = mat2::zero;
	out.a00 = lhs * rhs.a00;    out.a01 = lhs * rhs.a01;
	out.a10 = lhs * rhs.a10;    out.a11 = lhs * rhs.a11;
	return out;
}
mat2 mat2::operator/(const float& val) const
{
	mat2 out = mat2::zero;
	out.a00 = a00 / val;    out.a01 = a01 / val;
	out.a10 = a10 / val;    out.a11 = a11 / val;
	return out;
}

bool mat2::operator==(const mat2& mat) const
{
	return
		almostEqual(a00, mat.a00) && almostEqual(a01, mat.a01) &&
		almostEqual(a10, mat.a10) && almostEqual(a11, mat.a11);
}
bool mat2::operator!=(const mat2& mat) const
{
	return
		!almostEqual(a00, mat.a00) || !almostEqual(a01, mat.a01) ||
		!almostEqual(a10, mat.a10) || !almostEqual(a11, mat.a11);
}





mat2 T(const mat2& mat)
{
	mat2 out = mat2::zero;
	out.a00 = mat.a00;    out.a01 = mat.a10;
	out.a10 = mat.a01;    out.a11 = mat.a11;
	return out;
}


float det(const mat2& mat)
{
	return mat.a00 * mat.a11 - mat.a10 * mat.a01;
}


mat2 adj(const mat2& mat)
{
	mat2 out = mat2::zero;
	out.a00 =  mat.a11;    out.a01 = -mat.a01;
	out.a10 = -mat.a10;    out.a11 =  mat.a00;
	return out;
}


mat2 inv(const mat2& mat)
{
	return adj(mat) / det(mat);
}





void print(const mat2& mat)
{
	std::cout << std::fixed << std::setprecision(FLOAT_PRECISION) << char(218) << mat.a00 << " " << mat.a01 << char(191) << std::endl;
	std::cout << std::fixed << std::setprecision(FLOAT_PRECISION) << char(192) << mat.a10 << " " << mat.a11 << char(217) << std::endl;
}