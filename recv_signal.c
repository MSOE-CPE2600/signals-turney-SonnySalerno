/*******************************************************************
* Filename: recv_signal.c
* Description: 
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
    (void)context; 
    printf("\nReceived SIGUSR1 (signal %d)\n", sig);
    printf("Signal sent by process with PID: %d\n", info->si_pid);
    printf("Received integer value: %d\n\n", info->si_value.sival_int);
}

int main() {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    
    sa.sa_sigaction = handle_sigusr1;
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