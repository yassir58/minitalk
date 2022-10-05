# minitalk (inter-process communication)

using c signals to establish communication between two processes:

I used signals SIG_USER1 and SIG_USER2 to encode the string message characters into bytes.
I used SIG_USER1 as binary number 0 and SIG_USER2 as binary number 1 after that I converted the binary number to its decimal representation
to get the ASCII character code.

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
