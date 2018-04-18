//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_CONTAINER_H_
#define _W_CONTAINER_H_

#include "WWin.h"
#include "WEntry.h"
#include "WDefines.h"

class WContainer
{
public:
	static const HRESULT hResult(HRESULT hResult) { WContainer::HR = hResult; return WContainer::HR; }
	static const HRESULT hResult(void) { return WContainer::HR; }

	static const HWND Handle(HWND hWnd) { WContainer::hWnd = hWnd; return WContainer::hWnd; }
	static const HWND Handle(void) { return WContainer::hWnd; }

	static const UINT Message(UINT msg) { WContainer::msg = msg; return WContainer::msg; }
	static const UINT Message(void) { return WContainer::msg; }

	static const WPARAM WParam(WPARAM wParam) { WContainer::wParam = wParam; return WContainer::wParam; }
	static const WPARAM WParam(void) { return WContainer::wParam; }

	static const LPARAM LParam(LPARAM lParam) { WContainer::lParam = lParam; return WContainer::lParam; }
	static const LPARAM LParam(void) { return WContainer::lParam; }

	static const WEntry Framework(WEntry entry) { WContainer::WFramework = entry; return WContainer::WFramework; }
	static const WEntry Framework(void) { return WContainer::WFramework; }

	static const DELTATIME DeltaSeconds(DELTATIME seconds) { WContainer::DeltaTime = seconds; return WContainer::DeltaTime; }
	static const DELTATIME DeltaSeconds(void) { return WContainer::DeltaTime; }

	static const W_BYTE BackA(W_BYTE intake) { WContainer::BGA = intake; return WContainer::BGA; }
	static const W_BYTE BackA(void) { return WContainer::BGA; }

	static const W_BYTE BackR(W_BYTE intake) { WContainer::BGR = intake; return WContainer::BGR; }
	static const W_BYTE BackR(void) { return WContainer::BGR; }

	static const W_BYTE BackG(W_BYTE intake) { WContainer::BGG = intake; return WContainer::BGG; }
	static const W_BYTE BackG(void) { return WContainer::BGG; }

	static const W_BYTE BackB(W_BYTE intake) { WContainer::BGB = intake; return WContainer::BGB; }
	static const W_BYTE BackB(void) { return WContainer::BGB; }

	static const W_INT Width(W_INT intake) { WContainer::W_WIDTH = intake; return WContainer::W_WIDTH; }
	static const W_INT Width(void) { return WContainer::W_WIDTH; }

	static const W_INT Height(W_INT intake) { WContainer::W_HEIGHT = intake; return WContainer::W_HEIGHT; }
	static const W_INT Height(void) { return WContainer::W_HEIGHT; }

private:
	static HRESULT WContainer::HR;
	static HWND WContainer::hWnd;
	static UINT WContainer::msg;
	static WPARAM WContainer::wParam;
	static LPARAM WContainer::lParam;
	static WEntry WContainer::WFramework;
	static DELTATIME WContainer::DeltaTime;
	static W_BYTE WContainer::BGA;
	static W_BYTE WContainer::BGR;
	static W_BYTE WContainer::BGG;
	static W_BYTE WContainer::BGB;
	static W_INT WContainer::W_WIDTH;
	static W_INT WContainer::W_HEIGHT;
	
};


#endif // !_W_CONTAINER_H_