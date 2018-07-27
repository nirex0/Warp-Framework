// © 2018 NIREX ALL RIGHTS RESERVED

#include "WSAsyncArgs.h"

WSAsyncArgs::WSAsyncArgs(WSSocket* sock)
	: m_sock(sock)
{
}


WSAsyncArgs::~WSAsyncArgs(void)
{
}

WSSocket* WSAsyncArgs::Socket(void) const
{
	return m_sock;
}
