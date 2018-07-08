// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_CONTAINER_H_
#define _W_CONTAINER_H_

#include "WWin.h"
#include "WEntry.h"
#include "WDefines.h"
#include "WMouse.h"
#include "WKeyboard.h"
#include "WTheme.h"

class WContainer
{
public:
	static const HRESULT hResult(HRESULT intake);
	static const HRESULT hResult(void);

	static const HWND Handle(HWND intake);
	static const HWND Handle(void);

	static const UINT Message(UINT intake);
	static const UINT Message(void);

	static const WPARAM WParam(WPARAM intake);
	static const WPARAM WParam(void);

	static const LPARAM LParam(LPARAM intake);
	static const LPARAM LParam(void);

	static const WEntry Framework(WEntry intake);
	static const WEntry Framework(void);

	static const DELTATIME DeltaSeconds(DELTATIME intake);
	static const DELTATIME DeltaSeconds(void);

	static const W_INT BackA(W_INT intake);
	static const W_INT BackA(void);

	static const W_INT BackR(W_INT intake);
	static const W_INT BackR(void);

	static const W_INT BackG(W_INT intake);
	static const W_INT BackG(void);

	static const W_INT BackB(W_INT intake);
	static const W_INT BackB(void);

	static const W_INT Width(W_INT intake);
	static const W_INT Width(void);

	static const W_INT Height(W_INT intake);
	static const W_INT Height(void);

	static WMouse* Mouse(WMouse* intake);
	static WMouse* Mouse(void);

	static WKeyboard* Keyboard(WKeyboard* intake);
	static WKeyboard* Keyboard(void);

	static INT HCX(INT intake);
	static INT HCX(void);
		   
	static INT HCY(INT intake);
	static INT HCY(void);

	static BOOL DragMove(BOOL intake);
	static BOOL DragMove(void);

	static WTheme Theme(WTheme intake);
	static WTheme Theme(void);

private:
	static HRESULT WContainer::HR;
	static HWND WContainer::hWnd;
	static UINT WContainer::msg;
	static WPARAM WContainer::wParam;
	static LPARAM WContainer::lParam;
	static WEntry WContainer::WFramework;
	static DELTATIME WContainer::DeltaTime;
	static W_INT WContainer::BGA;
	static W_INT WContainer::BGR;
	static W_INT WContainer::BGG;
	static W_INT WContainer::BGB;
	static W_INT WContainer::W_WIDTH;
	static W_INT WContainer::W_HEIGHT;
	static WMouse* WContainer::mouse;
	static WKeyboard* WContainer::keyboard;
	static INT WContainer::helperCoordX;
	static INT WContainer::helperCoordY;
	static BOOL WContainer::bDragMove;
	static WTheme WContainer::wTheme;
};


#endif // !_W_CONTAINER_H_
