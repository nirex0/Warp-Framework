# WARP ASYNC: LERP ARGS

Article content:
- _Linear interpolation Arguments_
- _Data_
- _Methods_
- _Example_
- _Header file_
---
### Linear interpolation Arguments:

###### Definition:
```cpp
class WLerpArgs : public WEventArgs
```

WLerpArgs is a class in which the calculated value that is passed through [WLerp](AS-LERP.md) events (**TICK** and **DONE**) is held.

---

### Data:

There's only one attribute held in WLerpArgs class and that is the ```m_Value``` of type ```float```.

```m_Value``` is the representative of the current calculated value in [WLerp](AS-LERP.md)

###### Definition:
```cpp
W_FLOAT	m_Value;
```
---

#### Methods:

##### 1) WLerpArgs::Constructor

###### Definition:
```cpp
WLerpArgs(W_FLOAT val);
```

The "Constructor" only takes one parameter which will be the value of the ```m_Value``` attribute.

The "Constructor" is the only method that 'sets' the value held within the instance of the WLerpArgs class.

|Parameters|Return Value|Events Raised  |
|----------|------------|---------------|
| ```float``` val   | (none)     | (none) |


##### 2) WLerpArgs::ValueExact

###### Definition
```cpp
W_FLOAT ValueExact(void) const;
```

The "ValueExact" Method simply returns the ```m_Value``` as a ```float``` data type.

|Parameters|Return Value|Events Raised  |
|----------|------------|---------------|
| (none)  | ```(float)m_value```     | (none) |

##### 3) WLerpArgs::ValueRounded

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
#include "WLerp.h"

WLerp* ExtentionLerp = new WLerp(0, 100, 0.03F, 1);
float value;

auto main(int argc, char** argv) -> int
{
    *ExtentionLerp->TickRegistry() += [&](WEntity* sender, WEventArgs* args)
    {
        WLerpArgs* LArgs = (WLerpArgs*)args;
        value = LArgs->ValueExact();
    }
    
    *ExtentionLerp->DoneRegistry() += [&](WEntity* sender, WEventArgs* args)
    {
        WLerpArgs* LArgs = (WLerpArgs*)args;
        value = (float)LArgs->ValueRounded();
    }

    ExtentionLerp.Perform();
    
    std::cin.get();
    return 0;
}	
```
### Header file
**```#include "WLerpArgs.h"```**

---
[Back to Index](AS-INDEX.md)