//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_ENTRY_H_
#define _W_ENTRY_H_

#include "WWin.h"  
#include "WDX.h"
#include "WEntity.h"
#include "WMouse.h"
#include "WKeyboard.h"
#include "WGraphics.h"
#include "WGFXContainer.h"


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
	void Update(DELTATIME deltaTime);
	void Render(DELTATIME deltaTime);

	inline WMouse* Mouse(void) { return m_mouse; }
	inline WEntry* Mouse(WMouse* const intake) { m_mouse = intake; return this; };

	inline WKeyboard* Keyboard(void) { return m_keyboard; }
	inline WEntry* Keyboard(WKeyboard* const intake) { m_keyboard = intake; return this; };

	inline WGraphics* Graphics(void) { return m_graphics; }
	inline WEntry* Graphics(WGraphics* const intake) { m_graphics = intake; return this; }
	
private:
	WMouse* m_mouse;
	WKeyboard* m_keyboard;
	WGraphics* m_graphics;

};

#endif // !_W_ENTRY_H_
