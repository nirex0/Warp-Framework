// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_CONTAINER_H_
#define _W_CONTAINER_H_

#include "WWin.h"
#include "WEntry.h"
#include "WDefines.h"
#include "WMouse.h"
#include "WKeyboard.h"
#include "WTheme.h"

class WContainer final
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

	static W_INT HCX(W_INT intake);
	static W_INT HCX(void);

	static W_INT HCY(W_INT intake);
	static W_INT HCY(void);

	static BOOL DragMove(BOOL intake);
	static BOOL DragMove(void);

	static WTheme Theme(WTheme intake);
	static WTheme Theme(void);

private:
	static HRESULT HR;
	static HWND hWnd;
	static UINT msg;
	static WPARAM wParam;
	static LPARAM lParam;
	static WEntry WFramework;
	static DELTATIME DeltaTime;
	static W_INT BGA;
	static W_INT BGR;
	static W_INT BGG;
	static W_INT BGB;
	static W_INT W_WIDTH;
	static W_INT W_HEIGHT;
	static WMouse* mouse;
	static WKeyboard* keyboard;
	static W_INT helperCoordX;
	static W_INT helperCoordY;
	static BOOL bDragMove;
	static WTheme wTheme;
};


#endif // !_W_CONTAINER_H_
