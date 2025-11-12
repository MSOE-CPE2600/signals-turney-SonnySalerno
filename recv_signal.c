/*******************************************************************
* Filename: recv_signal.c
* Description: Recieve signals that has additional info from sigqueue().
* Author: Sonny Salerno
* Section: CPE2600 111
* Date: 11/10/2025
* Note: make clean, make, ./recv_signal
*********************************************************************/
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

void handle_sigusr1(int sig, siginfo_t *info, void *context) {
    (void)context; // Supresses unused warnings
    printf("\nReceived SIGUSR1 (signal %d)\n", sig);
    printf("Signal sent by process with PID: %d\n", info->si_pid);
    // Extracts and prints the int attached to the signal from sender
    printf("Received integer value: %d\n\n", info->si_value.sival_int);
}

int main() {
    struct sigaction sa;
    // Initialize the sigaction struct
    memset(&sa, 0, sizeof(sa));
    
    sa.sa_sigaction = handle_sigusr1;
    sa.sa_flags = SA_SIGINFO;   // Gives detailed signal info

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }
    // Displays PID for user to use
    printf("Process running with PID: %d\n", getpid());
    printf("Waiting for SIGUSR1 signal...\n");
    printf("Send one using: kill -SIGUSR1 %d\n", getpid());

    while (1) {
        pause();    //Pauses it until signal recieved
    }
    return 0;
}