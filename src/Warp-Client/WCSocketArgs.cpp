// © 2018 NIREX ALL RIGHTS RESERVED

#include "WCSocketArgs.h"

WCSocketArgs::WCSocketArgs(SOCKET sock, char* data, int len)
	: m_sock(sock)
	, m_data(data)
	, m_len(len)
{
}

WCSocketArgs::~WCSocketArgs()
{
}

SOCKET WCSocketArgs::Socket(void) const
{
	return m_sock;
}

char* WCSocketArgs::Data(void) const
{
	return m_data;
}

int WCSocketArgs::Length(void) const
{
	return m_len;
}
