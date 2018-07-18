# WARP ASYNC: PREREQUISITES
---
Article content:
- _std::thread_
- _std::promise_
- _std::mutex_
- _std::terminate_
---

### STD::THREAD

###### Definition:
```cpp
class thread;
```

The class thread represents a single thread of execution. Threads allow multiple functions to execute concurrently.

Threads begin execution immediately upon construction of the associated thread object (pending any OS scheduling delays), starting at the top-level function provided as a constructor argument. The return value of the top-level function is ignored and if it terminates by throwing an exception, std::terminate is called. The top-level function may communicate its return value or an exception to the caller via std::promise or by modifying shared variables.

**Header File: ```<thread>```**

[**CppReference Link**](https://en.cppreference.com/w/cpp/thread/thread)

---
### STD::PROMISE

###### Definition:
```
1. template< class R > class promise;
2. template< class R > class promise<R&>;
3. template<>          class promise<void>;
```

###### Description:
1. base template
2. non-void specialization, used to communicate objects between threads
3. void specialization, used to communicate stateless events

The class template std::promise provides a facility to store a value or an exception that is later acquired asynchronously via a std::future object created by the std::promise object. Note that the std::promise object is meant to be used only once.

Each promise is associated with a shared state, which contains some state information and a result which may be not yet evaluated, evaluated to a value (possibly void) or evaluated to an exception. A promise may do three things with the shared state:

make ready: the promise stores the result or the exception in the shared state. Marks the state ready and unblocks any thread waiting on a future associated with the shared state.
release: the promise gives up its reference to the shared state. If this was the last such reference, the shared state is destroyed. Unless this was a shared state created by std::async which is not yet ready, this operation does not block.
abandon: the promise stores the exception of type std::future_error with error code std::future_errc::broken_promise, makes the shared state ready, and then releases it.
The promise is the "push" end of the promise-future communication channel: the operation that stores a value in the shared state synchronizes-with (as defined in std::memory_order) the successful return from any function that is waiting on the shared state (such as std::future::get). Concurrent access to the same shared state may conflict otherwise: for example multiple callers of std::shared_future::get must either all be read-only or provide external synchronization.

**Header File: ```<future>```**

[**CppReference Link**](https://en.cppreference.com/w/cpp/thread/promise)

---
### STD::MUTEX 
###### Definition:
```cpp
class mutex;
```

The mutex class is a synchronization primitive that can be used to protect shared data from being simultaneously accessed by multiple threads.

mutex offers exclusive, non-recursive ownership semantics:

A calling thread owns a mutex from the time that it successfully calls either lock or try_lock until it calls unlock.
When a thread owns a mutex, all other threads will block (for calls to lock) or receive a false return value (for try_lock) if they attempt to claim ownership of the mutex.
A calling thread must not own the mutex prior to calling lock or try_lock.
The behavior of a program is undefined if a mutex is destroyed while still owned by any threads, or a thread terminates while owning a mutex. The mutex class satisfies all requirements of Mutex and StandardLayoutType.

std::mutex is neither copyable nor movable.

**Header File: ```<mutex>```**

[**CppReference Link**](https://en.cppreference.com/w/cpp/thread/mutex)

---
### STD::TERMINATE

###### Definition:
```cpp
void terminate();
[[noreturn]] void terminate() noexcept;
```

std::terminate() is called by the C++ runtime when exception handling fails for any of the following reasons:

1. an exception is thrown and not caught (it is implementation-defined whether any stack unwinding is done in this case)
2. an exception is thrown during exception handling (e.g. from a destructor of some local object, or from a function that had to be called during exception handling)
3. the constructor or the destructor of a static or thread-local object throws an exception
4. a function registered with std::atexit or std::at_quick_exit throws an exception
5. a noexcept specification is violated (it is implementation-defined whether any stack unwinding is done in this case)
6. a dynamic exception specification is violated and the default handler for std::unexpected is executed
7. a non-default handler for std::unexpected throws an exception that violates the previously violated dynamic exception secification, if the specification does not include std::bad_exception
8. std::nested_exception::rethrow_nested is called for an object that isn't holding a captured exception
9. an exception is thrown from the initial function of std::thread
10. a joinable std::thread is destroyed or assigned to
11. a function invoked by a parallel algorithm exits via an uncaught exception and the execution policy specifies termination.

_NOTE: std::terminate() may also be called directly from the program._

In any case, std::terminate calls the currently installed std::terminate_handler. The default std::terminate_handler calls std::abort.

If a destructor reset the terminate handler during stack unwinding and the unwinding later led to terminate being called, the handler that was installed at the end of the throw expression is the one that will be called. (note: it was ambiguous whether re-throwing applied the new handlers)

If a destructor reset the terminate handler during stack unwinding, it is unspecified which handler is called if the unwinding later led to terminate being called.


|Parameters|Return Value|Defections|
|----------|------------|----------|
| (none)   | (none)     | [LWG 2111](https://cplusplus.github.io/LWG/issue2111)|


**Header File: ```<exception>```**

[**CppReference Link**](https://en.cppreference.com/w/cpp/error/terminate)

---
[Back to Index](AS-INDEX.md)
