// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_TEST_H_
#define _W_TEST_H_

#include "WDefines.h"
#include <cassert>

template <typename T>
class WTest final
{
public:
	static void WTestEQ(T e0, T e1)
	{
#ifdef WDBG  
		assert(e0 == e1);
#endif
	}

	static void WTestNE(T e0, T e1)
	{
#ifdef WDBG
		assert(e0 != e1);
#endif
	}

	static void WTestBINEQ(T e0, T e1)
	{
#ifdef WDBG
		assert(e0 & e1);
#endif
	}

	static void WTestBINNEQ(T e0, T e1)
	{
#ifdef WDBG
		assert(e0 !& e1);
#endif
	}

};

#endif // !_W_TEST_H_