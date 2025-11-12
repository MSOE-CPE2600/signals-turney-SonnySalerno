# Repo for Lab Week 10
## Description:
Use of signals as an inter process communication. Shows how to register a signal handler as well as how to
send, suspend, and view pending signals.

---

## How to Build
### To compile using `make`:
```bash
make clean
```
```bash
make
```

## This will generate multiple executable files

```bash
./signal_handler
```
```bash
./signal_alarm
```
```bash
./signal_segfault
```
```bash
./signal_sigaction
```
```bash
./recv_signal
```
```bash
./send_signal
```

### To compile manually:

`gcc -o exe filename.c`

---

## Description and how to run executable:

### <ins>Signal Handler</ins>
Handles `POSIX` signals like `SIGINT` demonstrates how a program can intercept and respond to user generated signals.
```
./signal_handler
```
Two ways to send the `SIGINT` signal to the process:

- Pressing 'Ctrl+C'

- In another terminal, type 'kill -2 pid' or 'kill -SIGINT pid'


### <ins>Signal Alarm</ins>
Sets and alarm using the `alarm()` function and handles `SIGALRM` signal after a specified delayed time (e.g. 5 seconds). Signals uses timers for asynchronous events.
```
./signal_alarm
```

### <ins>Signal Segfault</ins>
Triggers a segmentation fault by dereferencing a null pointer. Signal handler for `SIGSEGV` detects and prints a fault message.
```
./signal_segfault
```


### <ins>Signal Sigaction</ins>
Uses the `sigaction()` function to register a signal handler for `SIGUSR1`. The program waits for a signal and prints details about the sender when `SIGUSR1` is recieved.
```
./signal_sigaction
```
- In another terminal, type 'kill -SIGUSR1 pid'


### <ins>Send and Recieve signals</ins>
**recv_signal:**

    Registers a custom signal handler for `SIGUSR1` using `sigaction()`. Recieve signals that has additional info from `sigqueue()`. When `SIGUSR1` is recieved it prints the `PID` and integer that was attached to the signal.

**send_signal:**

    Sends a `SIGUSR1` signal to another process using `sigqueue()`. As well as generates a random int from 1-100 attaches it to the signal using `union sigval`, and sends it to a specific `PID`.

Compile together with seperate terminals:
```
./recv_signal
```

```
./send_signal <pid>
```
---
