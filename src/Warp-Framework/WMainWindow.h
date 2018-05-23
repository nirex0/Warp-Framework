//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_MAIN_WINDOW_H_
#define _W_MAIN_WINDOW_H_

#include "WWin.h"
#include "WDX.h"
#include "WEntity.h"
#include "WMouse.h"
#include "WKeyboard.h"
#include "WEntry.h"
#include "WDefines.h"
#include "WUserSettings.h"
#include "WRegContainer.h"
#include "WContainer.h"
#include "WSafeRelease.h"
#include "WGDIPaintEventArgs.h"
#include "WDXContainer.h"
#include "WGraphics.h"
#include "WGFXContainer.h"
#include "WControlHandler.h"
#include "WChrono.h"
#include "WAlgorithm.h"

LRESULT WARP_CALL WindowsProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

class WMainWindow final : public WEntity
{
public:
	// Ctor
	WMainWindow(HINSTANCE hInstance, LPWSTR WindowTitle, LPWSTR WindowName = L"MAIN_WINDOW");

	// Dtor
	~WMainWindow(void);

	// Init the first window
	W_INT Initialize(void);

	// Main message loop handler
	void MessageLoop(void);

	// WinProc
	LRESULT WProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:
	void SetGRegisters(void);

	// ---Win32 Members--- //
	HINSTANCE m_hAppInstance;

	// Devices
	WMouse* m_mouse;
	WKeyboard* m_keyboard;

	// Main entry class
	WEntry* m_entry;

	LPWSTR m_windowName;
	LPWSTR m_windowTitle;

	WUniqueRegister* m_OnGDIPaint;
	WGraphics* m_graphics;
};

WMainWindow* MainWnd;

#endif // !_W_MAIN_WINDOW_H_
