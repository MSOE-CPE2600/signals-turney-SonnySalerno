/*******************************************************************
* Filename: signal_handler.c
* Description: handle POSIX signals
* Author: Sonny Salerno
* Date: 11/10/2025
* Note: make clean, make, ./signal_handler, 'Ctrl+C' in main terminal  
* or in another terminal type 'kill -SIGINT <PID>' or 'kill -2 <PID>'
*********************************************************************/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int sig) {
    printf("\nCaught signal %d (SIGINT)\n", sig);
}

int main() {
    signal(SIGINT, handle_signal);

    printf("Process ID: %d\n", getpid());
    printf("Press Ctrl+C to send SIGINT...\n");

    while (1) {
        printf("Running...\n");
        sleep(1);
    }

    return 0;
}