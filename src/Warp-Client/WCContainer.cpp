// © 2018 NIREX ALL RIGHTS RESERVED

#include "WCContainer.h"

WCEntry* WCContainer::App(void)
{
	return EntryClient;
}

WCEntry* WCContainer::App(WCEntry* intake)
{
	EntryClient = intake;
	return EntryClient;
}
