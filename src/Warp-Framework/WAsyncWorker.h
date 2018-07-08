// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_ASYNCWORKER_H_
#define _W_ASYNCWORKER_H_

#include "WEntity.h"
#include "WRegistry.h"
#include "WAsyncArgs.h"

#include <chrono>
#include <mutex>
#include <thread>
#include <future>

class WAsyncWorker : public WEntity
{
public:
	WAsyncWorker();
	~WAsyncWorker();

// Getters
	WRegistry* WorkRegistry(void) const;

// Setters
	WRegistry* WorkRegistry(WRegistry* intake);

// Functions
	void RunWorkerAsync(void);
	void RunWorkerAsyncSafe(void);
	bool IsRunning(void);

private:
	void WorkerWork(void);
	bool WorkThread(std::thread& out);

private:
	std::thread thr;
	std::mutex m_MutexLock;

	bool m_isRunning;
	WRegistry* m_WorkRegistry;
};

#endif // !_W_ASYNCWORKER_H_
