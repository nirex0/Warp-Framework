//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_KEYBOARD_H_
#define _W_KEYBOARD_H_

#include "WEntity.h"
#include "WUniqueRegister.h"
#include "WKeyboardArgs.h"
#include "WRegContainer.h"

typedef W_BYTE WKey;

class WKeyboard final : public WEntity
{
public:
	inline WKeyboard()
		: m_bAutorepeatEnabled(false)
	{
		m_KeyDownReg = new WUniqueRegister();
		m_KeyUpReg = new WUniqueRegister();
		m_OnCharReg = new WUniqueRegister();
		SetGRegisters();
	}

	inline WKeyboard(const WKeyboard& newKeyboard)
		: m_KeyDownReg(newKeyboard.m_KeyDownReg)
		, m_KeyUpReg(newKeyboard.m_KeyUpReg)
		, m_OnCharReg(newKeyboard.m_OnCharReg)
		, m_bAutorepeatEnabled(newKeyboard.m_bAutorepeatEnabled)
	{
		SetGRegisters();
	}

	inline ~WKeyboard()
	{
		delete m_KeyDownReg;
		delete m_KeyUpReg;
		delete m_OnCharReg;
	}

	inline WKeyboard* RunKeyDown(void)
	{
		WKeyboardArgs* ARGS = new WKeyboardArgs(this->m_lastKey);
		this->m_KeyDownReg->Run(this, ARGS);
		return this;
	}

	inline WKeyboard* RunKeyUp(void)
	{
		WKeyboardArgs* ARGS = new WKeyboardArgs(this->m_lastKey);
		this->m_KeyUpReg->Run(this, ARGS);
		return this;
	}

	inline WKeyboard* RunOnChar(void)
	{
		WKeyboardArgs* ARGS = new WKeyboardArgs(this->m_lastKey);
		this->m_OnCharReg->Run(this, ARGS);
		return this;
	}


	inline WKey LastKey(void) const
	{
		return this->m_lastKey;
	}

	inline WKeyboard* LastKey(WKey intake)
	{
		this->m_lastKey = intake;
		return this;
	}

	inline WUniqueRegister* KeyDownRegistry(void)
	{
		return this->m_KeyDownReg;
	}

	inline WKeyboard* KeyDownRegistry(WUniqueRegister* const intake)
	{
		this->m_KeyDownReg = intake;
		return this;
	}

	inline WUniqueRegister* KeyUpRegistry(void)
	{
		return this->m_KeyUpReg;
	}

	inline WKeyboard* KeyUpRegistry(WUniqueRegister* const intake)
	{
		this->m_KeyUpReg = intake;
		return this;
	}

	inline WUniqueRegister* OnCharRegistry(void)
	{
		return this->m_OnCharReg;
	}

	inline WKeyboard* OnCharRegistry(WUniqueRegister* const intake)
	{
		this->m_OnCharReg = intake;
		return this;
	}

	inline WKeyboard* EnableAutorepeat(void)
	{
		this->m_bAutorepeatEnabled = true;
		return this;
	}

	inline WKeyboard* DisableAutorepeat(void)
	{
		this->m_bAutorepeatEnabled = true;
		return this;
	}

	inline bool AutorepeatIsEnabled(void) const
	{

		return this->m_bAutorepeatEnabled;
	}

private:
	void SetGRegisters(void)
	{
		WRegContainer::KeyboardKeyDown(m_KeyDownReg);
		WRegContainer::KeyboardKeyUp(m_KeyUpReg);
		WRegContainer::KeyboardOnChar(m_OnCharReg);
	}

	bool m_bAutorepeatEnabled;

	WKey m_lastKey;

	WUniqueRegister* m_KeyDownReg;
	WUniqueRegister* m_KeyUpReg;
	WUniqueRegister* m_OnCharReg;

};

#endif // !_W_KEYBOARD_H_
