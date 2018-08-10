// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _WS_SOCKET_ARGS_H_
#define _WS_SOCKET_ARGS_H_

#include "WSEventArgs.h"
#include "WSSock.h"

class WSSocketArgs : public WSEventArgs
{
public:
	WSSocketArgs(SOCKET sock, char* data, int len);
	~WSSocketArgs(void);

	SOCKET Socket(void) const;
	char* Data(void) const;
	int Length(void) const;

private:
	SOCKET m_sock;
	char* m_data;
	int m_len;
};

#endif // !_WS_SOCKET_ARGS_H_