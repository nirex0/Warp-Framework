//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_LERP_H_
#define _W_LERP_H_

#include "WEntity.h"
#include "WLerpArgs.h"
#include "WMath.h"
#include "WRegistry.h"
#include "WDefines.h"

#include <chrono>
#include <mutex>
#include <thread>
#include <future>

class WLerp : public WEntity
{
public:
	WLerp(W_FLOAT from, W_FLOAT to, W_FLOAT alpha, W_LONG delay = 1)
		: m_from(from)
		, m_to(to)
		, m_alpha(alpha)
		, m_value(from)
		, m_delay(delay)
	{
		m_LerpTickRegistry = new WRegistry();
		m_LerpDoneRegistry = new WRegistry();

		m_isLocked = false;
	}

	~WLerp()
	{
		delete m_LerpTickRegistry;
		delete m_LerpDoneRegistry;
	}

	// Getters
	WRegistry* TickRegistry(void) const { return m_LerpTickRegistry; }
	WRegistry* DoneRegistry(void) const { return m_LerpDoneRegistry; }

	W_LONG Delay(void) const { return m_delay; }
	W_FLOAT Value(void) const { return m_value; }
	W_FLOAT From(void) const { return m_from; }
	W_FLOAT To(void) const { return m_to; }
	W_FLOAT Alpha(void) const { return m_alpha; }
	bool IsRunning(void) { return m_isRunning; }

	// Setters
	WRegistry* TickRegistry(WRegistry* intake) { m_LerpTickRegistry = intake; return m_LerpTickRegistry; }
	WRegistry* DoneRegistry(WRegistry* intake) { m_LerpDoneRegistry = intake; return m_LerpDoneRegistry; }

	W_LONG Delay(W_LONG intake) { m_delay = intake; return m_delay; }
	W_FLOAT Value(W_FLOAT intake) { m_value = intake; return m_value; }
	W_FLOAT From(W_FLOAT intake) { m_from = intake; return m_from; }
	W_FLOAT To(W_FLOAT intake) { m_to = intake; return m_to; }
	W_FLOAT Alpha(W_FLOAT intake) { m_alpha = intake; return m_alpha; }

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

	bool IsLocked(void) const { return m_isLocked; }
	void Lock(void) { m_isLocked = true; }
	void Unlock(void) { m_isLocked = false; }

private:
	void WorkerWork(void)
	{
		m_isRunning = true;
		while (!isNear(m_value, m_to, 1) && !m_isLocked)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(m_delay));
			std::lock_guard<std::mutex> lock(m_MutexLock);

			m_value = m_value + (m_to - m_value) * m_alpha;

			WLerpArgs* lerpArgsTick = new WLerpArgs(m_value);
			m_LerpTickRegistry->Run(this, lerpArgsTick);
		}
		m_isRunning = false;
		WLerpArgs* lerpArgsDone = new WLerpArgs(m_to);
		m_LerpDoneRegistry->Run(this, lerpArgsDone);
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
	W_FLOAT m_alpha;

	std::thread thr;
	std::mutex m_MutexLock;

	bool m_isRunning;
	bool m_isLocked;

	WRegistry* m_LerpTickRegistry;
	WRegistry* m_LerpDoneRegistry;
};

#endif // !_W_LERP_H_
