//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_SMOOTHSTEP_H_
#define _W_SMOOTHSTEP_H_


#include "WEntity.h"
#include "WSmoothStepArgs.h"
#include "WMath.h"
#include "WRegistry.h"
#include "WDefines.h"

#include <chrono>
#include <mutex>
#include <thread>
#include <future>

class WSmoothStep : public WEntity
{
public:
	WSmoothStep(W_FLOAT from, W_FLOAT to, W_LONG delay = 1)
		: m_from(from)
		, m_to(to)
		, m_value(from)
		, m_delay(delay)
	{
		m_SmoothStepTickRegistry = new WRegistry();
		m_SmoothStepDoneRegistry = new WRegistry();
	}

	~WSmoothStep()
	{
		delete m_SmoothStepTickRegistry;
		delete m_SmoothStepDoneRegistry;
	}

	// Getters
	WRegistry* TickRegistry(void) const { return m_SmoothStepTickRegistry; }
	WRegistry* DoneRegistry(void) const { return m_SmoothStepDoneRegistry; }

	W_LONG Delay(void) const { return m_delay; }
	W_FLOAT Value(void) const { return m_value; }
	W_FLOAT From(void) const { return m_from; }
	W_FLOAT To(void) const { return m_to; }
	bool IsRunning(void) { return m_isRunning; }

	// Setters
	WRegistry* TickRegistry(WRegistry* intake) { m_SmoothStepTickRegistry = intake; return m_SmoothStepTickRegistry; }
	WRegistry* DoneRegistry(WRegistry* intake) { m_SmoothStepDoneRegistry = intake; return m_SmoothStepDoneRegistry; }

	W_LONG Delay(W_LONG intake) const { intake = m_delay; return m_delay; }
	W_FLOAT Value(W_FLOAT intake) const { intake = m_value; return m_value; }
	W_FLOAT From(W_FLOAT intake) const { intake = m_from; return m_from; }
	W_FLOAT To(W_FLOAT intake) const { intake = m_to; return m_to; }

	// Functions
	void Perform(void)
	{
		m_value = m_from;
		thr = WorkThread();
		thr.detach();
	}

	void PerformSafe(void)
	{
		if (!m_isRunning)
		{
			m_value = m_from;
			thr = WorkThread();
			thr.detach();
		}
	}

private:
	void WorkerWork(void)
	{
		m_isRunning = true;

		while (!isNear(m_value, m_to, 1))
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(m_delay));
			std::lock_guard<std::mutex> lock(m_MutexLock);

			m_value = smoothstep<W_FLOAT>(m_from, m_to, m_value);

			WSmoothStepArgs* SSArgsTick = new WSmoothStepArgs(m_value);
			m_SmoothStepTickRegistry->Run(this, SSArgsTick);
		}

		m_isRunning = false;

		WSmoothStepArgs* SSArgsDone = new WSmoothStepArgs(m_to);
		m_SmoothStepDoneRegistry->Run(this, SSArgsDone);
	}

	std::thread WorkThread()
	{
		return std::thread([=] { WorkerWork(); });
	}

private:
	W_LONG m_delay;
	W_FLOAT m_value;
	W_FLOAT m_from;
	W_FLOAT m_to;

	std::thread thr;
	std::mutex m_MutexLock;

	bool m_isRunning;

	WRegistry* m_SmoothStepTickRegistry;
	WRegistry* m_SmoothStepDoneRegistry;
};

#endif // !_W_SMOOTHSTEP_H_
