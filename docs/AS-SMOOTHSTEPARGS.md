# WARP ASYNC: SMOOTH STEP ARGS

Article content:
- _Smooth step Arguments_
- _Data_
- _Methods_
- _Example_
- _Header file_
---
### Smooth step Arguments:

###### Definition:
```cpp
class WSmoothStepArgs : public WEventArgs
```

WSmoothStepArgs is a class in which the calculated value that is passed through [WSmoothStep](AS-SMOOTHSTEP.md) events (**TICK** and **DONE**) is held.

---

### Data:

There's only one attribute held in WSmoothStepArgs class and that is the ```m_Value``` of type ```float```.

```m_Value``` is the representative of the current calculated value in [WSmoothStep](AS-SMOOTHSTEP.md).

###### Definition:
```cpp
W_FLOAT	m_Value;
```
---

#### Methods:

##### 1) WSmoothStepArgs::Constructor

###### Definition:
```cpp
WSmoothStepArgs(W_FLOAT val);
```

The "Constructor" only takes one parameter which will be the value of the ```m_Value``` attribute.

The "Constructor" is the only method that 'sets' the value held within the instance of the WSmoothStepArgs class.

|Parameters|Return Value|Events Raised  |
|----------|------------|---------------|
| ```float``` val   | (none)     | (none) |


##### 2) WSmoothStepArgs::ValueExact

###### Definition
```cpp
W_FLOAT ValueExact(void) const;
```

The "ValueExact" Method simply returns the ```m_Value``` as a ```float``` data type.

|Parameters|Return Value|Events Raised  |
|----------|------------|---------------|
| (none)  | ```(float)m_value```     | (none) |

##### 3) WSmoothStepArgs::ValueRounded

###### Definition
```cpp
W_INT ValueRounded(void) const;
```
The "ValueExact" Method simply returns the ```m_Value``` as an ```int``` data type.

|Parameters|Return Value|Events Raised  |
|----------|------------|---------------|
| (none)  | ```(int)m_value```     | (none) |

---
### Example:
```cpp
#include <iostream>
#include "WSmoothStep.h"

WSmoothStep* ExtentionStep = new ExtentionStep(0, 100, 1);
float value;

auto main(int argc, char** argv) -> int
{
    *ExtentionStep->TickRegistry() += [&](WEntity* sender, WEventArgs* args)
    {
        WSmoothStepArgs* SArgs = (WSmoothStepArgs*)args;
        value = SArgs->ValueExact();
    }
    
    *ExtentionStep->DoneRegistry() += [&](WEntity* sender, WEventArgs* args)
    {
        WSmoothStepArgs* SArgs = (WSmoothStepArgs*)args;
        value = (float)SArgs->ValueRounded();
    }

    ExtentionStep.Perform();
    
    std::cin.get();
    return 0;
}	
```
### Header file
**```#include "WSmoothStepArgs.h"```**

---
[Back to Index](AS-INDEX.md)