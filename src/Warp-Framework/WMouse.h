// © 2019 NIREX ALL RIGHTS RESERVED

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
	WMouse(void);
	WMouse(const WMouse& iWMouse);
	~WMouse(void);

	WMouse* MouseDown(void);
	WMouse* MouseUp(void);
	WMouse* MouseMove(void);
	WMouse* MouseMiddleUp(void);
	WMouse* MouseMiddleDown(void);

	WRegistry* MouseDownRegistry(void);
	WMouse* MouseDownRegistry(WRegistry* const intake);

	WRegistry* MouseUpRegistry(void);
	WMouse* MouseUpRegistry(WRegistry* const intake);

	WRegistry* MouseMoveRegistry(void);
	WMouse* MouseMoveRegistry(WRegistry* const intake);

	WRegistry* MouseRollUpRegistry(void);
	WMouse* MouseRollUpRegistry(WRegistry* const intake);

	WRegistry* MouseRollDownRegistry(void);
	WMouse* MouseRollDownRegistry(WRegistry* const intake);

	WPointF* MPoint(void);
	WMouse* MPoint(W_UINT x, W_UINT y);

	WMouseKey MouseKey(void) const;
	WMouse* MouseKey(WMouseKey intake);

private:
	void SetGRegisters(void);
	
	WRegistry* m_MouseDown;
	WRegistry* m_MouseUp;
	WRegistry* m_MouseMove;
	WRegistry* m_MouseRollUp;
	WRegistry* m_MouseRollDown;

	WPointF* m_mPoint;
	WMouseKey m_WMKPrev;
};

#endif // !_W_MOUSE_H_

