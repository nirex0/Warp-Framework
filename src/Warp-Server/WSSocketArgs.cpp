// © 2018 NIREX ALL RIGHTS RESERVED

#include "WSSocketArgs.h"

WSSocketArgs::WSSocketArgs(SOCKET sock, char* data, int len)
	: m_sock(sock)
	, m_data(data)
	, m_len(len)
{
}

WSSocketArgs::~WSSocketArgs()
{
}

SOCKET WSSocketArgs::Socket(void) const
{
	return m_sock;
}

char* WSSocketArgs::Data(void) const
{
	return m_data;
}

int WSSocketArgs::Length(void) const
{
	return m_len;
}
