**CLASSES:**
============
### **CLASS**: WAsyncWorker

``` class WAsyncWorker : public WEntity ```

##### **Description:** A class to perform Async tasks that require iteration

----------
**FUNCTIONS & METHODS:**
========================
### **FUNCTION**: RunWorkerAsync

``` void RunWorkerAsync(void) ```

##### **Description:** Begin Async Worker (no safeguards)

### **FUNCTION**: RunWorkerAsyncSafe

``` void RunWorkerAsyncSafe(void) ```

##### **Description:** Begin Async Worker (with safeguards)

### **FUNCTION**: IsRunning

``` bool IsRunning(void) ```

 Returns: True if working, False otherwise. 

##### **Description:** Function to determine whether or not the Worker is working

### **FUNCTION**: Stop

``` void Stop(void) ```

##### **Description:** Stop Async Worker if it's working

----------
**MEMBERS:**
============
### **MEMBER**: m_delay

``` W_LONG m_delay ```

##### **Description:** Delay Between each epoch

### **MEMBER**: m_WorkRegistry

``` WRegistry* m_WorkRegistry ```

##### **Description:** Function registry that is called on each Tick

----------

###### Generated with [Docreator](https://github.com/nirex0/docreator)