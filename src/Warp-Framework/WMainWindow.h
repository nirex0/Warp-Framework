// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_MAIN_WINDOW_H_
#define _W_MAIN_WINDOW_H_

#include "WEntry.h"
#include "WEntity.h"
#include "WWin.h"
#include "WDX.h"
#include "WDefines.h"
#include "WMouse.h"
#include "WKeyboard.h"
#include "WGraphics.h"

LRESULT WARP_CALL WindowsProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

class WMainWindow final : public WEntity
{
public:
	WMainWindow(HINSTANCE hInstance, LPWSTR WindowTitle, LPWSTR WindowName = L"MAIN_WINDOW");
	~WMainWindow(void);
	W_INT Initialize(void);
	void MessageLoop(void);
	LRESULT WProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:
	void SetGRegisters(void);

	HINSTANCE m_hAppInstance;
	WMouse* m_mouse;
	WKeyboard* m_keyboard;
	WEntry* m_entry;
	LPWSTR m_windowName;
	LPWSTR m_windowTitle;
	WUniqueRegister* m_OnGDIPaint;
	WGraphics* m_graphics;
};

static WMainWindow* MainWnd;

#endif // !_W_MAIN_WINDOW_H_
