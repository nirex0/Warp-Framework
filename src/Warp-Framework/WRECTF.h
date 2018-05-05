//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_RECTF_H_
#define _W_RECTF_H_

class WRECTF
{
public:
	WRECTF()
		: top(0)
		, left(0)
		, bottom(0)
		, right(0)
	{
	}

	WRECTF(float in_top, float in_left, float in_bottom, float in_right)
		: top(in_top)
		, left(in_left)
		, bottom(in_bottom)
		, right(in_right)
	{
	}

	float Top(void) const { return top; }
	float Top(float intake) { top = intake; return top; }

	float Left(void) const { return left; }
	float Left(float intake) { left = intake; return left; }

	float Bottom(void) const { return bottom; }
	float Bottom(float intake) { bottom = intake; return bottom; }

	float Right(void) const { return right; }
	float Right(float intake) { right = intake; return intake; }

private:
	float top;
	float left;
	float bottom;
	float right;

};

#endif // !_W_RECTF_H_
