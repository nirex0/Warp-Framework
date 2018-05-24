//© 2018 NIREX ALL RIGHTS RESERVED

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
	WAsyncWorker()
	{
		m_WorkRegistry = new WRegistry();
	}

	~WAsyncWorker() 
	{
		delete m_WorkRegistry;
	}

	// Getters
	WRegistry* WorkRegistry(void) const
	{
		return m_WorkRegistry;
	}

	// Setters
	WRegistry* WorkRegistry(WRegistry* intake)
	{
		m_WorkRegistry = intake;
		return m_WorkRegistry;
	}

	// Functions
	void RunWorkerAsync(void)
	{
		m_isRunning = true;

		thr = WorkThread();
		thr.detach();

		m_isRunning = false;
	}

	void RunWorkerAsyncSafe(void)
	{
		if (!m_isRunning)
		{
			m_isRunning = true;

			thr = WorkThread();
			thr.detach();

			m_isRunning = false;
		}
	}

	bool IsRunning(void)
	{
		return m_isRunning;
	}

private:
	void WorkerWork(void)
	{
		std::lock_guard<std::mutex> lock(m_MutexLock);
		WAsyncArgs* args = new WAsyncArgs();
		m_WorkRegistry->Run(this, args);		
	}

	std::thread WorkThread()
	{
		return std::thread([=] { WorkerWork(); });
	}

private:
	std::thread thr;
	std::mutex m_MutexLock;

	bool m_isRunning;
	WRegistry* m_WorkRegistry;
};

#endif // !_W_ASYNCWORKER_H_
