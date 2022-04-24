#include "vec2.hpp"





const vec2 vec2::up = vec2(0.0f, 1.0f);
const vec2 vec2::down = vec2(0.0f, -1.0f);
const vec2 vec2::right = vec2(1.0f, 0.0f);
const vec2 vec2::left = vec2(-1.0f, 0.0f);

const vec2 vec2::one = vec2(1.0f, 1.0f);
const vec2 vec2::zero = vec2(0.0f, 0.0f);





vec2::vec2(float val)
{
	x = val;    
	y = val;
}
vec2::vec2(const float vector[2])
{
	x = vector[0];
	y = vector[1];
}

vec2& vec2::operator=(const vec2& a)
{
	x = a.x;
	y = a.y;
	return *this;
}
vec2& vec2::operator+=(const vec2& a)
{
	x += a.x;
	y += a.y;
	return *this;
}
vec2& vec2::operator-=(const vec2& a)
{
	x -= a.x;
	y -= a.y;
	return *this;
}



vec2 vec2::operator+(const vec2& a) const
{
	return vec2(x + a.x, y + a.y);
}
vec2 vec2::operator-(const vec2& a) const
{
	return vec2(x - a.x, y - a.y);
}



vec2 vec2::operator-() const
{
	return vec2(-x, -y);
}



vec2 vec2::operator*(const float& a) const
{
	return vec2(x * a, y * a);
}
vec2 operator*(const float& lhs, const vec2& rhs) 
{ 
	return vec2(lhs * rhs.x, lhs * rhs.y); 
}
vec2 vec2::operator/(const float& a) const
{
	return vec2(x / a, y / a);
}



bool vec2::operator==(const vec2& a) const
{
	return (almostEqual(x, a.x) && almostEqual(y, a.y));
}
bool vec2::operator!=(const vec2& a) const
{
	return (!almostEqual(x, a.x) || !almostEqual(y, a.y));
}





float dot(const vec2& v0, const vec2& v1) 
{ 
	return v0.x * v1.x + v0.y * v1.y; 
}


float mag(const vec2& vec) 
{ 
	return sqrtf(vec.x * vec.x + vec.y * vec.y); 
}
float magSqr(const vec2& vec) 
{ 
	return vec.x * vec.x + vec.y * vec.y; 
}


vec2 norm(const vec2& vec) 
{ 
	return vec / mag(vec); 
}


float dist(const vec2& vec0, const vec2& vec1) 
{ 
	return mag(vec0 - vec1); 
}





void print(const vec2& vec)
{
	std::cout << std::fixed << std::setprecision(FLOAT_PRECISION) <<
		'[' <<
		vec.x <<
		',' <<
		' ' <<
		vec.y <<
		']' <<
	std::endl;
}