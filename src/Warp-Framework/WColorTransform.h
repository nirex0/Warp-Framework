// © 2018 NIREX ALL RIGHTS RESERVED

#ifndef _W_COLOR_TRANSFORM_H_
#define _W_COLOR_TRANSFORM_H_

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
	WColorTransform(W_COLOR From, W_COLOR To, W_FLOAT alpha, W_LONG Delay);
	~WColorTransform();

	// Getters
	WRegistry* TickRegistry(void) const;
	WRegistry* DoneRegistry(void) const;

	W_LONG Delay(void) const;
	W_FLOAT Alpha(void) const;
	W_COLOR Value(void) const;
	W_COLOR From(void) const;
	W_COLOR To(void) const;
	bool IsRunning(void);

	// Setters
	WRegistry* TickRegistry(WRegistry* intake);
	WRegistry* DoneRegistry(WRegistry* intake);

	W_LONG Delay(W_LONG intake);
	W_FLOAT Alpha(W_FLOAT intake);
	W_COLOR Value(W_COLOR intake);
	W_COLOR From(W_COLOR intake);
	W_COLOR To(W_COLOR intake);
	
// Functions
	void Perform(void);
	void PerformSafe(void);
	void Stop(void);

private:
	void WorkerWork(void);
	bool WorkThread(std::thread& out);

private:
	W_LONG m_delay;
	W_FLOAT m_alpha;
	W_COLOR m_value;
	W_COLOR m_from;
	W_COLOR m_to;

	std::thread* thr;
	std::mutex m_MutexLock;

	bool m_stop;
	bool m_isRunning;

	WRegistry* m_CTTickRegistry;
	WRegistry* m_CTDoneRegistry;
};

#endif // !_W_COLOR_TRANSFORM_H_
