**CLASSES:**
============
### **CLASS**: WSmoothStepArgs

``` class WSmoothStepArgs : public WEventArgs ```

##### **Description:** Arguments passed through the WSmoothStep Registry classes

----------
**FUNCTIONS & METHODS:**
========================
### **FUNCTION**: WSmoothStepArgs

``` WSmoothStepArgs(W_FLOAT val) ```

 Constructor of the WSmoothStepArgs class

##### **Description:** val: Argument value to be passed through the WSmoothStep Registry

### **FUNCTION**: ValueExact

``` W_FLOAT ValueExact(void) const ```

##### **Description:** Value Getter function (With Precision)

### **FUNCTION**: ValueRounded

``` W_INT ValueRounded(void) const ```

##### **Description:** Value Getter function (Rounded)

----------
**MEMBERS:**
============
### **MEMBER**: W_FLOAT	m_Value

``` W_FLOAT	m_Value ```

##### **Description:** Value to be sent through the WSmoothStep Registry

----------

###### Generated with [Docreator](https://github.com/nirex0/docreator)