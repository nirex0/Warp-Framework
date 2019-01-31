// © 2019 NIREX ALL RIGHTS RESERVED

#include "WSeekBarValueChangeArgs.h"

WSeekBarValueChangeArgs::WSeekBarValueChangeArgs(W_FLOAT input)
{
	m_value = input;
}

W_FLOAT WSeekBarValueChangeArgs::Value(void) const
{
	return m_value;
}
