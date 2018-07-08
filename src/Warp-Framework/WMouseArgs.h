// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_MOUSE_ARGS_H_
#define _W_MOUSE_ARGS_H_

#include "WDefines.h"
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
	WMouseArgs(W_INT x, W_INT y, WMouseKey key, KeyState keyState);
	WMouseArgs(WPointF point, WMouseKey key, KeyState keyState);
	~WMouseArgs(void) = default;

	WPointF const Point(void);
	WMouseKey const Key(void) const;

	W_INT X(void) const;
	W_INT Y(void) const;

	KeyState State(void) const;

private:
	WPointF m_Point;
	WMouseKey m_wmk;
	KeyState m_keyState;
};

#endif // !_W_MOUSE_ARGS_H_
