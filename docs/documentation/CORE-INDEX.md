# WARP CORE DOCUMENTATION: MAIN INDEX
#### WARP-CORE QUICKSTART
| TITLE 				  | DESCRIPTION 																|
|-------------------------|-----------------------------------------------------------------------------|
| [**Prerequisites**](CORE-PREREQ.md)   | Things you need before diving into Warp Core								|
| [**Quickstart**](CORE-QS.md) 	  | Quickstart guide to get you up and running with warp's core system 	|

# REFERENCE GUIDE


#### WARP-CORE CONTAINERS REFERENCE

|TITLE  			 |DESCRIPTION										|
|--------------------|--------------------------------------------------|
|[**WContainer**](CORE-WCONTAINER.md)| Main Container Class|
|[**WDXContainer**](CORE-WDXCONTAINER.md)| Container class holding Direct2D resources|
|[**WGFXContainer**](CORE-WGFXCONTAINER.md) | Container class holding the main instance of the WGraphics pointer|
|[**WREGContainer**](CORE-WREGCONTAINER.md) | Container class holding the global Registry data (Devices) |

#### WARP-CORE CORE REFERENCE

| TITLE 				  | DESCRIPTION 																|
|-------------------------|-----------------------------------------------------------------------------|
| [**WEntity**](CORE-WENTITY.md)   | The main parent class of the entire framework								|
| [**WEventBound**](CORE-WEVENTBOUND.md) | A bond between a bool and a Warp-Event 	|
| [**WGenerator**](CORE-WGENERATOR.md) | Simple implementation of a generator 	|
| [**WLogicalBound**](CORE-WLOGICALBOUND.md) | A bond between a void(&bool) method and a bool 	|
| [**WRegistry**](CORE-WREGISTRY.md) | Warp's main event registry class 	|
| [**WUniqueRegister**](CORE-WUNIQUEREGISTRY.md) | Warp's alternative event registry class (std::unique_ptr) 	|


#### WARP-CORE EVENT ARGS REFERENCE

| TITLE 				  | DESCRIPTION 																|
|-------------------------|-----------------------------------------------------------------------------|
| [**WEventArgs**](CORE-WEVENTARGS.md)   | The main parent class of all the argument classes								|
| [**WGeneratorArgs**](CORE-WGENERATORARGS.md) | Argument class that is passed through the WGenerator class 	|

#### WARP-CORE MAIN WINDOW REFERENCE

| TITLE 				  | DESCRIPTION 																|
|-------------------------|-----------------------------------------------------------------------------|
| [**WEntry**](CORE-WENTRY.md)   | The starting point of a warp Application|
| [**WMainWindow**](CORE-WMAINWINDOW.md) | C-Style main window (The actual entry of the framework) 	|

#### WARP-CORE MATH REFERENCE

| TITLE 				  | DESCRIPTION 																|
|-------------------------|-----------------------------------------------------------------------------|
| [**WMath**](CORE-WMATH.md)   | The warp's main Math calculation header|
| [**WMatrix2**](CORE-WMAT2.md)   | Simple 2x2 Matrix class|
| [**WMatrix3**](CORE-WMAT3.md)   | Simple 3x3 Matrix class|
| [**WVector2**](CORE-WVEC2.md)   | Simple Vector with 2 components|
| [**WVector3**](CORE-WVEC3.md)   | Simple Vector with 3 components|
| [**WVector4**](CORE-WVEC4.md)   | Simple Vector with 4 components|

#### WARP-CORE SYSTEM REFERENCE

| TITLE 				  | DESCRIPTION 																|
|-------------------------|-----------------------------------------------------------------------------|
| [**WChrono**](CORE-WCHRONO.md)   | Delta time calculation header file |
| [**WCODEC**](CORE-WCODEC.md)   | "Windowscodecs" linking header|
| [**WDefines**](CORE-WDEFINES.md)   | Cusomized data type defines |
| [**WDX**](CORE-WDX.md)   | "d2d1" / "dwrite" linking header|
| [**WMci**](CORE-WMCI.md)   | "Winmm" linking header|
| [**WSafeRelease**](CORE-WSAFERELEASE.md)   | Main COM resource release class|
| [**WUserSettings**](CORE-WUSERSETTINGS.md)   | User settings determining the version / name of the application|
| [**WWin**](CORE-WWIN.md)   | <Windows.h> option header file |

---
[Main index](INDEX.md)
