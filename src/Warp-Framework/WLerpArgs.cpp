// © 2019 NIREX ALL RIGHTS RESERVED

#include "WLerpArgs.h"

WLerpArgs::WLerpArgs(W_FLOAT val)
	: m_Value(val)
{
}

W_FLOAT WLerpArgs::ValueExact(void) const
{
	return m_Value;
}

W_INT WLerpArgs::ValueRounded(void) const
{
	return (W_INT)m_Value;
}