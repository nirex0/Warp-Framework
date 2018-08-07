// © 2018 NIREX ALL RIGHTS RESERVED

#include "WSSocket.h"

WSSocket::WSSocket(std::string ip, int port, int bufferSize)
	: m_ip(ip)
	, m_port(port)
	, m_bufferSize(bufferSize)
{
	m_buffer = new char[m_bufferSize];
	WORD version = MAKEWORD(2, 2);
	WSAStartup(version,&m_data);
	m_sock = socket(AF_INET, SOCK_STREAM, 0);
}

WSSocket::~WSSocket(void)
{
	CleanUp();
}

W_INT WSSocket::Bind(void)
{
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(m_port);
	inet_pton(AF_INET, m_ip.c_str(), &hint.sin_addr);

	return bind(m_sock, (sockaddr*)&hint, sizeof(hint));
}

W_INT WSSocket::Listen(W_INT backLog)
{
	return listen(m_sock, backLog);
}

W_INT WSSocket::Accept(SOCKET clientSocket, int& outClientSize)
{
	sockaddr_in client;
	int clientSize = sizeof(client);

	clientSocket = accept(m_sock, (sockaddr*)&client, &clientSize);

	outClientSize = clientSize;

	return (clientSocket == INVALID_SOCKET);
}

W_INT WSSocket::Connect(void)
{
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(m_port);
	inet_pton(AF_INET, m_ip.c_str(), &hint.sin_addr);

	int connResult = connect(m_sock, (sockaddr*)&hint, sizeof(hint));
	if (connResult == SOCKET_ERROR)
	{
		CleanUp();
		return SOCKET_ERROR;
	}
}

W_INT WSSocket::Send(SOCKET fromSocket, char* inData, int* dataLength)
{
	int total = 0;
	int bytesleft = *dataLength;
	int tmp;

	while (total < *dataLength)
	{
		tmp = send(fromSocket, inData + total, bytesleft, 0);
		if (tmp == -1) { break; }
		total += tmp;
		bytesleft -= tmp;
	}

	*dataLength = total;

	return tmp == -1 ? -1 : 0;
}


W_INT WSSocket::Receive(SOCKET fromSocket, char* outData, int& outLength)
{
	int bytes = recv(fromSocket, m_buffer, m_bufferSize, 0);
	
	outData = m_buffer;
	outLength = bytes;

	if (bytes == SOCKET_ERROR)
	{
		CleanUp();
		return SOCKET_ERROR;
	}
	if (bytes == 0)
	{
		CleanUp();
		return NULL;
	}

	for (size_t i = 0; i < bytes; i++)
	{
		m_cleanedData += m_buffer[i];
	}

	return 0;
}

SOCKET WSSocket::Socket(void) const
{
	return m_sock;
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

W_INT WSSocket::CleanUp(void)
{
	return WSACleanup();
}
