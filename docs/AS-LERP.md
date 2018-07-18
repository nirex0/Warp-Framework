# WARP ASYNC: LERP
Article content:
- _Linear interpolation_
- _Linear interpolation in Warp_
- _Methods_
- _Events_
- _Example_
- _Header file_
---
### Linear interpolation:

Linearly interpolating is finding a value that is some percentage between two given values

|Parameters|Description|
|----------|------------|
| ```from``` | The minimum value |
| ```to``` | The maximum value
| ```alpha``` | The percentage

Return Value: **```from``` + (```to``` - ```from```) * ```alpha```**

EXAMPLE: 
_Lerp( 0, 100, 0.1) = 10_
_Lerp( 0, 100, 0.8) = 80_
_Lerp( 0, 50, 0.5 ) = 25_
_Lerp( 100, 0, 0.5 ) = 50_

---

### Linear interpolation in Warp

###### Definition:
```cpp
class WLerp : public WEntity;
```

Warp Lerp class is different from a regular linear interpolation.
When warp calculates the Lep it sets the 'from' value to the last calculated Lerp() value, Creating a smooth transition between ```from``` and ```to```.

WLerp does this calculation on every **Lerp Tick** and raises and event (see WRegistry) which holds this calculated value within it's argument (see WLerpArgument) which is later used to create animations.

---

#### Parameters:

Unlike the actual lerp, WLerp takes four parameters instead of the usual three

|Parameters|Description|
|----------|------------|
| ```from``` | The minimum value |
| ```to``` | The maximum value
| ```alpha``` | The percentage
| ```delay``` | The duration of each **Lerp Tick** in milliseconds

---

#### Methods:

##### 1) WLERP::PEFRORM

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

##### 2) WLERP::PERFORM SAFE

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

##### 3) WLERP::LOCK

###### Definition:
```cpp
void Lock(void);
```

The "Lock" method locks the lerp to its current value and won't let any events to be raised.
The "Lock" method sets the m_isLocked to 1.

|Parameters|Return Value|Events Raised  |
|----------|------------|---------------|
| (none)   | (none)     | (none)        |

##### 4) WLERP::UNLOCK

###### Definition:
```cpp
void Unlock(void);
```

The "Lock" method unlocks the lerp and allows the calculation to be continued.
The "Lock" method sets the m_isLocked to 0.

|Parameters|Return Value|Events Raised  |
|----------|------------|---------------|
| (none)   | (none)     | (none)        |
	
##### 5) WLERP::ISLOCKED

###### Definition:
```cpp
bool IsLocked(void) const;
```

The "IsLocked" method returns the m_isLocked flag without changing it.

|Parameters|Return Value|Events Raised  |
|----------|------------|---------------|
| (none)   | m_isLocked | (none)        |


##### 6) WLERP::STOP

###### Definition:
```cpp
void Stop(void);
```

The "Stop" method tries to stop the class's continuation of calculation. 
The "Stop" method sets the m_stop flag to 1.
The "Stop" method sets the m_stop flag to 0 after the lerp has stopped.

|Parameters|Return Value|Events Raised  |
|----------|------------|---------------|
| (none)   | (none)     | (none)        |

---
### Events:

##### 1) WLERP::TICK

**TICK** is raised everytime the calculation makes a progress.
**TICK** sends the instance of the WLerp class and a new instance of WLerpArgs class holding the current calculation value.

|Parameters| Types      | Values |
|----------|------------|--------|
| Sender   | WEntity    | ```this```|
| Arguments| WEventArgs | ```m_value```|

##### 2) WLERP::DONE

**DONE** is raised when the calculation is 100% completed.
**DONE** sends the instance of the WLerp calss and a new instance of WLerpArgs class holding the ```to``` value of the WLerp class.

|Parameters| Types      | Values |
|----------|------------|--------|
| Sender   | WEntity    | ```this```|
| Arguments| WEventArgs | ```m_to```|

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
        value = LArgs;
    }
    
    *ExtentionLerp->DoneRegistry() += [&](WEntity* sender, WEventArgs* args)
    {
        WLerpArgs* LArgs = (WLerpArgs*)args;
        value = LArgs;
    }

    ExtentionLerp.Perform();
    
    std::cin.get();
    return 0;
}	
```
### Header file
**```#include "WLerp.h"```**

---
[Back to Index](AS-INDEX.md)
