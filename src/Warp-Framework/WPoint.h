// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_POINT_H_
#define _W_POINT_H_

#include "WDefines.h"

// X is HEIGHT	, Y is WIDTH
// X is TOP		, Y Is LEFT
// X is BOT		, Y Is RIGHT
template <typename T>
class WPoint
{
public:
	WPoint()
		: m_x(0.0F)
		, m_y(0.0F)
	{
	}
	WPoint(T x, T y)
		: m_x(x)
		, m_y(y)
	{
	}

	T X(void) const { return m_x; };
	T X(T x) { m_x = x; return m_x; };
	
	T Y(void) const { return m_y; };
	T Y(T y) { m_y = y; return m_y; };

private:
	T m_x;
	T m_y;
};

typedef WPoint<W_FLOAT>		WPointF;
typedef WPoint<W_DOUBLE>	WPointD;
typedef WPoint<W_INT>		WPointI;
typedef WPoint<W_UINT>		WPointU;
typedef WPoint<W_LONG>		WPointL;

#endif // !_W_POINT_H_
