// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _WS_SOCKET_H_
#define _WS_SOCKET_H_

#include <string>

#include "WSSock.h"
#include "WSDefines.h"

class WSSocket
{
public:
	WSSocket(std::string ip, int port, int bufferSize);
	~WSSocket(void);

	W_INT Bind(void);
	W_INT Listen(W_INT backLog);

	W_INT Accept(SOCKET clientSocket, int& outClientSize);
#ifndef PURE_SERVER
	W_INT Connect(void);
#endif
	W_INT Send(SOCKET fromSocket, char* inData, int dataLength);
	W_INT Receive(SOCKET fromSocket, char* outData, int& outLength);

	SOCKET Socket(void) const;
	WSADATA SocketData(void)const;

	W_INT Port(void) const;
	std::string IP(void) const;
	std::string Data(void) const;

private:
	W_INT CleanUp(void);

	W_INT m_port;
	std::string m_ip;

	std::string m_cleanedData;

	WSADATA m_data;
	SOCKET m_sock;
	char* m_buffer;
	W_INT m_bufferSize;
};

#endif // !_WS_SOCKET_H_