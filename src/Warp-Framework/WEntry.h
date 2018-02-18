//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_ENTRY_H_
#define _W_ENTRY_H_

#include "WEntity.h"
#include "WWin.h"  
#include "WMouse.h"
#include "WKeyboard.h"

class WEntry final : public WEntity
{
public:
	inline WEntry() : m_mouse(nullptr), m_keyboard(nullptr) {}
	void Start(void);
	void Update(double deltaTime);

	inline WEntry* SetWHandle(HWND hWnd) { this->hWnd = hWnd; return this; }
	inline HWND GetWHandle(void) const { return this->hWnd; }

	inline WEntry* SetWMessage(UINT msg) { this->msg = msg; return this; }
	inline UINT GetWMessage(void) const { return this->msg; }

	inline WEntry* SetWWParam(WPARAM wParam) { this->wParam = wParam; return this; }
	inline WPARAM GetWWParam(void) const { return this->wParam; }

	inline WEntry* SetWLParam(LPARAM lParam) { this->lParam = lParam; return this; }
	inline LPARAM GetWLParam(void) const { return this->lParam; }

	inline WMouse* GetWMouse(void) { return this->m_mouse; }
	inline WEntry* SetWMouse(WMouse* const intake) { this->m_mouse = intake; return this; };

	inline WKeyboard* GetWKeyboard(void) { return this->m_keyboard; }
	inline WEntry* SetWKeyboard(WKeyboard* const intake) { this->m_keyboard = intake; return this; };

private:
	WMouse* m_mouse;
	WKeyboard* m_keyboard;

	HWND hWnd;
	UINT msg;
	WPARAM wParam;
	LPARAM lParam;
};

#endif // _W_ENTRY_H_
