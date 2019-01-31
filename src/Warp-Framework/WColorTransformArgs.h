// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_COLOR_TRANSFORM_ARGS_H_
#define _W_COLOR_TRANSFORM_ARGS_H_

#include "WDefines.h"
#include "WEventArgs.h"
#include "WDX.h"

//-->DOC_CLASS
// Arguments passed through the WColorTransform Registry classes
class WColorTransformArgs : public WEventArgs
{
public:
	//-->DOC_FUNC
	// col: Argument value to be passed through the WColorTransform Registry
	// Constructor of the WColorTransformArgs class
	WColorTransformArgs(W_COLOR col);
	//-->DOC_FUNC
	// Value Getter function
	W_COLOR Value(void) const;

private:
	//-->DOC_MEMBER
	// Value of the color to be sent through the WColorTransform Registry
	W_COLOR	m_Value;
};

#endif // !_W_COLOR_TRANSFORM_ARGS_H_
