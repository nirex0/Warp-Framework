// © 2018 NIREX ALL RIGHTS RESERVED

#include "WContainer.h"
#include "WControlHandler.h"
#include "WRadioButtonHandler.h"

// These needs to be initialized before everything else
std::map<W_INT, IControl*> WControlHandler::mtcp = {};
std::set<WRadioButton*> WRadioButtonHandler::strz = {};
std::set<W_INT> WControlHandler::stcz = {};
WTheme WContainer::wTheme = {};

//Runs at the start of the application
void WEntry::Start(void)
{
}

//Runs every frame pre-render
void WEntry::Update(DELTATIME deltaTime)
{
}

//Runs every frame post-update
void WEntry::Render(DELTATIME deltaTime)
{
}
