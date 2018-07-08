// © 2018 NIREX ALL RIGHTS RESERVED

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
	WLerp(W_FLOAT from, W_FLOAT to, W_FLOAT alpha, W_LONG delay = 1);
	~WLerp();

// Getters
	WRegistry* TickRegistry(void) const;
	WRegistry* DoneRegistry(void) const;

	W_LONG Delay(void) const;
	W_FLOAT Value(void) const;
	W_FLOAT From(void) const;
	W_FLOAT To(void) const;
	W_FLOAT Alpha(void) const;
	bool IsRunning(void);

// Setters
	WRegistry* TickRegistry(WRegistry* intake);
	WRegistry* DoneRegistry(WRegistry* intake);

	W_LONG Delay(W_LONG intake);
	W_FLOAT Value(W_FLOAT intake);
	W_FLOAT From(W_FLOAT intake);
	W_FLOAT To(W_FLOAT intake);
	W_FLOAT Alpha(W_FLOAT intake);

// Functions
	void Perform(void);
	void PerformSafe(void);

	bool IsLocked(void) const;
	void Lock(void);
	void Unlock(void);
	void Stop(void);

private:
	void WorkerWork(void);
	bool WorkThread(std::thread& out);

private:
	W_LONG m_delay;
	W_FLOAT m_value;
	W_FLOAT m_from;
	W_FLOAT m_to;
	W_FLOAT m_alpha;

	std::thread* thr;
	std::mutex m_MutexLock;

	bool m_stop;
	bool m_isRunning;
	bool m_isLocked;

	WRegistry* m_LerpTickRegistry;
	WRegistry* m_LerpDoneRegistry;
};

#endif // !_W_LERP_H_
