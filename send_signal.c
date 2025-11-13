/*******************************************************************
* Filename: send_signal.c
* Description: Sends a signal using SIGUSR1 and gives and additonal 
* int value to another process using sigqueue().
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
    // Makes sure using correct arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <PID>\n", argv[0]);
        return 1;
    }
    // Converts command string to integer PID
    pid_t pid = atoi(argv[1]);
    union sigval value; 

    srand(time(NULL));
    // Generates random value from 1-100 to send with signal
    value.sival_int = rand() % 100 + 1;

    printf("Sending SIGUSR1 to process %d with value: %d\n", pid, value.sival_int);
    // Sends SIGUSR1 to the process along with int val
    if (sigqueue(pid, SIGUSR1, value) == -1) {
        perror("sigqueue");
        return 1;
    }
    printf("Signal sent successfully!\n");
    return 0;
}