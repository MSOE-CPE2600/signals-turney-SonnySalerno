/*******************************************************************
* Filename: signal_alarm.c
* Description: Schedules a SIGALRM signal to be delivered to the 
* process after 5 seconds.
* Author: Sonny Salerno
* Date: 11/10/2025
* Note: make clean, make, ./signal_alarm 
*********************************************************************/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Handles SIGALRM signal
void handle_alarm(int sig) {    // This is executed when SIGALRM is recieved
    printf("\nAlarm received!\n");
}
int main() {
    // Register for handler SIGALRM
    signal(SIGALRM, handle_alarm);

    // Schedules an alarm for 5 seconds
    printf("Alarm set for 5 seconds...\n");
    alarm(5);

    // Keeps the process running
    while (1) {
        printf("Running...\n");
        sleep(1);   // Slows it for a second
    }
    return 0;
}