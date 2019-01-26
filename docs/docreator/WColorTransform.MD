**CLASSES:**
============
### **CLASS**: WColorTransform

``` class WColorTransform : public WEntity ```

##### **Description:** A Class for performing a smooth Linear Interpolation (LERP) color transformation between two colors

----------
**FUNCTIONS & METHODS:**
========================
### **FUNCTION**: WColorTransform

``` WColorTransform(W_COLOR From, W_COLOR To, W_FLOAT Alpha, W_LONG Delay) ```

 From: color value to begin with

 To: target color value

 Alpha: Alpha value of the LERP

 Delay: Delay between each LERP epoch

##### **Description:** Initialize all the required values to perform a color transformation

### **FUNCTION**: IsRunning

``` bool IsRunning(void) ```

 Returns: True if in transform, False if transform is finished. 

##### **Description:** Function to determine whether or not the Transformation is being performed

### **FUNCTION**: Perform

``` void Perform(void) ```

##### **Description:** Begin Transformation (no safeguards)

### **FUNCTION**: PerformSafe

``` void PerformSafe(void) ```

##### **Description:** Begin Transformation (with safeguards)

### **FUNCTION**: Stop

``` void Stop(void) ```

##### **Description:** Stop Transformation if it's already happening

----------
**MEMBERS:**
============
### **MEMBER**: m_delay

``` W_LONG m_delay ```

##### **Description:** Delay Between each epoch

### **MEMBER**: m_alpha

``` W_FLOAT m_alpha ```

##### **Description:** Alpha Value of LERP

### **MEMBER**: m_value

``` W_COLOR m_value ```

##### **Description:** Current Value of the LERP

### **MEMBER**: m_from

``` W_COLOR m_from ```

##### **Description:** Value to begin with

### **MEMBER**: m_to

``` W_COLOR m_to ```

##### **Description:** Target value to get close to

### **MEMBER**: m_CTTickRegistry

``` WRegistry* m_CTTickRegistry ```

##### **Description:** Function registry that is called on each Tick

### **MEMBER**: m_CTDoneRegistry

``` WRegistry* m_CTDoneRegistry ```

##### **Description:** Function registry that is called when transformation is finished

----------

###### Generated with [Docreator](https://github.com/nirex0/docreator)
