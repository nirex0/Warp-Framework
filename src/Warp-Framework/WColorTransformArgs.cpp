// © 2018 NIREX ALL RIGHTS RESERVED

#include "WColorTransformArgs.h"

WColorTransformArgs::WColorTransformArgs(W_COLOR col)
	: m_val(col)
{
}

W_COLOR WColorTransformArgs::Value(void) const
{
	return m_val;
}