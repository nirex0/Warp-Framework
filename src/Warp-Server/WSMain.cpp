// © 2018 NIREX ALL RIGHTS RESERVED

#include "WSWin.h"
#include "WSDefines.h"
#include "WSContainer.h"
#include "WSSocket.h"
#include "WarpSock.h"
#include "WSNetworkAuxiliary.h"

#include <vector>
#include <memory>

std::vector<WSSocket> connections;

char* sendBuffer;
char* recvBuffer;

#define WS_DATA_SIZE 4096

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

	sendBuffer = new char[WS_DATA_SIZE];
	recvBuffer = new char[WS_DATA_SIZE];

	WSADATA WsaDat;
	if (WSAStartup(MAKEWORD(2, 2), &WsaDat) != 0)
	{
		// Initialization failure
		WSACleanup();
		system("PAUSE");
		return 1;
	}

	SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (listenSocket == INVALID_SOCKET)
	{
		// Socket creation failure
		WSACleanup();
		system("PAUSE");
		return 2;
	}

	std::string ip = "127.0.0.1";
	SOCKADDR_IN serverInf;
	serverInf.sin_family = AF_INET;
	serverInf.sin_port = htons(42422);
	WSHELPERS::w_inet_pton(AF_INET, ip.c_str(), &serverInf.sin_addr);

	if (bind(listenSocket, (SOCKADDR*)(&serverInf), sizeof(serverInf)) == SOCKET_ERROR)
	{
		// Binding failure
		WSACleanup();
		system("PAUSE");
		return 3;
	}


	listen(listenSocket, SOMAXCONN);

	u_long iMode = 1;
	ioctlsocket(listenSocket, FIONBIO, &iMode);

	FD_SET readfds;
	FD_SET writefds;
	FD_SET exceptfds;

	timeval timeout;
	timeout.tv_usec = 0.5 * 1000000;
	timeout.tv_sec = 0;
	
	mainEntry->Start();
	while (true)
	{
		FD_ZERO(&readfds);
		FD_ZERO(&writefds);
		FD_ZERO(&exceptfds);

		FD_SET(listenSocket, &readfds);
		FD_SET(listenSocket, &exceptfds);

		for (int i = 0; i < connections.size(); i++)
		{
			FD_SET(connections[i].Socket(), &readfds);
			FD_SET(connections[i].Socket(), &writefds);
			FD_SET(connections[i].Socket(), &exceptfds);
		}

		select(0, &readfds, &writefds, &exceptfds, &timeout);

		if (FD_ISSET(listenSocket, &exceptfds))
		{
			closesocket(listenSocket);
			for (int i = 0; i < connections.size(); i++)
			{
				closesocket(connections[i].Socket());
				break;
			}
		}

		if (FD_ISSET(listenSocket, &readfds))
		{
			WSSocket newConnection;
			newConnection.Socket(accept(listenSocket, NULL, NULL));
			if (newConnection.Socket() != INVALID_SOCKET)
			{
				// CONNECTION ESTABLISHED
				connections.push_back(newConnection);
			}
			else
			{
				// CONNECTION FAILED
			}
		}

		for (int i = 0; i < connections.size(); i++)
		{
			if (FD_ISSET(connections[i].Socket(), &exceptfds))
			{
				closesocket(connections[i].Socket());
				connections.erase(connections.begin() + i);
				i -= i;
				continue;
			}

			if (FD_ISSET(connections[i].Socket(), &readfds))
			{
				int valHolder = 0;
				int retVal = connections[i].Receive(recvBuffer, valHolder);
				if (retVal == SOCKET_ERROR)
				{
					if (WSAGetLastError() != WSAEWOULDBLOCK)
					{
						// Connection was closed
						closesocket(connections[i].Socket());
						connections.erase(connections.begin() + i);
						i -= i;
						continue;
					}
				}
				if (retVal == 0)
				{
					// Connection was closed
					closesocket(connections[i].Socket());
					connections.erase(connections.begin() + i);
					i -= i;
					continue;
				}
			}

			if (FD_ISSET(connections[i].Socket(), &writefds))
			{
				//SEND DATA HERE
				int valHolder = 0;
				int retVal = connections[i].Send(sendBuffer, valHolder);

			}
		}

		mainEntry->Update();
	}

	WSACleanup();
	return 0;
}