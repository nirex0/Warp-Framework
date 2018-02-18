//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_KEYBOARD_H_
#define _W_KEYBOARD_H_

#include "WEntity.h"
#include "WRegistry.h"
#include "WKeyboardArgs.h"

typedef unsigned char WKey;

class WKeyboard final : WEntity
{
public:
	inline WKeyboard()
		: m_bAutorepeatEnabled(false)
	{
		m_KeyDownReg = new WRegistry();
		m_KeyUpReg = new WRegistry();
		m_NOnCharReg = new WRegistry();

	}

	inline WKeyboard(const WKeyboard& newKeyboard)
		: m_KeyDownReg(newKeyboard.m_KeyDownReg)
		, m_KeyUpReg(newKeyboard.m_KeyUpReg)
		, m_NOnCharReg(newKeyboard.m_NOnCharReg)
		, m_bAutorepeatEnabled(newKeyboard.m_bAutorepeatEnabled)
	{
	}

	inline ~WKeyboard()
	{
		delete m_KeyDownReg;
		delete m_KeyUpReg;
		delete m_NOnCharReg;
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

	inline WKeyboard* RunNOnChar(void)
	{
		WKeyboardArgs* ARGS = new WKeyboardArgs(this->m_lastKey);
		this->m_NOnCharReg->Run(this, ARGS);
		return this;
	}


	inline WKey GetLastKey(void) const
	{
		return this->m_lastKey;
	}

	inline WKeyboard* SetLastKey(WKey intake)
	{
		this->m_lastKey = intake;
		return this;
	}

	inline WRegistry* GetKeyDownRegistry(void)
	{
		return this->m_KeyDownReg;
	}

	inline WKeyboard* SetKeyDownRegistry(WRegistry* const intake)
	{
		this->m_KeyDownReg = intake;
		return this;
	}

	inline WRegistry* GetKeyUpRegistry(void)
	{
		return this->m_KeyUpReg;
	}

	inline WKeyboard* SetKeyUpRegistry(WRegistry* const intake)
	{
		this->m_KeyUpReg = intake;
		return this;
	}

	inline WRegistry* GetNOnCharRegistry(void)
	{
		return this->m_NOnCharReg;
	}

	inline WKeyboard* SetNOnCharRegistry(WRegistry* const intake)
	{
		this->m_NOnCharReg = intake;
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
	WRegistry* m_NOnCharReg;

};

#endif // _W_KEYBOARD_H_
