//© 2018 NIREX ALL RIGHTS RESERVED

#include "WEntry.h"

WEntry* G_CurrInstance;

//Runs at the start of the application
void WEntry::Start(void)
{
	G_CurrInstance = this;
	
}

//Runs every frame
void WEntry::Update(double deltaTime)
{

}
