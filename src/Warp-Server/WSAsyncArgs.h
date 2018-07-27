// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _WS_ASYNC_ARGS_H_
#define _WS_ASYNC_ARGS_H_

#include "WSEventArgs.h"
#include "WSSocket.h"

class WSAsyncArgs : public WSEventArgs
{
public:
	WSAsyncArgs(WSSocket* sock);
	~WSAsyncArgs(void);

	WSSocket* Socket(void) const;

private:
	WSSocket * m_sock;
};

#endif // !_WS_ASYNC_ARGS_H_