// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _WC_SOCKET_H_
#define _WC_SOCKET_H_

#include <string>

#include "WCEntity.h"
#include "WCRegistry.h"
#include "WCSock.h"
#include "WCDefines.h"

class WCSocket : public WCEntity
{
public:
	WCSocket(void);
	WCSocket(std::string ip, int port, int bufferSize);
	~WCSocket(void);

	W_INT Accept(int& outClientSize);
	W_INT Bind(void);
	W_INT Connect(void);
	W_INT Listen(W_INT backLog = 0);
	W_INT Receive(char* outData, int& lengthTransfer);
	W_INT Send(char* inData, int& lengthTraBnsfer);

	SOCKET Socket(void) const;
	void Socket(SOCKET s);
	WSADATA SocketData(void)const;

	W_INT Port(void) const;
	std::string IP(void) const;
	std::string Data(void) const;
	bool SockCount(void) const;

private:
	W_INT CleanUp(void);

	WCRegistry* m_AcceptReg;
	WCRegistry* m_BindReg;
	WCRegistry* m_ConnectReg;
	WCRegistry* m_ListenReg;
	WCRegistry* m_ReceiveReg;
	WCRegistry* m_SendReg;

	std::string m_ip;
	W_INT m_port;

	WSADATA m_data;
	SOCKET m_sock;

	W_INT m_bufferSize;
	char* m_recvBuffer;
	char* m_sendBuffer;

	std::string m_cleanedData;

	static int m_sockCount;
	static bool m_bIsStarted;
};

#endif // !_WC_SOCKET_H_