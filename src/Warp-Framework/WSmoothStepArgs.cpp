// © 2019 NIREX ALL RIGHTS RESERVED

#include "WSmoothStepArgs.h"

WSmoothStepArgs::WSmoothStepArgs(W_FLOAT val)
	: m_Value(val)
{
}

W_FLOAT WSmoothStepArgs::ValueExact(void) const
{
	return m_Value;
}

W_INT WSmoothStepArgs::ValueRounded(void) const
{
	return (W_INT)m_Value;
}