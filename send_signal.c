/*******************************************************************
* Filename: send_signal.c
* Description: 
* Author: Sonny Salerno
* Section: CPE2600 111
* Date: 11/10/2025
* Note: make clean, make, ./send_signal <PID>
*********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <PID>\n", argv[0]);
        return 1;
    }

    pid_t pid = atoi(argv[1]);
    union sigval value;

    srand(time(NULL));
    value.sival_int = rand() % 100 + 1;

    printf("Sending SIGUSR1 to process %d with value: %d\n", pid, value.sival_int);

    if (sigqueue(pid, SIGUSR1, value) == -1) {
        perror("sigqueue");
        return 1;
    }

    printf("Signal sent successfully!\n");
    return 0;
}