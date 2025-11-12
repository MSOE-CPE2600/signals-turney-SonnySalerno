/*******************************************************************
* Filename: signal_sigaction.c
* Description: 
* Author: Sonny Salerno
* Date: 11/10/2025
* Note: make clean, make, ./signal_sigaction
*********************************************************************/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void handle_sigaction(int sig, siginfo_t *info, void *context) {
    (void)context; 
    printf("Received SIGUSR1 (signal %d)\n", sig);
    printf("Signal sent by process with PID: %d\n", info->si_pid);
}

int main() {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));

    sa.sa_sigaction = handle_sigaction;
    sa.sa_flags = SA_SIGINFO;

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("Process running with PID: %d\n", getpid());
    printf("Waiting for SIGUSR1 signal...\n");
    printf("Send one using: kill -SIGUSR1 %d\n", getpid());

    while (1) {
        pause();
    }
    return 0;
}