# WARP ASYNC: ASYNC WORKER
Article content:
- _Async Worker_
- _Methods_
- _Events_
- _Example_
- _Header file_
---

### Async Worker

###### Definition:
```cpp
class WAsyncArgs : public WEntity;
```

Warp Async worker is a simple loop which raises a specific event every time it **TICKS**

Warp Async worker will continue to run until **WASYNCWORKER::STOP** is called 

---

#### Parameters:

|Parameters|Description|
|----------|------------|
| ```delay``` | The duration of each **TICK** in milliseconds

---

#### Methods:

##### 1) WASYNCWORKER::PEFRORM

###### Definition:
```cpp
void Perform(void);
```

The "Perform" method starts the calculation in and raises the **TICK** event everytime the calculation makes progress.

The "Perform" method sets the m_isRunning flag to 1 on call.


|Parameters|Return Value|Events Raised  |
|----------|------------|---------------|
| (none)   | (none)     | TICK |

##### 2) WASYNCWORKER::PERFORM SAFE

###### Definition:
```cpp
void PerformSafe(void);
```

The "PerformSafe" method returns if the m_isRunning flag is already set to 1.

The "PerformSafe" method starts the calculation in and raises the **TICK** event everytime the calculation makes progress.

The "PerformSafe" method sets the m_isRunning flag to 1 on call.

|Parameters|Return Value|Events Raised  |
|----------|------------|---------------|
| (none)   | (none)     | TICK |

##### 3) WASYNCWORKER::STOP

###### Definition:
```cpp
void Stop(void);
```

The "Stop" method ends the worker's main loop.

The "Stop" method sets the m_stop flag to 1.

The "Stop" method sets the m_stop flag to 0 after the worker has stopped.

|Parameters|Return Value|Events Raised  |
|----------|------------|---------------|
| (none)   | (none)     | (none)        |

---
### Events:

##### 1) WASYNCWORKER::TICK

**TICK** is raised everytime the worker begins finishes the loop.

**TICK** sends the instance of the WAsyncWorker class and a new instance of [WAsyncArgs](AS-WORKERARGS.md) which holds nothing.

|Parameters| Types      | Values |
|----------|------------|--------|
| Sender   | WEntity    | ```this```|
| Arguments| WEventArgs | (none)|

---
### Example:
```cpp
#include <iostream>
#include "WAsyncWorker.h"

WAsyncWorker* ExtentionWorker = new WAsyncWorker();
int value;

auto main(int argc, char** argv) -> int
{
    *ExtentionWorker->WorkRegistry() += [&](WEntity* sender, WEventArgs* args)
    {
        value += 1;
    }
    ExtentionWorker.Perform();
    
    std::cin.get();
    return 0;
}	
```
### Header file
**```#include "WAsyncWorker.h"```**

---
[Back to Index](AS-INDEX.md)
