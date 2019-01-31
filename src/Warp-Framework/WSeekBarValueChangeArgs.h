// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_SEEK_BAR_VALUECHANGE_ARGS_H_
#define _W_SEEK_BAR_VALUECHANGE_ARGS_H_

#include "WEventArgs.h"
#include "WDefines.h"

class WSeekBarValueChangeArgs : public WEventArgs
{
public:
	WSeekBarValueChangeArgs(W_FLOAT input);
	~WSeekBarValueChangeArgs() = default;
	
	W_FLOAT Value(void) const;

private:
	W_FLOAT m_value;
};

#endif // !_W_SEEK_BAR_VALUECHANGE_ARGS_H_
