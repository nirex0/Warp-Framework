// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_SOCKET_ARGS_H_
#define _W_SOCKET_ARGS_H_

#include "WEventArgs.h"
#include "WNetwork.h"

class WSocketArgs : public WEventArgs
{
public:
	WSocketArgs(SOCKET sock, char* data, int len);
	~WSocketArgs(void);

	SOCKET Socket(void) const;
	char* Data(void) const;
	int Length(void) const;

private:
	SOCKET m_sock;
	char* m_data;
	int m_len;
};

#endif // !_WS_SOCKET_ARGS_H_