// © 2018 NIREX ALL RIGHTS RESERVED

#include "WSWin.h"
#include "WSDefines.h"
#include "WSContainer.h"

// Initializing WSContainer members
WSEntry* WSContainer::EntryServer = {};

W_INT WARP_ENTRY wWinMain(
	HINSTANCE hInstance,			// UNUSED
	HINSTANCE hPrevInstance,		// UNUSED
	LPWSTR lpCmd,					// UNUSED
	INT cmdShow						// UNUSED
)
{
	UNREFERENCED_PARAMETER(hInstance);
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmd);
	UNREFERENCED_PARAMETER(cmdShow);

	return 0;
}