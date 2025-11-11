/*******************************************************************
* Filename: signal_alarm.c
* Description: schedules a SIGALRM signal to be delivered to the 
* process after 5 seconds.
* Author: Sonny Salerno
* Date: 11/10/2025
* Note: make clean, make, ./signal_alarm 
*********************************************************************/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_alarm(int sig) {
    printf("\nAlarm received!\n");
}
int main() {
    signal(SIGALRM, handle_alarm);

    printf("Alarm set for 5 seconds...\n");
    alarm(5);

    while (1) {
        printf("Running...\n");
        sleep(1);
    }
    return 0;
}