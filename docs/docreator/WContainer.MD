**CLASSES:**
============
### **CLASS**: WContainer

``` class WContainer final ```

##### **Description:** A Container class that allows access to a set of global static variables throughout the framework

----------
**MEMBERS:**
============
### **MEMBER**: HR

``` static HRESULT HR ```

##### **Description:**Holds the HRESULT of the last done operation

### **MEMBER**: hWnd

``` static HWND hWnd ```

##### **Description:**A Handle to the main window of the framework

### **MEMBER**: msg

``` static UINT msg ```

##### **Description:**Last Sent Message through the windows message loop

### **MEMBER**: wParam

``` static WPARAM wParam ```

##### **Description:**WParam of the windows message loop

### **MEMBER**: lParam

``` static LPARAM lParam ```

##### **Description:**LParam of the windows message loop

### **MEMBER**: WFramework

``` static WEntry WFramework ```

##### **Description:**Entry Class

### **MEMBER**: DeltaTime

``` static DELTATIME DeltaTime ```

##### **Description:**Current Delta Time of the render engine

### **MEMBER**: BGA

``` static W_INT BGA ```

##### **Description:**Background alpha value

### **MEMBER**: BGR

``` static W_INT BGR ```

##### **Description:**Background red value

### **MEMBER**: BGG

``` static W_INT BGG ```

##### **Description:**Background green value

### **MEMBER**: BGB

``` static W_INT BGB ```

##### **Description:**Background blue value

### **MEMBER**: W_WIDTH

``` static W_INT W_WIDTH ```

##### **Description:**Current Window Width

### **MEMBER**: W_HEIGHT

``` static W_INT W_HEIGHT ```

##### **Description:**Current Window Height

### **MEMBER**: mouse

``` static WMouse* mouse ```

##### **Description:**Pointer to the mouse object

### **MEMBER**: keyboard

``` static WKeyboard* keyboard ```

##### **Description:**Pointer to the keyboard object

### **MEMBER**: helperCoordX

``` static W_INT helperCoordX ```

##### **Description:**RESERVED FOR DRAGMOVE WINDOW MOVEMENT

### **MEMBER**: helperCoordY

``` static W_INT helperCoordY ```

##### **Description:**RESERVED FOR DRAGMOVE WINDOW MOVEMENT

### **MEMBER**: bDragMove

``` static BOOL bDragMove ```

##### **Description:**Holder for whether or not window is in a DragMove State

### **MEMBER**: wTheme

``` static WTheme wTheme ```

##### **Description:**Theme of the framework

----------

###### Generated with [Docreator](https://github.com/nirex0/docreator)