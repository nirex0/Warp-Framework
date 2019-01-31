// © 2019 NIREX ALL RIGHTS RESERVED

#include "WKeyboard.h"

WKeyboard::WKeyboard()
	: m_bAutorepeatEnabled(false)
{
	m_KeyDownReg = new WUniqueRegister();
	m_KeyUpReg = new WUniqueRegister();
	m_OnCharReg = new WUniqueRegister();
	SetGRegisters();
}

WKeyboard::WKeyboard(const WKeyboard& newKeyboard)
	: m_KeyDownReg(newKeyboard.m_KeyDownReg)
	, m_KeyUpReg(newKeyboard.m_KeyUpReg)
	, m_OnCharReg(newKeyboard.m_OnCharReg)
	, m_bAutorepeatEnabled(newKeyboard.m_bAutorepeatEnabled)
{
	SetGRegisters();
}

WKeyboard::~WKeyboard()
{
	delete m_KeyDownReg;
	delete m_KeyUpReg;
	delete m_OnCharReg;
}

WKeyboard* WKeyboard::RunKeyDown(void)
{
	WKeyboardArgs* ARGS = new WKeyboardArgs(this->m_lastKey);
	this->m_KeyDownReg->Run(this, ARGS);
	return this;
}

WKeyboard* WKeyboard::RunKeyUp(void)
{
	WKeyboardArgs* ARGS = new WKeyboardArgs(this->m_lastKey);
	this->m_KeyUpReg->Run(this, ARGS);
	return this;
}

WKeyboard* WKeyboard::RunOnChar(void)
{
	WKeyboardArgs* ARGS = new WKeyboardArgs(this->m_lastKey);
	this->m_OnCharReg->Run(this, ARGS);
	return this;
}

WKey WKeyboard::LastKey(void) const
{
	return this->m_lastKey;
}

WKeyboard* WKeyboard::LastKey(WKey intake)
{
	this->m_lastKey = intake;
	return this;
}

WUniqueRegister* WKeyboard::KeyDownRegistry(void)
{
	return this->m_KeyDownReg;
}

WKeyboard* WKeyboard::KeyDownRegistry(WUniqueRegister* const intake)
{
	this->m_KeyDownReg = intake;
	return this;
}

WUniqueRegister* WKeyboard::KeyUpRegistry(void)
{
	return this->m_KeyUpReg;
}

WKeyboard* WKeyboard::KeyUpRegistry(WUniqueRegister* const intake)
{
	this->m_KeyUpReg = intake;
	return this;
}

WUniqueRegister* WKeyboard::OnCharRegistry(void)
{
	return this->m_OnCharReg;
}

WKeyboard* WKeyboard::OnCharRegistry(WUniqueRegister* const intake)
{
	this->m_OnCharReg = intake;
	return this;
}

WKeyboard* WKeyboard::EnableAutorepeat(void)
{
	this->m_bAutorepeatEnabled = true;
	return this;
}

WKeyboard* WKeyboard::DisableAutorepeat(void)
{
	this->m_bAutorepeatEnabled = true;
	return this;
}

bool WKeyboard::AutorepeatIsEnabled(void) const
{

	return this->m_bAutorepeatEnabled;
}

void WKeyboard::SetGRegisters(void)
{
	WRegContainer::KeyboardKeyDown(m_KeyDownReg);
	WRegContainer::KeyboardKeyUp(m_KeyUpReg);
	WRegContainer::KeyboardOnChar(m_OnCharReg);
}
