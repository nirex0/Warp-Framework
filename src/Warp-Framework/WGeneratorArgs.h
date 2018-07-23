// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_GENERATOR_ARGS_H_
#define _W_GENERATOR_ARGS_H_

#include "WEventArgs.h"
#include "WDefines.h"

template <class T>
class WGeneratorArgs : public WEventArgs
{
public:
	WGeneratorArgs(W_INT iteration, T value = {})
		: m_valueHeld(value)
		, m_iterationCount(iteration)
	{
	}

	bool HasValue(void) const
	{
		return (m_valueHeld != {});
	}

	T Value(void) const
	{
		return m_valueHeld;
	}

	W_INT Iteration(void) const
	{
		return m_iterationCount;
	}

private:
	T m_valueHeld;
	W_INT m_iterationCount;
};

#endif // !_W_GENERATOR_ARGS_H_