# WARP ASYNC: ASYNC WORKER ARGS

Article content:
- _Async Worker Arguments_
- _Example_
- _Header file_
---
### Async Worker Arguments:

###### Definition:
```cpp
class WAsyncArgs : public WEventArgs
```

WAsyncArgs is a class which holds no data and  is used by the [WAsyncWorker](AS-WORKER.md).

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
**```#include "WAsyncArgs.h"```**

---
[Back to Index](AS-INDEX.md)