//© 2018 NIREX ALL RIGHTS RESERVED

#include "WMouseArgs.h"

WMouseArgs::WMouseArgs(int x, int y, WMouseKey key)
{
	WPoint* ptPtr = new WPoint();
	ptPtr->x = x;
	ptPtr->y = y;
	this->m_wmk = key;
	this->m_Point = ptPtr;
}

WMouseArgs::WMouseArgs(WPoint point, WMouseKey key)
{
	WPoint* ptPtr = new WPoint();
	ptPtr->x = point.x;
	ptPtr->y = point.y;
	this->m_wmk = key;
	this->m_Point = ptPtr;
}

WMouseArgs::WMouseArgs(WPoint* point, WMouseKey key)
{
	this->m_wmk = key;
	this->m_Point = point;
}

WMouseArgs::~WMouseArgs(void)
{
	delete m_Point;
}

WPoint* const WMouseArgs::GetPoint(void)
{
	return m_Point;
}

WMouseKey const WMouseArgs::GetKey(void) const
{
	return m_wmk;
}

int WMouseArgs::GetX(void) const
{
	return m_Point->x;
}

int WMouseArgs::GetY(void) const
{
	return m_Point->y;
}
