// © 2018 NIREX ALL RIGHTS RESERVED

#include "WTestAuxiliary.h"

void WTestAuxiliary::Add(WTestRegistry* intake)
{
	stwp.emplace(intake);
}

void WTestAuxiliary::Remove(WTestRegistry* intake)
{
	stwp.erase(intake);
}

void WTestAuxiliary::Run(void)
{
	for (const auto &p : stwp)
	{
		p->TestEqual();
	}
}
