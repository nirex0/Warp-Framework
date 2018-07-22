# WARP ASYNC: COLOR TRANSFORM
Article content:
- _Color transform in warp_
- _Methods_
- _Events_
- _Example_
- _Header file_
---
### Color transform in warp:

###### Definition:
```cpp
class WColorTransform : public WEntity;
```

Color transform uses the linear interpolation formula to transit from Color-A to Color-B.

The lerp formula is applied to every component of the value Color. (Red, Green, Blue, Alpha)


|Parameters|Description|
|----------|------------|
| ```from``` | The source color |
| ```to``` | The destination color |
| ```alpha``` | The percentage


---

#### Parameters:

Much like the WLerp, WColorTransform takes four parameters.

|Parameters|Description|
|----------|------------|
| ```from``` | The source color |
| ```to``` | The destination color |
| ```alpha``` | The percentage
| ```delay``` | The duration of each **Transit Tick** in milliseconds
---

#### Methods:

##### 1) WCOLORTRANSFORM::PEFRORM

###### Definition:
```cpp
void Perform(void);
```

The "Perform" method starts the calculation in and raises the **TICK** event everytime the calculation makes progress.

The "Perform" method sets the m_isRunning flag to 1 on call.

The "Perform" methods raises the **DONE** event when it's finished its calculation.


|Parameters|Return Value|Events Raised  |
|----------|------------|---------------|
| (none)   | (none)     | TICK and DONE |

##### 2) WCOLORTRANSFORM::PERFORM SAFE

###### Definition:
```cpp
void PerformSafe(void);
```

The "PerformSafe" method returns if the m_isRunning flag is already set to 1.

The "PerformSafe" method starts the calculation in and raises the **TICK** event everytime the calculation makes progress.

The "PerformSafe" method sets the m_isRunning flag to 1 on call.

The "PerformSafe" methods raises the **DONE** event when it's finished its calculation.

|Parameters|Return Value|Events Raised  |
|----------|------------|---------------|
| (none)   | (none)     | TICK and DONE |

##### 3) WCOLORTRANSFORM::STOP

###### Definition:
```cpp
void Stop(void);
```

The "Stop" method stops the class's continuation of calculation. 

The "Stop" method sets the m_stop flag to 1.

The "Stop" method sets the m_stop flag to 0 after the color transform has stopped.

|Parameters|Return Value|Events Raised  |
|----------|------------|---------------|
| (none)   | (none)     | (none)        |

---
### Events:

##### 1) WCOLORTRANSFORM::TICK

**TICK** is raised everytime the calculation makes a progress.

**TICK** sends the instance of the WColorTransform class and a new instance of [WColorTransformArgs](AS-COLORARGS.md) class holding the current calculation value.

|Parameters| Types      | Values |
|----------|------------|--------|
| Sender   | WEntity    | ```this```|
| Arguments| WEventArgs | ```m_value```|

##### 2) WCOLORTRANSFORM::DONE

**DONE** is raised when the calculation is 100% completed.

**DONE** sends the instance of the WColorTransform calss and a new instance of [WColorTransformArgs](AS-COLORARGS.md) class holding the ```to``` value of the WColorTransform class.

|Parameters| Types      | Values |
|----------|------------|--------|
| Sender   | WEntity    | ```this```|
| Arguments| WEventArgs | ```m_to```|

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
        value = ColorArgs->Value();
    }

    ExtentionTransform.Perform();
    
    std::cin.get();
    return 0;
}	
```
### Header file
**```#include "WColorTransform.h"```**

---
[Back to Index](AS-INDEX.md)
