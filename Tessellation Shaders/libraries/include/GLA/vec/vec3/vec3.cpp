#include "vec3.hpp"





const vec3 vec3::up = vec3(0.0f, 1.0f, 0.0f);
const vec3 vec3::down = vec3(0.0f, -1.0f, 0.0f);
const vec3 vec3::right = vec3(1.0f, 0.0f, 0.0f);
const vec3 vec3::left = vec3(-1.0f, 0.0f, 0.0f);
const vec3 vec3::forward = vec3(0.0f, 0.0f, -1.0f);
const vec3 vec3::backward = vec3(0.0f, 0.0f, 1.0f);

const vec3 vec3::one = vec3(1.0f, 1.0f, 1.0f);
const vec3 vec3::zero = vec3(0.0f, 0.0f, 0.0f);





vec3::vec3(float val)
{
	x = val;
	y = val;
	z = val;
}
vec3::vec3(const float vector[3])
{
	x = vector[0];
	y = vector[1];
	z = vector[2];
}

vec3& vec3::operator =(const vec3& a) 
{ 
	x = a.x; 
	y = a.y; 
	z = a.z; 
	return *this; 
}
vec3& vec3::operator+=(const vec3& a) 
{
	x += a.x; 
	y += a.y; 
	z += a.z; 
	return *this; 
}
vec3& vec3::operator-=(const vec3& a) 
{ 
	x -= a.x; 
	y -= a.y; 
	z -= a.z; 
	return *this; 
}



vec3 vec3::operator+(const vec3& a) const 
{ 
	return vec3(x + a.x, y + a.y, z + a.z); 
}
vec3 vec3::operator-(const vec3& a) const 
{ 
	return vec3(x - a.x, y - a.y, z - a.z); 
}



vec3 vec3::operator-() const 
{ 
	return vec3(-x, -y, -z); 
}



vec3 vec3::operator*(const float& a) const 
{ 
	return vec3(x * a, y * a, z * a); 
}
vec3 operator*(const float& lhs, const vec3& rhs)
{
	return vec3(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
}
vec3 vec3::operator/(const float& a) const 
{ 
	return vec3(x / a, y / a, z / a); 
}



bool vec3::operator==(const vec3& a) const 
{ 
	return (almostEqual(x, a.x) && almostEqual(y, a.y) && almostEqual(z, a.z)); 
}
bool vec3::operator!=(const vec3& a) const 
{ 
	return (!almostEqual(x, a.x) || !almostEqual(y, a.y) || !almostEqual(z, a.z)); 
}





float dot(const vec3& v0, const vec3& v1) 
{ 
	return v0.x * v1.x + v0.y * v1.y + v0.z * v1.z; 
}
vec3 cross(const vec3& v0, const vec3& v1)
{
	return vec3(v0.y * v1.z - v1.y * v0.z, -v0.x * v1.z + v1.x * v0.z, v0.x * v1.y - v1.x * v0.y);
}


float mag(const vec3& vec) 
{ 
	return sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z); 
}
float magSqr(const vec3& vec) 
{ 
	return vec.x * vec.x + vec.y * vec.y + vec.z * vec.z; 
}


vec3 norm(const vec3& vec) 
{ 
	return vec / mag(vec); 
}


float dist(const vec3& vec0, const vec3& vec1) 
{ 
	return mag(vec0 - vec1); 
}





void print(const vec3& vec) 
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
		']' << 
	std::endl; 
}