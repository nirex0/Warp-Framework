// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_RADIO_BUTTON_HANDLER_H_
#define _W_RADIO_BUTTON_HANDLER_H_

#include "WRadioButton.h"

#include <set>
#include <utility>

class WRadioButtonHandler
{
public:
	static void Add(WRadioButton* intake);
	static void Remove(WRadioButton* intake);
	static void Deactive(std::wstring group);

private:
	static std::set<WRadioButton*> WRadioButtonHandler::strz;

};

#endif // !_W_RADIO_BUTTON_HANDLER_H_