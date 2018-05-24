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

void LerpHelper(WEntity* sender, WEventArgs* args);

class WLerp : public WEntity
{
private:
	friend void LerpHelper(WEntity* sender, WEventArgs* args);

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
		m_WorkerRegistry = new WRegistry();

		m_WorkerRegistry->Register(LerpHelper);
	}

	~WLerp()
	{
		delete m_LerpTickRegistry;
		delete m_LerpDoneRegistry;
		delete m_WorkerRegistry;
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

	W_LONG Delay(W_LONG intake) const { intake = m_delay; return m_delay; }
	W_FLOAT Value(W_FLOAT intake) const { intake = m_value; return m_value; }
	W_FLOAT From(W_FLOAT intake) const { intake = m_from; return m_from; }
	W_FLOAT To(W_FLOAT intake) const { intake = m_to; return m_to; }
	W_FLOAT Alpha(W_FLOAT intake) const { intake = m_alpha; return m_alpha; }

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
		std::lock_guard<std::mutex> lock(m_MutexLock);

		m_value = lerp<W_FLOAT>(m_value, m_to, m_alpha);
		WLerpArgs* lerpArgsTick = new WLerpArgs(m_value);
		m_LerpTickRegistry->Run(this, lerpArgsTick);
		if (!(m_value > (m_to - 1.0F)))
		{
			WLerpArgs* lerpArgsDone = new WLerpArgs(m_to);
			m_LerpDoneRegistry->Run(this, lerpArgsDone);
		}
	}

	std::thread WorkThread()
	{
		return std::thread([=] { m_WorkerRegistry->Run(this, nullptr); });
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
	WRegistry* m_WorkerRegistry;

	WRegistry* m_LerpTickRegistry;
	WRegistry* m_LerpDoneRegistry;
};

void LerpHelper(WEntity* sender, WEventArgs* args)
{
	WLerp* LSender = (WLerp*)(sender);

	LSender->m_isRunning = true;

	while(!(LSender->Value() > LSender->To() - 1))
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(LSender->Delay()));
		LSender->WorkerWork();
	}

	LSender->m_isRunning = false;
}

#endif // !_W_LERP_H_
