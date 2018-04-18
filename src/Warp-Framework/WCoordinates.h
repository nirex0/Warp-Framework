//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_COORDINATES_H_
#define _W_COORDINATES_H_

// X is HEIGHT	, Y is WIDTH
// X is TOP		, Y Is LEFT
// X is BOT		, Y Is RIGHT
class WCoordinates
{
public:

	WCoordinates()
		: m_x(0.0F)
		, m_y(0.0F)
	{
	}
	WCoordinates(float x, float y)
		: m_x(x)
		, m_y(y)
	{
	}

	float X(void) const { return m_x; };
	float X(float x) { m_x = x; return m_x; };
	
	float Y(void) const { return m_y; };
	float Y(float y) { m_y = y; return m_y; };

private:
	float m_x;
	float m_y;
};

#endif // !_W_COORDINATES_H_
