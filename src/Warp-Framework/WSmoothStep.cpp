// © 2018 NIREX ALL RIGHTS RESERVED

#include "WSmoothStep.h"

WSmoothStep::WSmoothStep(W_FLOAT from, W_FLOAT to, W_LONG delay)
	: m_from(from)
	, m_to(to)
	, m_value(from)
	, m_delay(delay)
{
	thr = new std::thread();

	m_SmoothStepTickRegistry = new WRegistry();
	m_SmoothStepDoneRegistry = new WRegistry();
}

WSmoothStep::~WSmoothStep()
{
	delete thr;
	delete m_SmoothStepTickRegistry;
	delete m_SmoothStepDoneRegistry;
}
WRegistry* WSmoothStep::TickRegistry(void) const
{
	return m_SmoothStepTickRegistry;
}

WRegistry* WSmoothStep::DoneRegistry(void) const
{
	return m_SmoothStepDoneRegistry;
}

W_LONG WSmoothStep::Delay(void) const
{
	return m_delay;
}

W_FLOAT WSmoothStep::Value(void) const
{
	return m_value;
}

W_FLOAT WSmoothStep::From(void) const
{
	return m_from;
}

W_FLOAT WSmoothStep::To(void) const
{
	return m_to;
}

bool WSmoothStep::IsRunning(void)
{
	return m_isRunning;
}

WRegistry* WSmoothStep::TickRegistry(WRegistry* intake)
{
	m_SmoothStepTickRegistry = intake;
	return m_SmoothStepTickRegistry;
}

WRegistry* WSmoothStep::DoneRegistry(WRegistry* intake)
{
	m_SmoothStepDoneRegistry = intake;
	return m_SmoothStepDoneRegistry;
}

W_LONG WSmoothStep::Delay(W_LONG intake)
{
	m_delay = intake;
	return m_delay;
}

W_FLOAT WSmoothStep::Value(W_FLOAT intake)
{
	m_value = intake;
	return m_value;
}

W_FLOAT WSmoothStep::From(W_FLOAT intake)
{
	m_from = intake;
	return m_from;
}

W_FLOAT WSmoothStep::To(W_FLOAT intake)
{
	m_to = intake;
	return m_to;
}

void WSmoothStep::Perform(void)
{
	m_value = m_from;
	if (WorkThread(*thr))
	{
		thr->detach();
	}
}

void WSmoothStep::PerformSafe(void)
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

void WSmoothStep::Stop(void)
{
	m_stop = true;
}

void WSmoothStep::WorkerWork(void)
{
	m_isRunning = true;
	while (!isNear(m_value, m_to, 1))
	{
		if (m_stop)
		{
			m_stop = false;
			m_isRunning = false;
			return;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(m_delay));
		std::lock_guard<std::mutex> lock(m_MutexLock);

		m_value = smoothstep(m_from, m_to, m_value);

		WSmoothStepArgs* SSArgsTick = new WSmoothStepArgs(m_value);
		m_SmoothStepTickRegistry->Run(this, SSArgsTick);
	}
	m_isRunning = false;
	WSmoothStepArgs* SSArgsDone = new WSmoothStepArgs(m_to);
	m_SmoothStepDoneRegistry->Run(this, SSArgsDone);
}

bool WSmoothStep::WorkThread(std::thread & out)
{
	out = std::thread([=] { WorkerWork(); });
	return true;
}