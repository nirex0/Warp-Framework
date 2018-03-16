//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_CONTAINER_H_
#define _W_CONTAINER_H_

#include "WWin.h"

// This class will hold the data required to handle windows messages so they can be used all across the framework.
class WContainer
{
public:
	static void hResult(HRESULT hResult) { WContainer::HR = hResult; }
	static const HRESULT hResult(void) { return WContainer::HR; }

	static void Handle(HWND hWnd) { WContainer::hWnd = hWnd; }
	static const HWND Handle(void) { return WContainer::hWnd; }

	static void Message(UINT msg) { WContainer::msg = msg;}
	static const UINT Message(void) { return WContainer::msg; }
	
	static void WParam(WPARAM wParam) { WContainer::wParam = wParam;}
	static const WPARAM WParam(void) { return WContainer::wParam; }
	
	static void LParam(LPARAM lParam) { WContainer::lParam = lParam;}
	static const LPARAM LParam(void){ return WContainer::lParam; }

private:
	static HRESULT WContainer::HR;
	static HWND WContainer::hWnd;
	static UINT WContainer::msg;
	static WPARAM WContainer::wParam;
	static LPARAM WContainer::lParam;
};


#endif // _W_CONTAINER_H_
