//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_KEYBOARD_H_
#define _W_KEYBOARD_H_

#include "WEntity.h"
#include "WRegistry.h"
#include "WKeyboardArgs.h"

typedef W_BYTE WKey;

class WKeyboard final : WEntity
{
public:
	inline WKeyboard()
		: m_bAutorepeatEnabled(false)
	{
		m_KeyDownReg = new WRegistry();
		m_KeyUpReg = new WRegistry();
		m_OnCharReg = new WRegistry();

	}

	inline WKeyboard(const WKeyboard& newKeyboard)
		: m_KeyDownReg(newKeyboard.m_KeyDownReg)
		, m_KeyUpReg(newKeyboard.m_KeyUpReg)
		, m_OnCharReg(newKeyboard.m_OnCharReg)
		, m_bAutorepeatEnabled(newKeyboard.m_bAutorepeatEnabled)
	{
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

	inline WRegistry* KeyDownRegistry(void)
	{
		return this->m_KeyDownReg;
	}

	inline WKeyboard* KeyDownRegistry(WRegistry* const intake)
	{
		this->m_KeyDownReg = intake;
		return this;
	}

	inline WRegistry* KeyUpRegistry(void)
	{
		return this->m_KeyUpReg;
	}

	inline WKeyboard* KeyUpRegistry(WRegistry* const intake)
	{
		this->m_KeyUpReg = intake;
		return this;
	}

	inline WRegistry* OnCharRegistry(void)
	{
		return this->m_OnCharReg;
	}

	inline WKeyboard* OnCharRegistry(WRegistry* const intake)
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
	bool m_bAutorepeatEnabled;

	WKey m_lastKey;

	WRegistry* m_KeyDownReg;
	WRegistry* m_KeyUpReg;
	WRegistry* m_OnCharReg;

};

#endif // _W_KEYBOARD_H_
