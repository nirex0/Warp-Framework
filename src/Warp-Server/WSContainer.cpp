// © 2018 NIREX ALL RIGHTS RESERVED

#include "WSContainer.h"

WSEntry* WSContainer::App(void)
{
	return EntryServer;
}

WSEntry* WSContainer::App(WSEntry* intake)
{
	EntryServer = intake;
	return EntryServer;
}
