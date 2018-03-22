//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_CONTAINER_H_
#define _W_CONTAINER_H_

#include "WWin.h"
#include "WEntry.h"

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

private:
	static HRESULT WContainer::HR;
	static HWND WContainer::hWnd;
	static UINT WContainer::msg;
	static WPARAM WContainer::wParam;
	static LPARAM WContainer::lParam;
	static WEntry WContainer::WFramework;
	static DELTATIME WContainer::DeltaTime;
};


#endif // !_W_CONTAINER_H_