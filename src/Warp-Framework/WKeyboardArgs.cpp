// © 2018 NIREX ALL RIGHTS RESERVED

#include "WKeyboardArgs.h"

WKeyboardArgs::WKeyboardArgs(WKey key)
	: m_Key(key)
{
}

const WKey WKeyboardArgs::GetKey(void) const
{
	return this->m_Key;
}
