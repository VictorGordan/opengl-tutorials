#include"ulp.hpp"

int32_t ulpsDistance(const float a, const float b)
{
	// Save work if the floats are equal
	// Also handles +0 == -0
	if (a == b) return 0;

	constexpr auto max =
		std::numeric_limits<int32_t>::max();

	// Max distance for NaN
	if (isnan(a) || isnan(b)) return max;

	// If one's infinite and they're not equal, max distance
	if (isinf(a) || isinf(b)) return max;

	int32_t ia, ib;
	memcpy(&ia, &a, sizeof(float));
	memcpy(&ib, &b, sizeof(float));

	// Don't compare differently-signed floats
	if ((ia < 0) != (ib < 0)) return max;

	// Return the absolute value of the distance in ULPs
	int32_t distance = ia - ib;
	if (distance < 0) distance = -distance;
	return distance;
}

bool almostEqual(float x, float y)
{
	return ulpsDistance(x, y) <= ULP_PRECISION;
}