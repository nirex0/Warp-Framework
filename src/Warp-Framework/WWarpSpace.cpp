// © 2018 NIREX ALL RIGHTS RESERVED

#include "WWarpSpace.h"
#include "WContainer.h"
#include "WMath.h"

WPointF WWarpSpace::Coordinates(W_FLOAT xInput, W_FLOAT yInput)
{
	xInput = clamp(xInput, 0, 1);
	yInput = clamp(yInput, 0, 1);

	return WPointF(
		(W_FLOAT)(WContainer::Width() / 2) + ((WContainer::Width() / 2) * xInput), 
		(W_FLOAT)(WContainer::Height() / 2) + ((WContainer::Height() / 2) * yInput));
}

WPointF WWarpSpace::Coordinates(WPointF coords)
{
	return Coordinates(coords.X(), coords.Y());
}

WRectF WWarpSpace::Coordinates(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right)
{
	WPointF tl = Coordinates(top, left);
	WPointF br = Coordinates(bottom, right);
	return WRectF(tl.Y(), tl.X(), br.Y(), br.X());
}

WRectF WWarpSpace::Coordinates(WPointF topLeft, WPointF botRight)
{
	topLeft = Coordinates(topLeft.X(), topLeft.Y());
	botRight = Coordinates(botRight.X(), botRight.Y());
	return WRectF(topLeft.Y(), topLeft.X(), botRight.Y(), botRight.X());
}

WRectF WWarpSpace::Coordinates(WRectF input)
{
	return Coordinates(
		input.Top(), 
		input.Left(), 
		input.Bottom(), 
		input.Right());
}

W_FLOAT WWarpSpace::Calculate(W_FLOAT input, W_FLOAT ref)
{
	input = clamp(input, 0, 1);
	return (W_FLOAT)(ref / 2) + ((ref / 2) * input);
}
