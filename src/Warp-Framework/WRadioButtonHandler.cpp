// © 2019 NIREX ALL RIGHTS RESERVED

#include "WRadioButtonHandler.h"

void WRadioButtonHandler::Add(WRadioButton* intake)
{
	strz.emplace(intake);
}

void WRadioButtonHandler::Remove(WRadioButton* intake)
{
	strz.erase(intake);
}

void WRadioButtonHandler::Deactive(std::wstring group)
{
	for (const auto& p : strz)
	{
		if (p->Group() == group)
			p->Checked(false);
	}
}
