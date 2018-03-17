//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_MOUSE_ARGS_H_
#define _W_MOUSE_ARGS_H_

#include "WEventArgs.h"
#include "WDefines.h"

class WMouseArgs : public WEventArgs
{
public:
	WMouseArgs(int x, int y, WMouseKey key)
	{
		WPoint* ptPtr = new WPoint();
		ptPtr->x = x;
		ptPtr->y = y;
		this->m_wmk = key;
		this->m_Point = ptPtr;
	}

	WMouseArgs(WPoint point, WMouseKey key)
	{
		WPoint* ptPtr = new WPoint();
		ptPtr->x = point.x;
		ptPtr->y = point.y;
		this->m_wmk = key;
		this->m_Point = ptPtr;
	}

	WMouseArgs(WPoint* point, WMouseKey key)
	{
		this->m_wmk = key;
		this->m_Point = point;
	}

	~WMouseArgs(void)
	{
		delete m_Point;
	}

	WPoint* const GetPoint(void)
	{
		return m_Point;
	}

	WMouseKey const GetKey(void) const
	{
		return m_wmk;
	}

	int X(void) const
	{
		return m_Point->x;
	}

	int Y(void) const
	{
		return m_Point->y;
	}

private:
	WPoint* m_Point;
	WMouseKey m_wmk;
};

#endif // _W_MOUSE_ARGS_H_
