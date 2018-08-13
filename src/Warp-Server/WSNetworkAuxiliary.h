// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _WS_NETWORK_AUXILIARY_H_
#define _WS_NETWORK_AUXILIARY_H_

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include "WarpSock.h"
#include "WSWin.h"

// Because Microsoft is a Pain
namespace WSHELPERS
{
	int w_inet_pton(int af, const char *src, void *dst);
	const char* w_inet_ntop(int af, const void *src, char *dst, socklen_t size);
}
#endif // !_WS_NETWORK_AUXILIARY_H_