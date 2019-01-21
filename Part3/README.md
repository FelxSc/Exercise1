# Reasons for concurrency and parallelism


To complete this exercise you will have to use git. Create one or several commits that adds answers to the following questions and push it to your groups repository to complete the task.

When answering the questions, remember to use all the resources at your disposal. Asking the internet isn't a form of "cheating", it's a way of learning.

 ### What is concurrency? What is parallelism? What's the difference?
 > Concurrency means that different parts of a program run at the same, but the processes only seem to run at the same time. These concurrent processes are interleaved. This means that every process has a specific time span in which it can be executed. If the process does not finish during this time slice, it is paused and another process is executed.
 > Parallelism means that processes are executed at the same time instant. This approach needs several processors to be made possible.
 > Difference: Concurrency is used on the single core and parallelism can be used with several cores.

 ### Why have machines become increasingly multicore in the past decade?
 > The frequency of CPUs did not increase over the last decade. To achieve faster program execution it is necessary to increase the number of processors in a machine. In this way, several processes can be executed in parallel.

 ### What kinds of problems motivates the need for concurrent execution?
 (Or phrased differently: What problems do concurrency help in solving?)
 > It increases the program throughput, because a single process which is independent of other processes can be finished without waiting for other processes to be finished first. Also whenever a program has to wait for operations to be finished, concurrent processes can be executed in the meantime.
 > Multiple threads within a process share the same data space and can therefore communicate more easily with each other.

 ### Does creating concurrent programs make the programmer's life easier? Harder? Maybe both?
 (Come back to this after you have worked on part 4 of this exercise)
 > It depends on the task. In Python it could make the developers life harder, because the threads might corrupt data that is accessed at the same time. In Go it might make the programmer's life easier, because it is made for Concurrency.

 ### What are the differences between processes, threads, green threads, and coroutines?
 > A process is an instance of a computer program that is being executed. It is the acutal execution of the program instructions.
 > A thread is a component of a process. It can be scheduled (typically by the OS) and therefore run concurrently. Several threads can exist concurrently within one process. Threads can share memory, processes cannot.
 > A green thread are scheduled by a runtime library or a virtual machine instead by an OS.
 > Coroutines are similar to threads. They are cooperatively multitasked, which means that not the OS initiates a context switch but the process itself. Therefore, coroutines provide concurrency, but not parallelism.

 ### Which one of these do `pthread_create()` (C/POSIX), `threading.Thread()` (Python), `go` (Go) create?
 > The 'pthread_create()'-function creates a new OS-thread in the calling process. The attributes of this thread can be configured by passing parameters to that function.
 > 'threading.Thread()' creates a thread in Python, to which a function is passed. Those threads are then executed concurrently.
 > 'go' launches a go-routine. It is a function executing concurrently with other go-routines. There can be several go-routines running in a thread. Threads have higher cost (in terms of memory space) than go-routines. Managed by the runtime library.

 ### How does pythons Global Interpreter Lock (GIL) influence the way a python Thread behaves?
 > The GIL is a mutex, that prevents several threads from being executed at the same time. This means only one thread is able to hold the control of the Python interpreter. If two threads simultaneously increment the reference count on an object, it could happen that it is only increased once. It can therefore be a bottleneck.

 ### With this in mind: What is the workaround for the GIL (Hint: it's another module)?
 > Python has the option to use the multiprocessing module. This module provides multiple processes instead of multiple threads. This means every process gets its own Python interpreter and memory space so that the GIL is no problem anymore, since there will only be a single thread in every process.

 ### What does `func GOMAXPROCS(n int) int` change?
 > It changes the maximum number of CPUs that can be executing simultaneously. If n is <1 it does not change anything.
