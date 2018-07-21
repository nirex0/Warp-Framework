#include "WColorTransform.h"

WColorTransform::WColorTransform(W_COLOR From, W_COLOR To, W_FLOAT alpha, W_LONG Delay)
	: m_from(From)
	, m_to(To)
	, m_alpha(alpha)
	, m_delay(Delay)
	, m_value(From)
{
	thr = new std::thread();

	m_CTTickRegistry = new WRegistry();
	m_CTDoneRegistry = new WRegistry();

}

WColorTransform::~WColorTransform()
{
	delete thr;
	delete m_CTTickRegistry;
	delete m_CTDoneRegistry;
}

WRegistry* WColorTransform::TickRegistry(void) const
{
	return m_CTTickRegistry;
}

WRegistry* WColorTransform::DoneRegistry(void) const
{
	return m_CTDoneRegistry;
}

W_LONG WColorTransform::Delay(void) const
{
	return m_delay;
}

W_FLOAT WColorTransform::Alpha(void) const
{
	return m_alpha;
}

W_COLOR WColorTransform::Value(void) const
{
	return m_value;
}

W_COLOR WColorTransform::From(void) const
{
	return m_from;
}

W_COLOR WColorTransform::To(void) const
{
	return m_to;
}

bool WColorTransform::IsRunning(void)
{
	return m_isRunning;
}

WRegistry* WColorTransform::TickRegistry(WRegistry* intake)
{
	m_CTTickRegistry = intake; return m_CTTickRegistry;
}

WRegistry* WColorTransform::DoneRegistry(WRegistry* intake)
{
	m_CTDoneRegistry = intake; return m_CTDoneRegistry;
}

W_LONG WColorTransform::Delay(W_LONG intake)
{
	m_delay = intake;
	return m_delay;
}

W_FLOAT WColorTransform::Alpha(W_FLOAT intake)
{
	m_alpha = intake; 
	return m_alpha;
}

W_COLOR WColorTransform::Value(W_COLOR intake)
{
	m_value = intake; 
	return m_value;
}

W_COLOR WColorTransform::From(W_COLOR intake)
{
	m_from = intake; 
	return m_from;
}

W_COLOR WColorTransform::To(W_COLOR intake)
{
	m_to = intake; 
	return m_to;
}

void WColorTransform::Perform(void)
{
	m_value = m_from;
	if (WorkThread(*thr))
	{
		thr->detach();
	}
}

void WColorTransform::PerformSafe(void)
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

void WColorTransform::Stop(void)
{
	m_stop = true;
}

void WColorTransform::WorkerWork(void)
{
	m_isRunning = true;
	while (
		!isNear(m_value.r, m_to.r, 0.01F) ||
		!isNear(m_value.g, m_to.g, 0.01F) ||
		!isNear(m_value.b, m_to.b, 0.01F) ||
		!isNear(m_value.a, m_to.a, 0.01F))
	{
		if (m_stop)
		{
			m_stop = false;
			m_isRunning = false;
			return;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(m_delay));
		std::lock_guard<std::mutex> lock(m_MutexLock);

		m_value.r = m_value.r + (m_to.r - m_value.r)* m_alpha;
		m_value.g = m_value.g + (m_to.g - m_value.g)* m_alpha;
		m_value.b = m_value.b + (m_to.b - m_value.b)* m_alpha;
		m_value.a = m_value.a + (m_to.a - m_value.a)* m_alpha;

		WColorTransformArgs* CTArgsTick = new WColorTransformArgs(m_value);
		m_CTTickRegistry->Run(this, CTArgsTick);
	}
	m_isRunning = false;
	WColorTransformArgs* CTArgsDone = new WColorTransformArgs(m_to);
	m_CTDoneRegistry->Run(this, CTArgsDone);
}

bool WColorTransform::WorkThread(std::thread & out)
{
	out = std::thread([=] { WorkerWork(); });
	return true;
}