
# 42-Minitalk

First time I made this project I printed each character as soon as it was transmitted to the server, but later I realized that this way was against the rules! Now the server only prints when the whole string is passed!

### Mandatory Part

You must create a communication program in the form of a client and a server.

- The server must be started first. After its launch, it has to print its PID.
- The client takes two parameters:
- The server PID.
- The string to send.
- The client must send the string passed as a parameter to the server.

#### Once the string has been received, the server must print it. 

- The server has to display the string pretty quickly.
- Your server should be able to receive strings from several clients in a row  - without needing to restart.
- The communication between your client and your server has to be done only using UNIX signals.
- You can only use these two signals: SIGUSR1 and SIGUSR2.













## What i learned:
 - UNIX Signals
 - Bitwise operations
 - C programming
 - Basic algorithms

## Installation and Running

Install minitalk with make

```bash
  make
  make bonus
```
    
