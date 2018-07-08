// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_SMOOTH_STEP_ARGS_H_
#define _W_SMOOTH_STEP_ARGS_H_

#include "WDefines.h"
#include "WEventArgs.h"

class WSmoothStepArgs : public WEventArgs
{
public:
	WSmoothStepArgs(W_FLOAT val);
	W_FLOAT ValueExact(void) const;
	W_INT ValueRounded(void) const;

private:
	W_FLOAT	m_Value;
};

#endif // !_W_SMOOTH_STEP_ARGS_H_
