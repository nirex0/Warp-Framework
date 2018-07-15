// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_TEXT_H_
#define _W_TEXT_H_

#include <cassert>

template <typename T>
class WTest final
{
public:
	static void WTestEQ(T e0, T e1)
	{
		assert(e0 == e1);
	}

	static void WTestNE(T e0, T e1)
	{
		assert(e0 != e1);
	}

	static void WTestBEQ(T e0, T e1)
	{
		assert(e0 & e1);
	}

	static void WTestBNEQ(T e0, T e1)
	{
		assert(e0 !& e1);
	}

};

#endif // !_W_TEXT_H_