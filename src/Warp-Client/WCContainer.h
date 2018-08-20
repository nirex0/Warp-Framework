// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _WC_CONTAINER_H_
#define _WC_CONTAINER_H_

#include "WCEntry.h"

class WCContainer
{
public:
	static WCEntry* App(void);
	static WCEntry* App(WCEntry* intake);

private:
	static WCEntry* EntryClient;
};

#endif // !_WC_CONTAINER_H_