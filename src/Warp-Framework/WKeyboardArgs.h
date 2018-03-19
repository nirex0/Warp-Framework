//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_KEYBOARD_ARGS_H_
#define _W_KEYBOARD_ARGS_H_

#include "WEventArgs.h"

typedef unsigned char WKey;

class WKeyboardArgs : public WEventArgs
{
public:
	WKeyboardArgs(WKey key)
		: m_Key(key)
	{
	}

	~WKeyboardArgs()
	{
	}

	const WKey GetKey(void) const
	{
		return this->m_Key;
	}

private:
	WKey m_Key;
};

#endif // !_W_KEYBOARD_ARGS_H_
