/*******************************************************************
* Filename: signal_sigaction.c
* Description: Uses sigaction() to handle signals info from sender
* Author: Sonny Salerno
* Date: 11/10/2025
* Note: make clean, make, ./signal_sigaction
*********************************************************************/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

// Signal handler for SIGUSR1
void handle_sigaction(int sig, siginfo_t *info, void *context) {
    (void)context;  // Supresses unused warnings
    printf("\nReceived SIGUSR1 (signal %d)\n", sig);
    printf("Signal sent by process with PID: %d\n", info->si_pid);
}

int main() {
    struct sigaction sa;
    // Initalize the sigaction struct
    memset(&sa, 0, sizeof(sa));

    // Assigns handler functions enables SA_SIGINFO 
    sa.sa_sigaction = handle_sigaction;
    sa.sa_flags = SA_SIGINFO;   // Gives detailed signal info

    // Registers SIGUSR1
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }
    // Displays PID for user to use
    printf("Process running with PID: %d\n", getpid());
    printf("Waiting for SIGUSR1 signal...\n");
    printf("Send one using: kill -SIGUSR1 %d\n", getpid());

    while (1) {
        pause();    // Pauses it until signal recieved
    }
    return 0;
}