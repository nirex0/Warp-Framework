// © 2019 NIREX ALL RIGHTS RESERVED

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

//-->DOC_CLASS
// A Class for performing a smooth Linear Interpolation (LERP) color transformation between two colors
class WColorTransform : public WEntity
{
public:
	//-->DOC_FUNC
	// Initialize all the required values to perform a color transformation
	// From: color value to begin with
	// To: target color value
	// Alpha: Alpha value of the LERP
	// Delay: Delay between each LERP epoch
	WColorTransform(W_COLOR From, W_COLOR To, W_FLOAT Alpha, W_LONG Delay);
	~WColorTransform(void);

	WRegistry* TickRegistry(void) const;
	WRegistry* DoneRegistry(void) const;

	W_LONG Delay(void) const;
	W_FLOAT Alpha(void) const;
	W_COLOR Value(void) const;
	W_COLOR From(void) const;
	W_COLOR To(void) const;

	//-->DOC_FUNC
	// Function to determine whether or not the Transformation is being performed
	// Returns: True if in transform, False if transform is finished. 
	bool IsRunning(void);

	WRegistry* TickRegistry(WRegistry* intake);
	WRegistry* DoneRegistry(WRegistry* intake);

	W_LONG Delay(W_LONG intake);
	W_FLOAT Alpha(W_FLOAT intake);
	W_COLOR Value(W_COLOR intake);
	W_COLOR From(W_COLOR intake);
	W_COLOR To(W_COLOR intake);
	
	//-->DOC_FUNC
	// Begin Transformation (no safeguards)
	void Perform(void);

	//-->DOC_FUNC
	// Begin Transformation (with safeguards)
	void PerformSafe(void);

	//-->DOC_FUNC
	// Stop Transformation if it's already happening
	void Stop(void);

private:
	void WorkerWork(void);
	bool WorkThread(std::thread& out);

private:
	//-->DOC_MEMBER
	// Delay Between each epoch
	W_LONG m_delay;

	//-->DOC_MEMBER
	// Alpha Value of LERP
	W_FLOAT m_alpha;

	//-->DOC_MEMBER
	// Current Value of the LERP
	W_COLOR m_value;

	//-->DOC_MEMBER
	// Value to begin with
	W_COLOR m_from;

	//-->DOC_MEMBER
	// Target value to get close to
	W_COLOR m_to;

	std::thread* thr;
	std::mutex m_MutexLock;

	bool m_stop;
	bool m_isRunning;

	//-->DOC_MEMBER
	// Function registry that is called on each Tick
	WRegistry* m_CTTickRegistry;

	//-->DOC_MEMBER
	// Function registry that is called when transformation is finished
	WRegistry* m_CTDoneRegistry;
};

#endif // !_W_COLOR_TRANSFORM_H_
