// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_MOUSE_H_
#define _W_MOUSE_H_

#include "WEntity.h"
#include "WRegistry.h"
#include "WDefines.h"
#include "WMouseArgs.h"
#include "WRegContainer.h"

class WMouse final : public WEntity
{
public:
	WMouse(void)
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

	WMouse(const WMouse& iWMouse)
		: m_MouseDown(iWMouse.m_MouseDown)
		, m_MouseUp(iWMouse.m_MouseUp)
		, m_MouseMove(iWMouse.m_MouseMove)
		, m_MouseRollUp(iWMouse.m_MouseRollUp)
		, m_MouseRollDown(iWMouse.m_MouseRollDown)
	{
		SetGRegisters();
	}


	~WMouse(void)
	{
		delete m_MouseDown;
		delete m_MouseUp;
		delete m_MouseMove;
		delete m_MouseRollUp;
		delete m_MouseRollDown;
	}

	inline WMouse* MouseDown(void)
	{
		WMouseArgs* ARGS = new WMouseArgs((W_INT)(this->m_mPoint->X()), (W_INT)(this->m_mPoint->Y()), this->m_WMKPrev, KeyState::MouseDown);
		m_MouseDown->Run(this, ARGS);
		return this;
	}
	inline WMouse* MouseUp(void)
	{
		WMouseArgs* ARGS = new WMouseArgs((W_INT)(this->m_mPoint->X()), (W_INT)(this->m_mPoint->Y()), this->m_WMKPrev, KeyState::MouseUp);
		m_MouseUp->Run(this, ARGS);
		return this;
	}
	inline WMouse* MouseMove(void)
	{
		WMouseArgs* ARGS = new WMouseArgs((W_INT)(this->m_mPoint->X()), (W_INT)(this->m_mPoint->Y()), this->m_WMKPrev, KeyState::NoClick);
		m_MouseMove->Run(this, ARGS);
		return this;
	}

	inline WMouse* MouseMiddleUp(void)
	{
		WMouseArgs* ARGS = new WMouseArgs((W_INT)(this->m_mPoint->X()), (W_INT)(this->m_mPoint->Y()), this->m_WMKPrev, KeyState::MouseUp);
		m_MouseRollUp->Run(this, ARGS);
		return this;
	}

	inline WMouse* MouseMiddleDown(void)
	{
		WMouseArgs* ARGS = new WMouseArgs((W_INT)(this->m_mPoint->X()), (W_INT)(this->m_mPoint->Y()), this->m_WMKPrev, KeyState::MouseDown);
		m_MouseRollDown->Run(this, ARGS);
		return this;
	}

	inline WRegistry* MouseDownRegistry(void)
	{
		return this->m_MouseDown;
	}

	inline WMouse* MouseDownRegistry(WRegistry* const intake)
	{
		this->m_MouseDown = intake;
		return this;
	}

	inline WRegistry* MouseUpRegistry(void)
	{
		return this->m_MouseUp;
	}

	inline WMouse* MouseUpRegistry(WRegistry* const intake)
	{
		this->m_MouseUp = intake;
		return this;
	}

	inline WRegistry* MouseMoveRegistry(void)
	{
		return this->m_MouseMove;
	}

	inline WMouse* MouseMoveRegistry(WRegistry* const intake)
	{
		this->m_MouseMove = intake;
		return this;
	}

	inline WRegistry* MouseRollUpRegistry(void)
	{
		return this->m_MouseRollUp;
	}

	inline WMouse* MouseRollUpRegistry(WRegistry* const intake)
	{
		this->m_MouseRollUp = intake;
		return this;
	}

	inline WRegistry* MouseRollDownRegistry(void)
	{
		return this->m_MouseRollDown;
	}

	inline WMouse* MouseRollDownRegistry(WRegistry* const intake)
	{
		this->m_MouseRollDown = intake;
		return this;
	}


	inline WPointF* MPoint(void)
	{
		return this->m_mPoint;
	}

	inline WMouse* MPoint(W_UINT x, W_UINT y)
	{
		this->m_mPoint->X((W_FLOAT)x);
		this->m_mPoint->Y((W_FLOAT)y);
		return this;
	}

	inline WMouseKey MouseKey(void) const
	{
		return m_WMKPrev;
	}

	inline WMouse* MouseKey(WMouseKey intake)
	{
		m_WMKPrev = intake;
		return this;
	}

private:

	void SetGRegisters(void)
	{
		WRegContainer::MouseDown(m_MouseDown);
		WRegContainer::MouseUp(m_MouseUp);
		WRegContainer::MouseMove(m_MouseMove);
		WRegContainer::MouseRollUp(m_MouseRollUp);
		WRegContainer::MouseRollDown(m_MouseRollDown);
	}
	
	WRegistry* m_MouseDown;
	WRegistry* m_MouseUp;
	WRegistry* m_MouseMove;
	WRegistry* m_MouseRollUp;
	WRegistry* m_MouseRollDown;

	WPointF* m_mPoint;
	WMouseKey m_WMKPrev;
};

#endif // !_W_MOUSE_H_

