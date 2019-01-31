// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_RECT_H_
#define _W_RECT_H_

#include "WDefines.h"
#include "WPoint.h"

template <typename T>
class WRect
{
public:

	WRect()
		: m_top(0.0F)
		, m_left(0.0F)
		, m_bottom(0.0F)
		, m_right(0.0F)
	{
	}
	WRect(T uniscale)
		: m_top(uniscale)
		, m_left(uniscale)
		, m_bottom(uniscale)
		, m_right(uniscale)
	{
	}
	WRect(T top, T left, T bottom, T right)
		: m_top(top)
		, m_left(left)
		, m_bottom(bottom)
		, m_right(right)
	{
	}

	T Top(void) const { return m_top; }
	T Top(T top) { m_top = top; return m_top; }

	T Left(void) const { return m_left; }
	T Left(T left) { m_left = left; return m_left; }

	T Bottom(void) const { return m_bottom; }
	T Bottom(T bottom) { m_bottom = bottom; return m_bottom; }

	T Right(void) const { return m_right; }
	T Right(T right) { m_right = right; return m_right; }
	
	bool IsColliding(WRect intake) const
	{
		return
			(
				this->Left() < intake.Right() &&
				this->Right() > intake.Left() &&
				this->Top() < intake.Bottom() &&
				this->Bottom() > intake.Top()
				);
	}
	bool IsColliding(WPointF intake) const
	{
		return
			(
				intake.X() < this->Right() &&
				intake.X() > this->Left() &&
				intake.Y() < this->Bottom() &&
				intake.Y() > this->Top()
				);
	}

private:
	T m_top;
	T m_left;
	T m_bottom;
	T m_right;
};

typedef WRect<W_FLOAT>		WRectF;
typedef WRect<W_DOUBLE>		WRectD;
typedef WRect<W_INT>		WRectI;
typedef WRect<W_UINT>		WRectU;
typedef WRect<W_LONG>		WRectL;

#endif // !_W_RECT_H_
