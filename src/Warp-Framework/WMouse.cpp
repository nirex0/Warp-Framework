// © 2019 NIREX ALL RIGHTS RESERVED

#include "WMouse.h"

WMouse::WMouse(void)
{
	m_MouseDown = new WRegistry();
	m_MouseUp = new WRegistry();
	m_MouseMove = new WRegistry();
	m_MouseRollUp = new WRegistry();
	m_MouseRollDown = new WRegistry();

	m_mPoint = new WPointF();

	m_mPoint->X(0);
	m_mPoint->Y(0);

	SetGRegisters();
}

WMouse::WMouse(const WMouse & iWMouse)
	: m_MouseDown(iWMouse.m_MouseDown)
	, m_MouseUp(iWMouse.m_MouseUp)
	, m_MouseMove(iWMouse.m_MouseMove)
	, m_MouseRollUp(iWMouse.m_MouseRollUp)
	, m_MouseRollDown(iWMouse.m_MouseRollDown)
{
	SetGRegisters();
}

WMouse::~WMouse(void)
{
	delete m_MouseDown;
	delete m_MouseUp;
	delete m_MouseMove;
	delete m_MouseRollUp;
	delete m_MouseRollDown;
}

WMouse* WMouse::MouseDown(void)
{
	WMouseArgs* ARGS = new WMouseArgs((W_INT)(this->m_mPoint->X()), (W_INT)(this->m_mPoint->Y()), this->m_WMKPrev, KeyState::MouseDown);
	m_MouseDown->Run(this, ARGS);
	return this;
}

WMouse* WMouse::MouseUp(void)

{
	WMouseArgs* ARGS = new WMouseArgs((W_INT)(this->m_mPoint->X()), (W_INT)(this->m_mPoint->Y()), this->m_WMKPrev, KeyState::MouseUp);
	m_MouseUp->Run(this, ARGS);
	return this;
}

WMouse* WMouse::MouseMove(void)

{
	WMouseArgs* ARGS = new WMouseArgs((W_INT)(this->m_mPoint->X()), (W_INT)(this->m_mPoint->Y()), this->m_WMKPrev, KeyState::NoClick);
	m_MouseMove->Run(this, ARGS);
	return this;
}

WMouse* WMouse::MouseMiddleUp(void)

{
	WMouseArgs* ARGS = new WMouseArgs((W_INT)(this->m_mPoint->X()), (W_INT)(this->m_mPoint->Y()), this->m_WMKPrev, KeyState::MouseUp);
	m_MouseRollUp->Run(this, ARGS);
	return this;
}

WMouse* WMouse::MouseMiddleDown(void)

{
	WMouseArgs* ARGS = new WMouseArgs((W_INT)(this->m_mPoint->X()), (W_INT)(this->m_mPoint->Y()), this->m_WMKPrev, KeyState::MouseDown);
	m_MouseRollDown->Run(this, ARGS);
	return this;
}

WRegistry* WMouse::MouseDownRegistry(void)
{
	return this->m_MouseDown;
}

WMouse* WMouse::MouseDownRegistry(WRegistry* const intake)
{
	this->m_MouseDown = intake;
	return this;
}

WRegistry* WMouse::MouseUpRegistry(void)
{
	return this->m_MouseUp;
}

WMouse* WMouse::MouseUpRegistry(WRegistry* const intake)
{
	this->m_MouseUp = intake;
	return this;
}

WRegistry* WMouse::MouseMoveRegistry(void)
{
	return this->m_MouseMove;
}

WMouse* WMouse::MouseMoveRegistry(WRegistry* const intake)
{
	this->m_MouseMove = intake;
	return this;
}

WRegistry* WMouse::MouseRollUpRegistry(void)
{
	return this->m_MouseRollUp;
}

WMouse* WMouse::MouseRollUpRegistry(WRegistry* const intake)
{
	this->m_MouseRollUp = intake;
	return this;
}

WRegistry* WMouse::MouseRollDownRegistry(void)
{
	return this->m_MouseRollDown;
}

WMouse* WMouse::MouseRollDownRegistry(WRegistry* const intake)
{
	this->m_MouseRollDown = intake;
	return this;
}

WPointF* WMouse::MPoint(void)

{
	return this->m_mPoint;
}

WMouse* WMouse::MPoint(W_UINT x, W_UINT y)
{
	this->m_mPoint->X((W_FLOAT)x);
	this->m_mPoint->Y((W_FLOAT)y);
	return this;
}

WMouseKey WMouse::MouseKey(void) const
{
	return m_WMKPrev;
}

WMouse* WMouse::MouseKey(WMouseKey intake)
{
	m_WMKPrev = intake;
	return this;
}

void WMouse::SetGRegisters(void)
{
	WRegContainer::MouseDown(m_MouseDown);
	WRegContainer::MouseUp(m_MouseUp);
	WRegContainer::MouseMove(m_MouseMove);
	WRegContainer::MouseRollUp(m_MouseRollUp);
	WRegContainer::MouseRollDown(m_MouseRollDown);
}
