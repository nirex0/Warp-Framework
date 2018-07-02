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
	static const HRESULT hResult(HRESULT intake) { WContainer::HR = intake; return WContainer::HR; }
	static const HRESULT hResult(void) { return WContainer::HR; }

	static const HWND Handle(HWND intake) { WContainer::hWnd = intake; return WContainer::hWnd; }
	static const HWND Handle(void) { return WContainer::hWnd; }

	static const UINT Message(UINT intake) { WContainer::msg = intake; return WContainer::msg; }
	static const UINT Message(void) { return WContainer::msg; }

	static const WPARAM WParam(WPARAM intake) { WContainer::wParam = intake; return WContainer::wParam; }
	static const WPARAM WParam(void) { return WContainer::wParam; }

	static const LPARAM LParam(LPARAM intake) { WContainer::lParam = intake; return WContainer::lParam; }
	static const LPARAM LParam(void) { return WContainer::lParam; }

	static const WEntry Framework(WEntry intake) { WContainer::WFramework = intake; return WContainer::WFramework; }
	static const WEntry Framework(void) { return WContainer::WFramework; }

	static const DELTATIME DeltaSeconds(DELTATIME intake) { WContainer::DeltaTime = intake; return WContainer::DeltaTime; }
	static const DELTATIME DeltaSeconds(void) { return WContainer::DeltaTime; }

	static const W_INT BackA(W_INT intake) { WContainer::BGA = intake; return WContainer::BGA; }
	static const W_INT BackA(void) { return WContainer::BGA; }

	static const W_INT BackR(W_INT intake) { WContainer::BGR = intake; return WContainer::BGR; }
	static const W_INT BackR(void) { return WContainer::BGR; }

	static const W_INT BackG(W_INT intake) { WContainer::BGG = intake; return WContainer::BGG; }
	static const W_INT BackG(void) { return WContainer::BGG; }

	static const W_INT BackB(W_INT intake) { WContainer::BGB = intake; return WContainer::BGB; }
	static const W_INT BackB(void) { return WContainer::BGB; }

	static const W_INT Width(W_INT intake) { WContainer::W_WIDTH = intake; return WContainer::W_WIDTH; }
	static const W_INT Width(void) { return WContainer::W_WIDTH; }

	static const W_INT Height(W_INT intake) { WContainer::W_HEIGHT = intake; return WContainer::W_HEIGHT; }
	static const W_INT Height(void) { return WContainer::W_HEIGHT; }

	static WMouse* Mouse(WMouse* intake) { WContainer::mouse = intake; return WContainer::mouse; }
	static WMouse* Mouse(void) { return WContainer::mouse; }

	static WKeyboard* Keyboard(WKeyboard* intake) { WContainer::keyboard = intake; return WContainer::keyboard; }
	static WKeyboard* Keyboard(void) { return WContainer::keyboard; }

	static INT HCX(INT intake) { WContainer::helperCoordX = intake; return WContainer::helperCoordX; }
	static INT HCX(void) { return WContainer::helperCoordX; }
		   
	static INT HCY(INT intake) { WContainer::helperCoordY = intake; return WContainer::helperCoordY; }
	static INT HCY(void) { return WContainer::helperCoordY; }

	static BOOL DragMove(BOOL intake) { WContainer::bDragMove = intake; return WContainer::bDragMove; }
	static BOOL DragMove(void) { return WContainer::bDragMove; }

	static WTheme Theme(WTheme intake) { wTheme = intake; return wTheme; }
	static WTheme Theme(void) { return wTheme; }

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
