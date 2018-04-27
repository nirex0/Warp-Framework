//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_MOUSE_ARGS_H_
#define _W_MOUSE_ARGS_H_

#include "WEventArgs.h"
#include "WDefines.h"

enum KeyState
{
	NoClick,
	MouseDown,
	MouseUp
};

class WMouseArgs : public WEventArgs
{
public:
	WMouseArgs(int x, int y, WMouseKey key, KeyState keyState)
	{
		WPoint* ptPtr = new WPoint();
		ptPtr->x = x;
		ptPtr->y = y;
		this->m_wmk = key;
		this->m_Point = ptPtr;
		this->m_keyState = keyState;
	}

	WMouseArgs(WPoint point, WMouseKey key, KeyState keyState)
	{
		WPoint* ptPtr = new WPoint();
		ptPtr->x = point.x;
		ptPtr->y = point.y;
		this->m_wmk = key;
		this->m_Point = ptPtr;
		this->m_keyState = keyState;
	}

	WMouseArgs(WPoint* point, WMouseKey key, KeyState keyState)
	{
		this->m_wmk = key;
		this->m_Point = point;
		this->m_keyState = keyState;
	}

	~WMouseArgs(void)
	{
		delete m_Point;
	}

	WPoint* const Point(void)
	{
		return m_Point;
	}

	WMouseKey const Key(void) const
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

	KeyState State(void) const
	{
		return m_keyState;
	}

private:
	WPoint* m_Point;
	WMouseKey m_wmk;
	KeyState m_keyState;
};

#endif // !_W_MOUSE_ARGS_H_
