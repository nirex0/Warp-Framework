//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_MOUSE_ARGS_H_
#define _W_MOUSE_ARGS_H_

#include "WEventArgs.h"
#include "WPoint.h"

enum KeyState
{
	NoClick,
	MouseDown,
	MouseUp
};

class WMouseArgs : public WEventArgs
{
public:
	WMouseArgs(W_INT x, W_INT y, WMouseKey key, KeyState keyState)
	{
		this->m_wmk = key;
		this->m_Point.X((W_FLOAT)x);
		this->m_Point.Y((W_FLOAT)y);
		this->m_keyState = keyState;
	}

	WMouseArgs(WPointF point, WMouseKey key, KeyState keyState)
	{
		this->m_wmk = key;
		this->m_Point = point;
		this->m_keyState = keyState;
	}

	~WMouseArgs(void)
	{

	}

	WPointF const Point(void)
	{
		return m_Point;
	}

	WMouseKey const Key(void) const
	{
		return m_wmk;
	}

	W_INT X(void) const
	{
		return (W_INT)m_Point.X();
	}

	W_INT Y(void) const
	{
		return (W_INT)m_Point.Y();
	}

	KeyState State(void) const
	{
		return m_keyState;
	}

private:
	WPointF m_Point;
	WMouseKey m_wmk;
	KeyState m_keyState;
};

#endif // !_W_MOUSE_ARGS_H_
