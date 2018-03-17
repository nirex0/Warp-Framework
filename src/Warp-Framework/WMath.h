//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_MATH_H_
#define _W_MATH_H_

#include <math.h>

constexpr float PI = 3.14159265f;
constexpr double PI_D = 3.1415926535897932;

template <typename T>
inline auto sq(const T& x)
{
	return x * x;
}

template <typename T>
inline auto clamp(float x, float lowerlimit, float upperlimit)
{
	if (x < lowerlimit) x = lowerlimit;
	if (x > upperlimit) x = upperlimit;
	return x;
}

template<typename T>
inline T lerp(const T& src, const T& dst, float alpha)
{
	return src + (dst - src) * alpha;
}

template <typename T>
inline auto smoothstep(float from, float to, float x)
{
	x = clamp((x - from) / (to - from), 0.0f, 1.0f);
	return x * x * (3 - 2 * x);
}



#endif // _W_MATH_H_

