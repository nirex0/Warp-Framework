// © 2018 NIREX ALL RIGHTS RESERVED

#include "WSSocket.h"
#include "WSSocketArgs.h"
#include "WarpSock.h"
#include <memory>

int WSSocket::m_sockCount = 0;
bool WSSocket::m_bIsStarted = false;

WSSocket::WSSocket(void)
	: m_ip("")
	, m_port(0)
	, m_bufferSize(0)
{
}

WSSocket::WSSocket(std::string ip, int port, int bufferSize)
	: m_ip(ip)
	, m_port(port)
	, m_bufferSize(bufferSize)
{
	m_sendBuffer = new char[m_bufferSize];
	m_recvBuffer = new char[m_bufferSize];
	WORD version = MAKEWORD(2, 2);

	if (!m_sockCount)
	{
		m_bIsStarted = true;
		WSAStartup(version, &m_data);
	}

	m_sockCount++;
	m_sock = socket(IPV4, SOCK_STREAM, 0);

	W_ULONG mode = 1;  
	ioctlsocket(m_sock, FIONBIO, &mode);

	m_AcceptReg = new WSRegistry();
	m_BindReg = new WSRegistry();
	m_ConnectReg = new WSRegistry();
	m_ListenReg = new WSRegistry();
	m_ReceiveReg = new WSRegistry();
	m_SendReg = new WSRegistry();
}

WSSocket::~WSSocket(void)
{
	delete m_AcceptReg;
	delete m_BindReg;
	delete m_ConnectReg;
	delete m_ListenReg;
	delete m_ReceiveReg;
	delete m_SendReg;

	CleanUp();
}

W_INT WSSocket::Accept(int& outClientSize)
{
	SOCKET newConnection;

	sockaddr_in client;
	int clientSize = sizeof(client);

	newConnection = accept(m_sock, (sockaddr*)&client, &clientSize);
	outClientSize = clientSize;
	
	std::unique_ptr<WSSocketArgs> args = std::make_unique<WSSocketArgs>(WSSocketArgs(newConnection, nullptr, 0));
	m_AcceptReg->Run(this, args.get());
	
	return (newConnection == INVALID_SOCKET);
}

W_INT WSSocket::Bind(void)
{
	sockaddr_in hint;
	hint.sin_family = IPV4;
	hint.sin_port = htons(m_port);
	inet_pton(IPV4, m_ip.c_str(), &hint.sin_addr);

	int retI = bind(m_sock, (sockaddr*)&hint, sizeof(hint));

	std::unique_ptr<WSSocketArgs> args = std::make_unique<WSSocketArgs>(WSSocketArgs(m_sock, nullptr, 0));
	m_BindReg->Run(this, args.get());

	return retI;
}

W_INT WSSocket::Connect(void)
{
	sockaddr_in hint;
	hint.sin_family = IPV4;
	hint.sin_port = htons(m_port);
	inet_pton(IPV4, m_ip.c_str(), &hint.sin_addr);

	int connResult = connect(m_sock, (sockaddr*)&hint, sizeof(hint));
	if (connResult == SOCKET_ERROR)
	{
		CleanUp();
		return SOCKET_ERROR;
	}

	std::unique_ptr<WSSocketArgs> args = std::make_unique<WSSocketArgs>(WSSocketArgs(m_sock, nullptr, 0));
	m_ConnectReg->Run(this, args.get());

	return connResult;
}

W_INT WSSocket::Listen(W_INT backLog)
{
	int retI = listen(m_sock, backLog);

	std::unique_ptr<WSSocketArgs> args = std::make_unique<WSSocketArgs>(WSSocketArgs(m_sock, nullptr, 0));
	m_ListenReg->Run(this, args.get());

	return retI;
}

W_INT WSSocket::Receive(char* outData, int& lengthTransfer)
{
	int bytesReceived = 0;
	while (lengthTransfer > 0) 
	{
		int bytesRequested = (lengthTransfer > m_bufferSize) ? m_bufferSize : lengthTransfer;
		int recvValue = recv(m_sock, outData + bytesReceived, bytesRequested, 0);
		if (recvValue == -1 || recvValue == 0 || recvValue == SOCKET_ERROR)
		{
			return recvValue;
		}
		bytesReceived += recvValue;
		lengthTransfer -= recvValue;
	}
	lengthTransfer = bytesReceived;
	
	for (int i = 0; i < bytesReceived; i++)
	{
		m_cleanedData += m_recvBuffer[i];
	}

	std::unique_ptr<WSSocketArgs> args = std::make_unique<WSSocketArgs>(WSSocketArgs(m_sock, m_recvBuffer, bytesReceived));
	m_ReceiveReg->Run(this, args.get());

	return 0;
}

W_INT WSSocket::Send(char* inData, int& lengthTransfer)
{
	int total = 0;
	int bytesleft = lengthTransfer;
	int tmp;
	
	m_sendBuffer = inData;

	while (total < lengthTransfer)
	{
		tmp = send(m_sock, m_sendBuffer + total, bytesleft, 0);
		if (tmp == -1) { break; }
		total += tmp;
		bytesleft -= tmp;
	}

	lengthTransfer = total;

	std::unique_ptr<WSSocketArgs> args = std::make_unique<WSSocketArgs>(WSSocketArgs(m_sock, inData, lengthTransfer));
	m_SendReg->Run(this, args.get());

	return tmp == -1 ? -1 : 0;
}

SOCKET WSSocket::Socket(void) const
{
	return m_sock;
}

void WSSocket::Socket(SOCKET s)
{
	m_sock = s;
}

WSADATA WSSocket::SocketData(void) const
{
	return m_data;
}

W_INT WSSocket::Port(void) const
{
	return m_port;
}

std::string WSSocket::IP(void) const
{
	return m_ip;
}

std::string WSSocket::Data(void) const
{
	return m_cleanedData;
}

bool WSSocket::SockCount(void) const
{
	return m_sockCount;
}

W_INT WSSocket::CleanUp(void)
{
	m_sockCount--;
	if (!m_sockCount)
	{
		m_bIsStarted = false;
		return WSACleanup();
	}
	return m_sockCount;
}
