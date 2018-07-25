// © 2018 NIREX ALL RIGHTS RESERVED

#include "WSContainer.h"

WSEntry* WSContainer::App(void) const
{
	return EntryServer;
}

WSEntry* WSContainer::App(WSEntry* intake)
{
	EntryServer = intake;
	return EntryServer;
}
