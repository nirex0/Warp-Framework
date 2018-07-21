// © 2018 NIREX ALL RIGHTS RESERVED

#include "WAsyncWorker.h"

WAsyncWorker::WAsyncWorker()
{
	m_WorkRegistry = new WRegistry();
	m_delay = 1;
}

WAsyncWorker::~WAsyncWorker()
{
	delete m_WorkRegistry;
}

WRegistry* WAsyncWorker::WorkRegistry(void) const
{
	return m_WorkRegistry;
}

W_LONG WAsyncWorker::Delay(void) const
{
	return m_delay;
}

WRegistry* WAsyncWorker::WorkRegistry(WRegistry* intake)
{
	m_WorkRegistry = intake;
	return m_WorkRegistry;
}

W_LONG WAsyncWorker::Delay(W_LONG intake)
{
	m_delay = intake;
	return m_delay;
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

void WAsyncWorker::Stop(void)
{
	m_stop = true;
}

void WAsyncWorker::WorkerWork(void)
{
	while (!m_stop)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(m_delay));
		m_isRunning = true;
		std::lock_guard<std::mutex> lock(m_MutexLock);
		WAsyncArgs* args = new WAsyncArgs();
		m_WorkRegistry->Run(this, args);
	}
	m_stop = false;
	m_isRunning = false;
	return;

}

bool WAsyncWorker::WorkThread(std::thread& out)
{
	out = std::thread([=] { WorkerWork(); });
	return true;
}
