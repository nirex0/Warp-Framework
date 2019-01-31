// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_SMOOTH_STEP_ARGS_H_
#define _W_SMOOTH_STEP_ARGS_H_

#include "WDefines.h"
#include "WEventArgs.h"

//-->DOC_CLASS
// Arguments passed through the WSmoothStep Registry classes
class WSmoothStepArgs : public WEventArgs
{
public:	
	//-->DOC_FUNC
	// val: Argument value to be passed through the WSmoothStep Registry
	// Constructor of the WSmoothStepArgs class
	WSmoothStepArgs(W_FLOAT val);

	//-->DOC_FUNC
	// Value Getter function (With Precision)
	W_FLOAT ValueExact(void) const;

	//-->DOC_FUNC
	// Value Getter function (Rounded)
	W_INT ValueRounded(void) const;

private:
	//-->DOC_MEMBER
	// Value to be sent through the WSmoothStep Registry
	W_FLOAT	m_Value;
};

#endif // !_W_SMOOTH_STEP_ARGS_H_
