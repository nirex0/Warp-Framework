//© 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_COLOR_TRANSFORM_H__H_
#define _W_COLOR_TRANSFORM_H__H_

#include "WEntity.h"
#include "WColorTransformArgs.h"
#include "WMath.h"
#include "WRegistry.h"
#include "WDefines.h"
#include "WDX.h"

#include <chrono>
#include <mutex>
#include <thread>
#include <future>

class WColorTransform : public WEntity
{
public:
	WColorTransform(W_COLOR From, W_COLOR To, W_FLOAT alpha, W_LONG Delay)
		: m_from(From)
		, m_to(To)
		, m_alpha(alpha)
		, m_delay(Delay)
		, m_value(From)
	{
		m_CTTickRegistry = new WRegistry();
		m_CTDoneRegistry = new WRegistry();

		m_isLocked = false;
	}

	~WColorTransform()
	{
		delete m_CTTickRegistry;
		delete m_CTDoneRegistry;
	}

	// Getters
	WRegistry* TickRegistry(void) const { return m_CTTickRegistry; }
	WRegistry* DoneRegistry(void) const { return m_CTDoneRegistry; }

	W_LONG Delay(void) const { return m_delay; }
	W_FLOAT Alpha(void) const { return m_alpha; }
	W_COLOR Value(void) const { return m_value; }
	W_COLOR From(void) const { return m_from; }
	W_COLOR To(void) const { return m_to; }
	bool IsRunning(void) { return m_isRunning; }

	// Setters
	WRegistry* TickRegistry(WRegistry* intake) { m_CTTickRegistry = intake; return m_CTTickRegistry; }
	WRegistry* DoneRegistry(WRegistry* intake) { m_CTDoneRegistry = intake; return m_CTDoneRegistry; }

	W_LONG Delay(W_LONG intake) { m_delay = intake; return m_delay; }
	W_FLOAT Alpha(W_FLOAT intake) { m_alpha = intake; return m_alpha; }
	W_COLOR Value(W_COLOR intake) { m_value = intake; return m_value; }
	W_COLOR From(W_COLOR intake) { m_from = intake; return m_from; }
	W_COLOR To(W_COLOR intake) { m_to = intake; return m_to; }
	
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
		while (
			!isNear(m_value.r, m_to.r, 0.01F) ||
			!isNear(m_value.g, m_to.g, 0.01F) ||
			!isNear(m_value.b, m_to.b, 0.01F) ||
			!isNear(m_value.a, m_to.a, 0.01F))
		{
			if (m_isLocked)
			{
				break;
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(m_delay));
			std::lock_guard<std::mutex> lock(m_MutexLock);

			m_value.r = m_value.r + (m_to.r - m_value.r) * m_alpha;
			m_value.g = m_value.g + (m_to.g - m_value.g) * m_alpha;
			m_value.b = m_value.b + (m_to.b - m_value.b) * m_alpha;
			m_value.a = m_value.a + (m_to.a - m_value.a) * m_alpha;

			WColorTransformArgs* CTArgsTick = new WColorTransformArgs(m_value);
			m_CTTickRegistry->Run(this, CTArgsTick);
		}
		m_isRunning = false;
		WColorTransformArgs* CTArgsDone = new WColorTransformArgs(m_to);
		m_CTDoneRegistry->Run(this, CTArgsDone);
	}

	std::thread WorkThread()
	{
		return std::thread([=] { WorkerWork(); });
	}

private:
	W_LONG m_delay;
	W_FLOAT m_alpha;
	W_COLOR m_value;
	W_COLOR m_from;
	W_COLOR m_to;

	std::thread thr;
	std::mutex m_MutexLock;

	bool m_isRunning;
	bool m_isLocked;

	WRegistry* m_CTTickRegistry;
	WRegistry* m_CTDoneRegistry;
};

#endif // !_W_COLOR_TRANSFORM_H_
