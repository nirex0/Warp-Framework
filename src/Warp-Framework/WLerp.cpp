// © 2018 NIREX ALL RIGHTS RESERVED

#include "WLerp.h"

WLerp::WLerp(W_FLOAT from, W_FLOAT to, W_FLOAT alpha, W_LONG delay)
	: m_from(from)
	, m_to(to)
	, m_alpha(alpha)
	, m_value(from)
	, m_delay(delay)
{
	thr = new std::thread();

	m_LerpTickRegistry = new WRegistry();
	m_LerpDoneRegistry = new WRegistry();

	m_isLocked = false;
}

WLerp::~WLerp()
{
	delete thr;
	delete m_LerpTickRegistry;
	delete m_LerpDoneRegistry;
}

WRegistry* WLerp::TickRegistry(void) const
{
	return m_LerpTickRegistry;
}

WRegistry* WLerp::DoneRegistry(void) const
{
	return m_LerpDoneRegistry;
}



W_LONG WLerp::Delay(void) const
{
	return m_delay;
}

W_FLOAT WLerp::Value(void) const
{
	return m_value;
}

W_FLOAT WLerp::From(void) const
{
	return m_from;
}

W_FLOAT WLerp::To(void) const
{
	return m_to;
}

W_FLOAT WLerp::Alpha(void) const
{
	return m_alpha;
}

bool WLerp::IsRunning(void)
{
	return m_isRunning;
}

WRegistry* WLerp::TickRegistry(WRegistry* intake)
{
	m_LerpTickRegistry = intake; 
	return m_LerpTickRegistry;
}

WRegistry* WLerp::DoneRegistry(WRegistry* intake)
{
	m_LerpDoneRegistry = intake; 
	return m_LerpDoneRegistry;
}

W_LONG WLerp::Delay(W_LONG intake)
{
	m_delay = intake;
	return m_delay;
}

W_FLOAT WLerp::Value(W_FLOAT intake)
{
	m_value = intake; 
	return m_value;
}

W_FLOAT WLerp::From(W_FLOAT intake)
{
	m_from = intake; 
	return m_from;
}

W_FLOAT WLerp::To(W_FLOAT intake)
{
	m_to = intake; 
	return m_to;
}

W_FLOAT WLerp::Alpha(W_FLOAT intake)
{
	m_alpha = intake; 
	return m_alpha;
}

void WLerp::Perform(void)
{
	m_value = m_from;
	if (WorkThread(*thr))
	{
		thr->detach();
	}
}

void WLerp::PerformSafe(void)
{
	if (!m_isRunning)
	{
		m_value = m_from;
		if (WorkThread(*thr))
		{
			thr->detach();
		}
	}
}

bool WLerp::IsLocked(void) const
{
	return m_isLocked;
}

void WLerp::Lock(void)
{
	m_isLocked = true;
}

void WLerp::Unlock(void)
{
	m_isLocked = false;
}

void WLerp::Stop(void)
{
	m_stop = true;
}

void WLerp::WorkerWork(void)
{
	m_isRunning = true;
	while (!isNear(m_value, m_to, 1) && !m_isLocked)
	{
		if (m_stop)
		{
			m_stop = false;
			m_isRunning = false;
			return;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(m_delay));
		m_value = m_value + (m_to - m_value)* m_alpha;

		WLerpArgs* lerpArgsTick = new WLerpArgs(m_value);
		m_LerpTickRegistry->Run(this, lerpArgsTick);
	}
	m_isRunning = false;
	WLerpArgs* lerpArgsDone = new WLerpArgs(m_to);
	m_LerpDoneRegistry->Run(this, lerpArgsDone);
}

bool WLerp::WorkThread(std::thread & out)
{
	out = std::thread([=] { WorkerWork(); });
	return true;
}