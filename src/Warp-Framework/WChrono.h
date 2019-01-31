// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_CHRONO_H_
#define _W_CHRONO_H_

#include "WDefines.h"

#include <chrono>

typedef std::chrono::duration<W_LONG, std::ratio<1, 60>> sixtieths_of_a_sec;
constexpr auto kMaxDeltatime = sixtieths_of_a_sec{ 1 };
using WClock = std::chrono::steady_clock;
auto mLastEndTime = WClock::now();
DELTATIME milliseconds = 0.0;

#endif // !_W_CHRONO_H_
