# WARP ASYNC: SMOOTHSTEP
Article content:
- _Smooth step_
- _Smooth step in Warp_
- _Methods_
- _Events_
- _Example_
- _Header file_
---
### Smooth step:

The function depends on three parameters, the input x, the "left edge" and the "right edge", with the left edge being assumed smaller than the right edge. The function receives a real number x as an argument and returns 0 if x is less than or equal to the left edge, 1 if x is greater than or equal to the right edge, and smoothly interpolates, using a Hermite polynomial, between 0 and 1 otherwise. The slope of the smoothstep function is zero at both edges. This is convenient for creating a sequence of transitions using smoothstep to interpolate each segment as an alternative to using more sophisticated or expensive interpolation techniques.

|Parameters|Description|
|----------|------------|
| ```from``` | The left edge |
| ```to``` | The right edge |

Functions: 
```cpp
float Clamp(float x, float lowerlimit, float upperlimit) 
{
  if (x < lowerlimit)
    x = lowerlimit;
  if (x > upperlimit)
    x = upperlimit;
  return x;
}

float SmoothStep(float edge0, float edge1, float x) 
{
  x = Clamp((x - edge0) / (edge1 - edge0), 0.0, 1.0); 
  return x * x * (3 - 2 * x);
}
```
---

### Smooth step in Warp

###### Definition:
```cpp
class WSmoothStep : public WEntity;
```

Warp Smooth Step class works much like the one explained above.

Warp begins calculation by giving SmoothStep the **left edge** as the value and smoothly going towards the **right edge**.

Warp does this calculation on every **Tick** and raises and event (see WRegistry) which holds this calculated value within it's argument (see [WSmoothStepArgs](AS-SMOOTHSTEPARGS.md)) which is later used to create animations.

---

#### Parameters:

|Parameters|Description|
|----------|------------|
| ```from``` | The left edge |
| ```to``` | The right edge |
| ```delay``` | The duration of each **Tick** in milliseconds

---

#### Methods:

##### 1) WSMOOTHSTEP::PEFRORM

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

##### 2) WSMOOTHSTEP::PERFORM SAFE

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

##### 3) WSMOOTHSTEP::STOP

###### Definition:
```cpp
void Stop(void);
```

The "Stop" method tries to stop the class's continuation of calculation. 

The "Stop" method sets the m_stop flag to 1.

The "Stop" method sets the m_stop flag to 0 after the smoothstep has stopped.

|Parameters|Return Value|Events Raised  |
|----------|------------|---------------|
| (none)   | (none)     | (none)        |

---
### Events:

##### 1) WSMOOTHSTEP::TICK

**TICK** is raised everytime the calculation makes a progress.

**TICK** sends the instance of the WSmoothStep class and a new instance of [WSmoothStepArgs](AS-SMOOTHSTEPARGS.md) class holding the current calculation value.

|Parameters| Types      | Values |
|----------|------------|--------|
| Sender   | WEntity    | ```this```|
| Arguments| WEventArgs | ```m_value```|

##### 2) WSMOOTHSTEP::DONE

**DONE** is raised when the calculation is 100% completed.

**DONE** sends the instance of the WSmoothStep calss and a new instance of [WSmoothStepArgs](AS-SMOOTHSTEPARGS.md) class holding the ```to``` value of the WSmoothStep class.

|Parameters| Types      | Values |
|----------|------------|--------|
| Sender   | WEntity    | ```this```|
| Arguments| WEventArgs | ```m_to```|

---
### Example:
```cpp
#include <iostream>
#include "WSmoothStep.h"

WSmoothStep* ExtentionStep = new WSmoothStep(0, 100, 1);
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
**```#include "WSmoothStep.h"```**

---
[Back to Index](AS-INDEX.md)
