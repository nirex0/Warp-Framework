//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_MOUSE_H_
#define _W_MOUSE_H_

#include "WEntity.h"
#include "WUniqueRegister.h"
#include "WDefines.h"
#include "WMouseArgs.h"
#include "WRegContainer.h"

class WMouse final : public WEntity
{
public:
	WMouse(void)
	{
		m_MouseDown = new WUniqueRegister();
		m_MouseUp = new WUniqueRegister();
		m_MouseMove = new WUniqueRegister();
		m_MouseRollUp = new WUniqueRegister();
		m_MouseRollDown = new WUniqueRegister();

		m_mPoint = new WPoint();

		m_mPoint->x = 0;
		m_mPoint->y = 0;

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
		WMouseArgs* ARGS = new WMouseArgs(this->m_mPoint->x, this->m_mPoint->y, this->m_WMKPrev);
		m_MouseDown->Run(this, ARGS);
		return this;
	}
	inline WMouse* MouseUp(void)
	{
		WMouseArgs* ARGS = new WMouseArgs(this->m_mPoint->x, this->m_mPoint->y, this->m_WMKPrev);
		m_MouseUp->Run(this, ARGS);
		return this;
	}
	inline WMouse* MouseMove(void)
	{
		WMouseArgs* ARGS = new WMouseArgs(this->m_mPoint->x, this->m_mPoint->y, this->m_WMKPrev);
		m_MouseMove->Run(this, ARGS);
		return this;
	}

	inline WMouse* MouseMiddleUp(void)
	{
		WMouseArgs* ARGS = new WMouseArgs(this->m_mPoint->x, this->m_mPoint->y, this->m_WMKPrev);
		m_MouseRollUp->Run(this, ARGS);
		return this;
	}

	inline WMouse* MouseMiddleDown(void)
	{
		WMouseArgs* ARGS = new WMouseArgs(this->m_mPoint->x, this->m_mPoint->y, this->m_WMKPrev);
		m_MouseRollDown->Run(this, ARGS);
		return this;
	}

	inline WUniqueRegister* MouseDownRegistry(void)
	{
		return this->m_MouseDown;
	}

	inline WMouse* MouseDownRegistry(WUniqueRegister* const intake)
	{
		this->m_MouseDown = intake;
		return this;
	}

	inline WUniqueRegister* MouseUpRegistry(void)
	{
		return this->m_MouseUp;
	}

	inline WMouse* MouseUpRegistry(WUniqueRegister* const intake)
	{
		this->m_MouseUp = intake;
		return this;
	}

	inline WUniqueRegister* MouseMoveRegistry(void)
	{
		return this->m_MouseMove;
	}

	inline WMouse* MouseMoveRegistry(WUniqueRegister* const intake)
	{
		this->m_MouseMove = intake;
		return this;
	}

	inline WUniqueRegister* MouseRollUpRegistry(void)
	{
		return this->m_MouseRollUp;
	}

	inline WMouse* MouseRollUpRegistry(WUniqueRegister* const intake)
	{
		this->m_MouseRollUp = intake;
		return this;
	}

	inline WUniqueRegister* MouseRollDownRegistry(void)
	{
		return this->m_MouseRollDown;
	}

	inline WMouse* MouseRollDownRegistry(WUniqueRegister* const intake)
	{
		this->m_MouseRollDown = intake;
		return this;
	}


	inline WPoint* MPoint(void)
	{
		return this->m_mPoint;
	}

	inline WMouse* MPoint(unsigned int x, unsigned int y)
	{
		this->m_mPoint->x = x;
		this->m_mPoint->y = y;
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
	
	WUniqueRegister* m_MouseDown;
	WUniqueRegister* m_MouseUp;
	WUniqueRegister* m_MouseMove;
	WUniqueRegister* m_MouseRollUp;
	WUniqueRegister* m_MouseRollDown;

	WPoint* m_mPoint;
	WMouseKey m_WMKPrev;
};

#endif // !_W_MOUSE_H_

