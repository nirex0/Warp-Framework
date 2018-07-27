// © 2018 NIREX ALL RIGHTS RESERVED

#include "WSWin.h"
#include "WSDefines.h"
#include "WSContainer.h"

#include <memory>

// Initializing WSContainer members
WSEntry* WSContainer::EntryServer = {};

#ifndef CONSOLE
W_INT WARP_ENTRY wWinMain(
	HINSTANCE hInstance,			// UNUSED
	HINSTANCE hPrevInstance,		// UNUSED
	LPWSTR lpCmd,					// UNUSED
	INT cmdShow						// UNUSED
)
#endif // !CONSOLE
#ifdef CONSOLE
W_INT main(int argc, char** argv)
#endif //CONSOLE
{
#ifndef CONSOLE
	UNREFERENCED_PARAMETER(hInstance);
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmd);
	UNREFERENCED_PARAMETER(cmdShow);
#endif // !CONSOLE
	std::unique_ptr<WSEntry> mainEntry = std::make_unique<WSEntry>(WSEntry());
	WSContainer::App(mainEntry.get());
	
	mainEntry->Start();
	while (true)
	{
		mainEntry->Update();
	}

	return 0;
}