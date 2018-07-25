// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _WS_CONTAINER_H_
#define _WS_CONTAINER_H_

#include "WSEntry.h"

class WSContainer
{
public:
	WSEntry* App(void) const;
	WSEntry* App(WSEntry* intake);

private:
	static WSEntry* EntryServer;
};

#endif // !_WS_CONTAINER_H_