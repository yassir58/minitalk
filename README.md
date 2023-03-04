# minitalk project

<h1>inter-process communication</h1>

<p> Inter-process communication (IPC) refers to the mechanisms and techniques used by different processes to communicate with each other in a Unix-like operating system. IPC is a fundamental concept in Unix and is used to share data, resources, and synchronization between different processes running on the same system.

Unix provides several mechanisms for IPC, such as pipes, shared memory, message queues, signals, and sockets. Each mechanism has its own strengths and weaknesses, and the choice of which mechanism to use depends on the specific requirements of the application.

IPC is essential in many areas of computer science and software engineering, including client-server applications, multi-process systems, and distributed computing. Understanding the different mechanisms of IPC in Unix is crucial for building robust and efficient systems. </p>
using c signals to establish communication between two processes:

<h2>My approach</h2>

<p>To establish communication between two processes, I utilized C signals. Specifically, I encoded string messages into bytes using signals SIG_USER1 and SIG_USER2. I assigned SIG_USER1 as the binary number 0, and SIG_USER2 as binary number 1. To obtain the ASCII character code, I then converted the binary number to its decimal representation.</p>


 ```bash
# Clone this repository
$ git clone https://github.com/yassir58/minitalk
$ cd minitalk
# Build executable
$ make

#run ./server first to get the PID 
$ ./server
#run ./client  server-pid as a first argument and the string message as a second argument
#example
$ ./client 48415 "string message"
``
