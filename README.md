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
```
gcc -o exe filename.c
```
---

## How to Run

### Run the executable in terminal:
**Signal Handler**
```
./signal_handler
```
Two (2) ways to send the SIGINT signal to the process:

1.) Pressing 'Ctrl+C'

2.) In another terminal, type 'kill -2 pid' or 'kill -SIGINT pid'

**Send and Recieve signals**
Compile together with seperate terminals:
```
./recv_signal
```
```
./send_signal <pid>
```
---
