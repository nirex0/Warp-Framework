// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_KEYBOARD_H_
#define _W_KEYBOARD_H_

#include "WEntity.h"
#include "WUniqueRegister.h"
#include "WKeyboardArgs.h"
#include "WRegContainer.h"
#include "WDefines.h"

typedef W_BYTE WKey;

class WKeyboard final : public WEntity
{
public:
	WKeyboard();
	WKeyboard(const WKeyboard& newKeyboard);
	~WKeyboard();

	WKeyboard* RunKeyDown(void);
	WKeyboard* RunKeyUp(void);
	WKeyboard* RunOnChar(void);

	WKey LastKey(void) const;
	WKeyboard* LastKey(WKey intake);

	WUniqueRegister* KeyDownRegistry(void);
	WKeyboard* KeyDownRegistry(WUniqueRegister* const intake);

	WUniqueRegister* KeyUpRegistry(void);
	WKeyboard* KeyUpRegistry(WUniqueRegister* const intake);

	WUniqueRegister* OnCharRegistry(void);
	WKeyboard* OnCharRegistry(WUniqueRegister* const intake);

	WKeyboard* EnableAutorepeat(void);
	WKeyboard* DisableAutorepeat(void);

	bool AutorepeatIsEnabled(void) const;

private:
	void SetGRegisters(void);

	bool m_bAutorepeatEnabled;

	WKey m_lastKey;

	WUniqueRegister* m_KeyDownReg;
	WUniqueRegister* m_KeyUpReg;
	WUniqueRegister* m_OnCharReg;

};

#endif // !_W_KEYBOARD_H_
