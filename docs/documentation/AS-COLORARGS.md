# WARP ASYNC: COLOR TRANSFORM ARGS

Article content:
- _Color Transform Arguments_
- _Data_
- _Methods_
- _Example_
- _Header file_
---
### Color Transform Arguments:

###### Definition:
```cpp
class WColorTransformArgs : public WEventArgs
```

WColorTransformArgs is a class in which the calculated value that is passed through [WColorTransform](AS-COLOR.md) events (**TICK** and **DONE**) is held.

---

### Data:

There's only one attribute held in WColorTransformArgs class and that is the ```m_Value``` of type ```W_COLOR```.

```m_Value``` is the representative of the current calculated value in [WColorTransform](AS-COLOR.md).

###### Definition:
```cpp
W_FLOAT	m_Value;
```
---

#### Methods:

##### 1) WColorTransformArgs::Constructor

###### Definition:
```cpp
WColorTransformArgs(W_COLOR val);
```

The "Constructor" only takes one parameter which will be the value of the ```m_Value``` attribute.

The "Constructor" is the only method that 'sets' the value held within the instance of the WColorTransformArgs class.

|Parameters|Return Value|Events Raised  |
|----------|------------|---------------|
| ```W_COLOR``` val   | (none)     | (none) |


##### 2) WColorTransformArgs::Value

###### Definition
```cpp
W_COLOR Value(void) const;
```

The "ValueExact" Method simply returns the ```m_Value``` as a ```W_COLOR``` data type.

|Parameters|Return Value|Events Raised  |
|----------|------------|---------------|
| (none)  | ```(W_COLOR)m_value```     | (none) |

---
### Example:
```cpp
#include <iostream>
#include "WDefines.h"
#include "WGraphics.h"
#include "WColorTransform.h"

WGraphics* graphics = new WGraphics();
WColorTransform* ExtentionTransform = new WColorTransform(graphics->FromRGBA(0,0,255), graphics->FromRGBA(255,0,0), 0.03f, 1);
WColor value;

auto main(int argc, char** argv) -> int
{
    *ExtentionTransform->TickRegistry() += [&](WEntity* sender, WEventArgs* args)
    {
        WColorTransformArgs* ColorArgs = (WColorTransformArgs*)args;
        value = ColorArgs->Value();
    }
    
    *ExtentionTransform->DoneRegistry() += [&](WEntity* sender, WEventArgs* args)
    {
        WColorTransformArgs* ColorArgs = (WColorTransformArgs*)args;
        value = (float)ColorArgs->Value();
    }

    ExtentionTransform.Perform();
    
    std::cin.get();
    return 0;
}	
```
### Header file
**```#include "WColorTransformArgs.h"```**

---
[Back to Index](AS-INDEX.md)