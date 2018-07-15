// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_TEST_AUXILIARY_H_
#define _W_TEST_AUXILIARY_H_

#include "WTestRegistry.h"

#include <set>

class WTestAuxiliary
{
public:
	static void Add(WTestRegistry* intake);
	static void Remove(WTestRegistry* intake);
	static void Run(void);

private:
	static std::set<WTestRegistry*> WTestAuxiliary::stwp;
};

#endif // !_W_TEST_AUXILIARY_H_
