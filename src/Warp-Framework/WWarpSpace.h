// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_WARP_SPACE_H_
#define _W_WARP_SPACE_H_

#include "WEntity.h"
#include "WPoint.h"
#include "WRect.h"
class WWarpSpace : public WEntity
{
public:
	static WPointF Coordinates(W_FLOAT x, W_FLOAT y);
	static WPointF Coordinates(WPointF coords);

	static WRectF Coordinates(W_FLOAT top, W_FLOAT left, W_FLOAT bottom, W_FLOAT right);
	static WRectF Coordinates(WPointF topLeft, WPointF botRight);
	static WRectF Coordinates(WRectF input);

	static W_FLOAT Calculate(W_FLOAT input, W_FLOAT ref);
};

#endif // !_W_WARP_SPACE_H_
