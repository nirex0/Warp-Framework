// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_ASYNCWORKER_H_
#define _W_ASYNCWORKER_H_

#include "WEntity.h"
#include "WRegistry.h"
#include "WAsyncArgs.h"
#include "WDefines.h"

#include <chrono>
#include <mutex>
#include <thread>
#include <future>
#include <memory>

//-->DOC_CLASS
// A class to perform Async tasks that require iteration
class WAsyncWorker : public WEntity
{
public:
	WAsyncWorker(void);
	~WAsyncWorker(void);

	WRegistry* WorkRegistry(void) const;
	W_LONG Delay(void) const;

	WRegistry* WorkRegistry(WRegistry* intake);
	W_LONG Delay(W_LONG intake);

	//-->DOC_FUNC
	// Begin Async Worker (no safeguards)
	void RunWorkerAsync(void);

	//-->DOC_FUNC
	// Begin Async Worker (with safeguards)
	void RunWorkerAsyncSafe(void);

	//-->DOC_FUNC
	// Function to determine whether or not the Worker is working
	// Returns: True if working, False otherwise. 
	bool IsRunning(void);

	//-->DOC_FUNC
	// Stop Async Worker if it's working
	void Stop(void);

private:
	void WorkerWork(void);
	bool WorkThread(std::thread& out);

private:
	//-->DOC_MEMBER
	// Delay Between each epoch
	W_LONG m_delay;

	std::thread thr;
	std::mutex m_MutexLock;

	bool m_stop;
	bool m_isRunning;

	//-->DOC_MEMBER
	// Function registry that is called on each Tick
	WRegistry* m_WorkRegistry;
};

#endif // !_W_ASYNCWORKER_H_
