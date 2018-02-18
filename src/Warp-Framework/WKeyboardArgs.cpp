//© 2018 NIREX ALL RIGHTS RESERVED

#include "WKeyboardArgs.h"

WKeyboardArgs::WKeyboardArgs(NKey key)
	: m_Key(key)
{
}

WKeyboardArgs::~WKeyboardArgs()
{
}

const NKey WKeyboardArgs::GetKey(void) const
{
	return this->m_Key;
}
