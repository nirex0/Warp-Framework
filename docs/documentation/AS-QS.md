# WARP ASYNC: QUICKSTART

Article content:
- _Overall Content_
- _Async Overview_
- _Async in Warp_
---
### Overall Content:

In this article you will learn:
 
 - What async is.
 - What async programming is usually used for.
 - What warp uses async for.
 - Where warp uses async.
 - How to use warp-async.
 
---
### Async Overview:

Async (more formally known as asynchronous) programming is a means of parallel programming in which a unit of work runs separately from the main application [thread](AS-PREREQ.md#stdthread) and notifies the calling thread of its completion, failure or progress. 

Async programming is often used when the application needs to do a heavy task while not blocking the main thread from continuing to run.

Take a look at this code snippet below:
###### Snippet:
```cpp
#include <thread>
#include <iostream>
#include <string>

void PrintAsync();
void SetString(std::string in);

std::string name;

void PrintAsync()
{
	while (true)
	{
		if (name != "")
		{
			std::cout << name << std::endl;
			name = "";
		}
	}
}

void SetString(std::string in) 
{ 
	name = in; 
}

auto main(int argc, char** argv) -> int
{
	std::thread t1(PrintAsync);
	std::string local;
	t1.detach();

	while (true)
	{
		std::cin >> local;
		SetString(local);
	}
	return false;
}
```

One of the most common questions asked here is "Why use an extra function, wouldn't that be redundant? (SetString)"

And my answer to that, dear reader, is "NO, it's not redundant!", take a look at the snippet below and run it, notice that whatever you enter, only the first character will appear as the output, that's because STD::CIN put's the input value inside the string char by char (Streaming), and since the PrintAsync's loop is being run hyperfast over and over again, it'll print the string out before STD::CIN can give it any value.

```cpp
#include <thread>
#include <iostream>
#include <string>

void PrintAsync();

std::string name;

void PrintAsync()
{
	while (true)
	{
		if (name != "")
		{
			std::cout << name << std::endl;
			name = "";
		}
	}
}

auto main(int argc, char** argv) -> int
{
	std::thread t1(PrintAsync);
	t1.detach();

	while (true)
	{
		std::cin >> name;
	}
	return false;
}
```

So as you can see, there's an endless loop running in the background without having a major impact on your application's overall performance.

Now keep in mind, that async programming is by no means as simple as the example shown above.

---

### Async in Warp:

But where does **WARP** use async and what for?

Warp-Framework currently has four async component classes which help warp do what it should, Async is warp is mainly used for graphical animations and smooth transitions of points and values.

###### Snippet:
```cpp
int x = 10;
while(x < 0)
    x--;
```

As you can see this can be easily put into an async function; it works fine, but it's a very dull way of transitioning between 10 and 0, what we need is a beautiful way of doing things, that's why those four components exist.

You can continue reading here to see exactly how warp uses async:

1) [WLerp](AS-LERP.md)
2) [WSmoothStep](AS-SMOOTHSTEP.md)
3) [WColorTransition](AS-COLOR.md)
4) [WAsyncWorker](AS-WORKER.md)

---
[Back to Index](AS-INDEX.md)