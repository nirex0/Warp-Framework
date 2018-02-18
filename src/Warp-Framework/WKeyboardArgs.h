//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_KEYBOARD_ARGS_H_
#define _W_KEYBOARD_ARGS_H_

#include "WEventArgs.h"

typedef unsigned char NKey;

class WKeyboardArgs : public WEventArgs
{
public:
	WKeyboardArgs(NKey key);
	~WKeyboardArgs();

	const NKey GetKey(void) const;

private:
	NKey m_Key;
};

#endif // _W_KEYBOARD_ARGS_H_
