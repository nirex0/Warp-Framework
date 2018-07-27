// © 2018 NIREX ALL RIGHTS RESERVED

#include "WSAsyncWorker.h"

WSAsyncWorker::WSAsyncWorker(WSSocket* sock)
	: m_sock(sock)
{
	m_WorkRegistry = new WSRegistry();
	m_delay = 1;
}

WSAsyncWorker::~WSAsyncWorker(void)
{
	delete m_WorkRegistry;
}

WSRegistry* WSAsyncWorker::WorkRegistry(void) const
{
	return m_WorkRegistry;
}

W_LONG WSAsyncWorker::Delay(void) const
{
	return m_delay;
}

WSSocket* WSAsyncWorker::Socket(void)
{
	return m_sock;
}

WSRegistry* WSAsyncWorker::WorkRegistry(WSRegistry* intake)
{
	m_WorkRegistry = intake;
	return m_WorkRegistry;
}

W_LONG WSAsyncWorker::Delay(W_LONG intake)
{
	m_delay = intake;
	return m_delay;
}

WSSocket* WSAsyncWorker::Socket(WSSocket* intake)
{
	m_sock = intake;
	return m_sock;
}

void WSAsyncWorker::RunWorkerAsync(void)
{
	if (WorkThread(thr))
	{
		thr.detach();
	}
}

void WSAsyncWorker::RunWorkerAsyncSafe(void)
{
	if (!m_isRunning)
	{
		if (WorkThread(thr))
		{
			thr.detach();
		}
	}
}

bool WSAsyncWorker::IsRunning(void)
{
	return m_isRunning;
}

void WSAsyncWorker::WorkerWork(void)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(m_delay));
	m_isRunning = true;
	std::lock_guard<std::mutex> lock(m_MutexLock);
	WSAsyncArgs* args = new WSAsyncArgs(m_sock);
	m_WorkRegistry->Run(this, args);

	m_isRunning = false;
	return;
}

bool WSAsyncWorker::WorkThread(std::thread& out)
{
	out = std::thread([=] { WorkerWork(); });
	return true;
}
