// © 2018 NIREX ALL RIGHTS RESERVED

#include "WSocketArgs.h"

WSocketArgs::WSocketArgs(SOCKET sock, char* data, int len)
	: m_sock(sock)
	, m_data(data)
	, m_len(len)
{
}

WSocketArgs::~WSocketArgs()
{
}

SOCKET WSocketArgs::Socket(void) const
{
	return m_sock;
}

char* WSocketArgs::Data(void) const
{
	return m_data;
}

int WSocketArgs::Length(void) const
{
	return m_len;
}
