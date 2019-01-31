// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_LERP_ARGS_H_
#define _W_LERP_ARGS_H_

#include "WDefines.h"
#include "WEventArgs.h"

//-->DOC_CLASS
// Arguments passed through the WLerp Registry classes
class WLerpArgs : public WEventArgs
{
public:
	//-->DOC_FUNC
	// val: Argument value to be passed through the WLerp Registry
	// Constructor of the WLerpArgs class
	WLerpArgs(W_FLOAT val);

	//-->DOC_FUNC
	// Value Getter function (With Precision)
	W_FLOAT ValueExact(void) const;

	//-->DOC_FUNC
	// Value Getter function (Rounded)
	W_INT ValueRounded(void) const;

private:
	//-->DOC_MEMBER
	// Value to be sent through the WLerp Registry
	W_FLOAT	m_Value;
};

#endif // !_W_LERP_ARGS_H_
