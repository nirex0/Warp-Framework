// © 2018 NIREX ALL RIGHTS RESERVED

#include "WMouseArgs.h"

WMouseArgs::WMouseArgs(W_INT x, W_INT y, WMouseKey key, KeyState keyState)
{
	m_wmk = key;
	m_Point.X((W_FLOAT)x);
	m_Point.Y((W_FLOAT)y);
	m_keyState = keyState;
}

WMouseArgs::WMouseArgs(WPointF point, WMouseKey key, KeyState keyState)
{
	m_wmk = key;
	m_Point = point;
	this->m_keyState = keyState;
}

WPointF const WMouseArgs::Point(void)
{
	return m_Point;
}

WMouseKey const WMouseArgs::Key(void) const
{
	return m_wmk;
}

W_INT WMouseArgs::X(void) const
{
	return (W_INT)m_Point.X();
}

W_INT WMouseArgs::Y(void) const
{
	return (W_INT)m_Point.Y();
}

KeyState WMouseArgs::State(void) const
{
	return m_keyState;
}