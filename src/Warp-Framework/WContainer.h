// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_CONTAINER_H_
#define _W_CONTAINER_H_

#include "WWin.h"
#include "WEntry.h"
#include "WDefines.h"
#include "WMouse.h"
#include "WKeyboard.h"
#include "WTheme.h"

//-->DOC_CLASS
// A Container class that allows access to a set of global static variables throughout the framework
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
	//-->DOC_MEMBER
	//Holds the HRESULT of the last done operation
	static HRESULT HR;

	//-->DOC_MEMBER
	//A Handle to the main window of the framework
	static HWND hWnd;

	//-->DOC_MEMBER
	//Last Sent Message through the windows message loop
	static UINT msg;

	//-->DOC_MEMBER
	//WParam of the windows message loop
	static WPARAM wParam;

	//-->DOC_MEMBER
	//LParam of the windows message loop
	static LPARAM lParam;

	//-->DOC_MEMBER
	//Entry Class
	static WEntry WFramework;

	//-->DOC_MEMBER
	//Current Delta Time of the render engine
	static DELTATIME DeltaTime;

	//-->DOC_MEMBER
	//Background alpha value
	static W_INT BGA;

	//-->DOC_MEMBER
	//Background red value
	static W_INT BGR;

	//-->DOC_MEMBER
	//Background green value
	static W_INT BGG;

	//-->DOC_MEMBER
	//Background blue value
	static W_INT BGB;

	//-->DOC_MEMBER
	//Current Window Width
	static W_INT W_WIDTH;

	//-->DOC_MEMBER
	//Current Window Height
	static W_INT W_HEIGHT;

	//-->DOC_MEMBER
	//Pointer to the mouse object
	static WMouse* mouse;

	//-->DOC_MEMBER
	//Pointer to the keyboard object
	static WKeyboard* keyboard;

	//-->DOC_MEMBER
	//RESERVED FOR DRAGMOVE WINDOW MOVEMENT
	static W_INT helperCoordX;

	//-->DOC_MEMBER
	//RESERVED FOR DRAGMOVE WINDOW MOVEMENT
	static W_INT helperCoordY;
	
	//-->DOC_MEMBER
	//Holder for whether or not window is in a DragMove State
	static BOOL bDragMove;

	//-->DOC_MEMBER
	//Theme of the framework
	static WTheme wTheme;
};


#endif // !_W_CONTAINER_H_
