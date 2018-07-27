// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _WS_ASYNCWORKER_H_
#define _WS_ASYNCWORKER_H_

#include "WSEntity.h"
#include "WSRegistry.h"
#include "WSAsyncArgs.h"
#include "WSDefines.h"

#include <chrono>
#include <mutex>
#include <thread>
#include <future>

class WSAsyncWorker : public WSEntity
{
public:
	WSAsyncWorker(WSSocket* sock);
	~WSAsyncWorker(void);

	// Getters
	WSRegistry* WorkRegistry(void) const;
	W_LONG Delay(void) const;
	WSSocket* Socket(void);

	// Setters
	WSRegistry* WorkRegistry(WSRegistry* intake);
	W_LONG Delay(W_LONG intake);
	WSSocket* Socket(WSSocket* intake);

	// Functions
	void RunWorkerAsync(void);
	void RunWorkerAsyncSafe(void);
	bool IsRunning(void);


private:
	void WorkerWork(void);
	bool WorkThread(std::thread& out);

private:
	W_LONG m_delay;
	std::thread thr;
	std::mutex m_MutexLock;

	bool m_isRunning;
	WSRegistry* m_WorkRegistry;
	WSSocket* m_sock;
};


#endif // !_WS_ASYNCWORKER_H_