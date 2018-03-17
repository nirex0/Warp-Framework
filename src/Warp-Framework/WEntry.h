//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_ENTRY_H_
#define _W_ENTRY_H_

#include "WContainer.h"
#include "WEntity.h"
#include "WWin.h"  
#include "WMouse.h"
#include "WKeyboard.h"

class WEntry final : public WEntity
{
public:
	inline WEntry() : m_mouse(nullptr), m_keyboard(nullptr) {}
	inline ~WEntry()
	{
		delete m_mouse;
		delete m_keyboard;
	}

	void Start(void);
	void Update(double deltaTime);

	inline WMouse* Mouse(void) { return this->m_mouse; }
	inline WEntry* Mouse(WMouse* const intake) { this->m_mouse = intake; return this; };

	inline WKeyboard* Keyboard(void) { return this->m_keyboard; }
	inline WEntry* Keyboard(WKeyboard* const intake) { this->m_keyboard = intake; return this; };

private:
	WMouse* m_mouse;
	WKeyboard* m_keyboard;
};

#endif // _W_ENTRY_H_
