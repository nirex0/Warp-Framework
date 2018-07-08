// © 2018 NIREX ALL RIGHTS RESERVED

#include "WAsyncWorker.h"

WAsyncWorker::WAsyncWorker()
{
	m_WorkRegistry = new WRegistry();
}

WAsyncWorker::~WAsyncWorker()
{
	delete m_WorkRegistry;
}

WRegistry* WAsyncWorker::WorkRegistry(void) const
{
	return m_WorkRegistry;
}

WRegistry* WAsyncWorker::WorkRegistry(WRegistry* intake)
{
	m_WorkRegistry = intake;
	return m_WorkRegistry;
}

void WAsyncWorker::RunWorkerAsync(void)
{
	if (WorkThread(thr))
	{
		thr.detach();
	}
}

void WAsyncWorker::RunWorkerAsyncSafe(void)
{
	if (!m_isRunning)
	{
		if (WorkThread(thr))
		{
			thr.detach();
		}
	}
}

bool WAsyncWorker::IsRunning(void)
{
	return m_isRunning;
}

void WAsyncWorker::WorkerWork(void)
{
	m_isRunning = true;
	std::lock_guard<std::mutex> lock(m_MutexLock);
	WAsyncArgs* args = new WAsyncArgs();
	m_WorkRegistry->Run(this, args);
	m_isRunning = false;
}

bool WAsyncWorker::WorkThread(std::thread & out)
{
	out = std::thread([=] { WorkerWork(); });
	return true;
}
