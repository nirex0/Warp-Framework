// © 2018 NIREX ALL RIGHTS RESERVED

#include "WCWin.h"
#include "WCDefines.h"
#include "WCContainer.h"
#include "WCSocket.h"
#include "WarpSock.h"
#include "WCNetworkAuxiliary.h"

#include <vector>
#include <memory>

std::vector<WCSocket> connections;

char* sendBuffer;
char* recvBuffer;

#define WS_DATA_SIZE 4096

// Initializing WSContainer members
WCEntry* WCContainer::EntryClient = {};

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
	std::unique_ptr<WCEntry> mainEntry = std::make_unique<WCEntry>(WCEntry());
	WCContainer::App(mainEntry.get());

}