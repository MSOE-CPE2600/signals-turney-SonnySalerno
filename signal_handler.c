/*******************************************************************
* Filename: signal_handler.c
* Description: Handles POSIX signals
* Author: Sonny Salerno
* Date: 11/10/2025
* Note: make clean, make, ./signal_handler, 'Ctrl+C' in main terminal  
* or in another terminal type 'kill -SIGINT <PID>' or 'kill -2 <PID>'
*********************************************************************/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Handles SIGINT signal
void handle_signal(int sig) {   // This is executed when SIGINT is recv
    printf("\nCaught signal %d (SIGINT)\n", sig);
}

int main() {
    // Register for handler SIGINT
    signal(SIGINT, handle_signal);

    // Prints process ID, user can send using kill
    printf("Process ID: %d\n", getpid());
    printf("Press Ctrl+C to send SIGINT...\n");

    // Keeps the process running
    while (1) {
        printf("Running...\n");
        sleep(1);   // Slows it for a second
    }

    return 0;
}