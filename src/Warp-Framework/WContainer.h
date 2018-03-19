//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_CONTAINER_H_
#define _W_CONTAINER_H_

#include "WWin.h"
#include "WEntry.h"

class WContainer
{
public:
	static void hResult(HRESULT hResult) { WContainer::HR = hResult; }
	static const HRESULT hResult(void) { return WContainer::HR; }

	static void Handle(HWND hWnd) { WContainer::hWnd = hWnd; }
	static const HWND Handle(void) { return WContainer::hWnd; }

	static void Message(UINT msg) { WContainer::msg = msg; }
	static const UINT Message(void) { return WContainer::msg; }

	static void WParam(WPARAM wParam) { WContainer::wParam = wParam; }
	static const WPARAM WParam(void) { return WContainer::wParam; }

	static void LParam(LPARAM lParam) { WContainer::lParam = lParam; }
	static const LPARAM LParam(void) { return WContainer::lParam; }

	static void Framework(WEntry entry) { WContainer::WFramework = entry; }
	static const WEntry Framework(void) { return WContainer::WFramework; }

	static void DeltaSeconds(DELTATIME seconds) { WContainer::DeltaTime = seconds; }
	static DELTATIME DeltaSeconds(void) { return WContainer::DeltaTime;}


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