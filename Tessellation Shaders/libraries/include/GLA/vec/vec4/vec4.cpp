#include "vec4.hpp"





const vec4 vec4::one = vec4(1.0f, 1.0f, 1.0f, 1.0f);
const vec4 vec4::zero = vec4(0.0f, 0.0f, 0.0f, 0.0f);





vec4::vec4(float val)
{
	x = val;
	y = val;
	z = val;
	w = val;
}
vec4::vec4(const float vector[4])
{
	x = vector[0];
	y = vector[1];
	z = vector[2];
	w = vector[3];
}

vec4& vec4::operator =(const vec4& a) 
{
	x = a.x; 
	y = a.y; 
	z = a.z; 
	w = a.w; 
	return *this; 
}
vec4& vec4::operator+=(const vec4& a) 
{ 
	x += a.x; 
	y += a.y; 
	z += a.z; 
	w += a.w; 
	return *this; 
}
vec4& vec4::operator-=(const vec4& a) 
{ 
	x -= a.x; 
	y -= a.y; 
	z -= a.z; 
	w -= a.w; 
	return *this; 
}



vec4 vec4::operator+(const vec4& a) const 
{ 
	return vec4(x + a.x, y + a.y, z + a.z, w + a.w); 
}
vec4 vec4::operator-(const vec4& a) const 
{ 
	return vec4(x - a.x, y - a.y, z - a.z, w - a.w); 
}



vec4 vec4::operator-() const 
{ 
	return vec4(-x, -y, -z, -w); 
}



vec4 vec4::operator*(const float& a) const 
{ 
	return vec4(x * a, y * a, z * a, w * a); 
}
vec4 operator*(const float& lhs, const vec4& rhs)
{
	return vec4(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w);
}
vec4 vec4::operator/(const float& a) const 
{ 
	return vec4(x / a, y / a, z / a, w / a); 
}



bool vec4::operator==(const vec4& a) const 
{ 
	return (almostEqual(x, a.x) && almostEqual(y, a.y) && almostEqual(z, a.z) && almostEqual(w, a.w)); 
}
bool vec4::operator!=(const vec4& a) const 
{ 
	return (!almostEqual(x, a.x) || !almostEqual(y, a.y) || !almostEqual(z, a.z) || !almostEqual(w, a.w)); 
}





float dot(const vec4& v0, const vec4& v1) 
{ 
	return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z + v0.w * v1.w; 
}


float mag(const vec4& vec) 
{ 
	return sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z + vec.w * vec.w); 
}
float magSqr(const vec4& vec) 
{ 
	return vec.x * vec.x + vec.y * vec.y + vec.z * vec.z + vec.w * vec.w; 
}


vec4 norm(const vec4& vec) 
{ 
	return vec / mag(vec); 
}


float dist(const vec4& vec0, const vec4& vec1) 
{ 
	return mag(vec0 - vec1); 
}





void print(const vec4& vec) 
{ 
	std::cout << std::fixed << std::setprecision(FLOAT_PRECISION) << 
		'[' << 
		vec.x << 
		',' << 
		' ' << 
		vec.y << 
		',' << 
		' ' << 
		vec.z << 
		',' << 
		' ' << 
		vec.w << 
		']' << 
	std::endl; }