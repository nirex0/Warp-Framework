// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _WC_SOCKET_ARGS_H_
#define _WC_SOCKET_ARGS_H_

#include "WCEventArgs.h"
#include "WCSock.h"

class WCSocketArgs : public WCEventArgs
{
public:
	WCSocketArgs(SOCKET sock, char* data, int len);
	~WCSocketArgs(void);

	SOCKET Socket(void) const;
	char* Data(void) const;
	int Length(void) const;

private:
	SOCKET m_sock;
	char* m_data;
	int m_len;
};

#endif // !_WC_SOCKET_ARGS_H_