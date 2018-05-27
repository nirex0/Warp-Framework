//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_LERP_ARGS_H_
#define _W_LERP_ARGS_H_

#include "WDefines.h"
#include "WEventArgs.h"

class WLerpArgs : public WEventArgs
{
public:
	WLerpArgs(W_FLOAT val)
		: m_Value(val)
	{
	}

	W_FLOAT ValueExact(void) const
	{
		return m_Value;
	}

	W_INT ValueRounded(void) const
	{
		return (W_INT)m_Value;
	}

private:
	W_FLOAT	m_Value;
};

#endif // !_W_LERP_ARGS_H_
