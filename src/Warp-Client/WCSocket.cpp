// © 2018 NIREX ALL RIGHTS RESERVED

#include "WCSocket.h"
#include "WCSocketArgs.h"
#include "WarpSock.h"
#include <memory>

int WCSocket::m_sockCount = 0;
bool WCSocket::m_bIsStarted = false;

WCSocket::WCSocket(void)
	: m_ip("")
	, m_port(0)
	, m_bufferSize(0)
{
}

WCSocket::WCSocket(std::string ip, int port, int bufferSize)
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

	m_AcceptReg = new WCRegistry();
	m_BindReg = new WCRegistry();
	m_ConnectReg = new WCRegistry();
	m_ListenReg = new WCRegistry();
	m_ReceiveReg = new WCRegistry();
	m_SendReg = new WCRegistry();
}

WCSocket::~WCSocket(void)
{
	delete m_AcceptReg;
	delete m_BindReg;
	delete m_ConnectReg;
	delete m_ListenReg;
	delete m_ReceiveReg;
	delete m_SendReg;

	CleanUp();
}

W_INT WCSocket::Accept(int& outClientSize)
{
	SOCKET newConnection;

	sockaddr_in client;
	int clientSize = sizeof(client);

	newConnection = accept(m_sock, (sockaddr*)&client, &clientSize);
	outClientSize = clientSize;

	std::unique_ptr<WCSocketArgs> args = std::make_unique<WCSocketArgs>(WCSocketArgs(newConnection, nullptr, 0));
	m_AcceptReg->Run(this, args.get());

	return (newConnection == INVALID_SOCKET);
}

W_INT WCSocket::Bind(void)
{
	sockaddr_in hint;
	hint.sin_family = IPV4;
	hint.sin_port = htons(m_port);
	inet_pton(IPV4, m_ip.c_str(), &hint.sin_addr);

	int retI = bind(m_sock, (sockaddr*)&hint, sizeof(hint));

	std::unique_ptr<WCSocketArgs> args = std::make_unique<WCSocketArgs>(WCSocketArgs(m_sock, nullptr, 0));
	m_BindReg->Run(this, args.get());

	return retI;
}

W_INT WCSocket::Connect(void)
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

	std::unique_ptr<WCSocketArgs> args = std::make_unique<WCSocketArgs>(WCSocketArgs(m_sock, nullptr, 0));
	m_ConnectReg->Run(this, args.get());

	return connResult;
}

W_INT WCSocket::Listen(W_INT backLog)
{
	int retI = listen(m_sock, backLog);

	std::unique_ptr<WCSocketArgs> args = std::make_unique<WCSocketArgs>(WCSocketArgs(m_sock, nullptr, 0));
	m_ListenReg->Run(this, args.get());

	return retI;
}

W_INT WCSocket::Receive(char* outData, int& lengthTransfer)
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

	std::unique_ptr<WCSocketArgs> args = std::make_unique<WCSocketArgs>(WCSocketArgs(m_sock, m_recvBuffer, bytesReceived));
	m_ReceiveReg->Run(this, args.get());

	return 0;
}

W_INT WCSocket::Send(char* inData, int& lengthTransfer)
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

	std::unique_ptr<WCSocketArgs> args = std::make_unique<WCSocketArgs>(WCSocketArgs(m_sock, inData, lengthTransfer));
	m_SendReg->Run(this, args.get());

	return tmp == -1 ? -1 : 0;
}

SOCKET WCSocket::Socket(void) const
{
	return m_sock;
}

void WCSocket::Socket(SOCKET s)
{
	m_sock = s;
}

WSADATA WCSocket::SocketData(void) const
{
	return m_data;
}

W_INT WCSocket::Port(void) const
{
	return m_port;
}

std::string WCSocket::IP(void) const
{
	return m_ip;
}

std::string WCSocket::Data(void) const
{
	return m_cleanedData;
}

bool WCSocket::SockCount(void) const
{
	return m_sockCount;
}

W_INT WCSocket::CleanUp(void)
{
	m_sockCount--;
	if (!m_sockCount)
	{
		m_bIsStarted = false;
		return WSACleanup();
	}
	return m_sockCount;
}
