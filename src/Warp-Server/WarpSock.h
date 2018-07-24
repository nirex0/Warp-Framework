// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _WS_WARP_SOCK_H_
#define _WS_WARP_SOCK_H_

#include <WS2tcpip.h>
#pragma comment (lib, "ws2_32.lib")

typedef SOCKET WSSocket;

#define WARP_FRAMEWORK
#define W_SERVER
#define WARP

#define V4 AF_INET
#define V6 AF_INET6

#endif // !_WS_WARP_SOCK_H_