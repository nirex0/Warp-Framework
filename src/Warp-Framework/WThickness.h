//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_THICKNESS_H_
#define _W_THICKNESS_H_

class WThickness
{
public:

	WThickness()
		: m_top(0.0F)
		, m_left(0.0F)
		, m_bottom(0.0F)
		, m_right(0.0F)
	{
	}
	WThickness(float uniscale)
		: m_top(uniscale)
		, m_left(uniscale)
		, m_bottom(uniscale)
		, m_right(uniscale)
	{
	}
	WThickness(float top, float left, float bottom, float right)
		: m_top(top)
		, m_left(left)
		, m_bottom(bottom)
		, m_right(right)
	{
	}

	float Top(void) const { return m_top; }
	float Top(float top) { m_top = top; return m_top; }

	float Left(void) const { return m_left; }
	float Left(float left) { m_left = left; return m_left; }

	float Bottom(void) const { return m_bottom; }
	float Bottom(float bottom) { m_bottom = bottom; return m_bottom; }

	float Right(void) const { return m_right; }
	float Right(float right) { m_right = right; return m_right; }
	
private:
	float m_top;
	float m_left;
	float m_bottom;
	float m_right;
};

#endif // !_W_THICKNESS_H_
