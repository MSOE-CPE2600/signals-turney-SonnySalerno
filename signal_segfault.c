/*******************************************************************
* Filename: signal_segfault.c
* Description: Shows how a seg fault is generated and handled
* Author: Sonny Salerno
* Date: 11/10/2025
* Note: make clean, make, ./signal_segfault
*********************************************************************/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// Handles segmentation fault when null is dereferenced
void handle_segfault(int sig){
    printf("Caught signal %d (SIGSEGV): Segmentation fault detected.\n", sig);
    printf("Exiting safely...\n");
    exit(1);    // Exits gracefully after handling
}

int main (int argc, char* argv[]) {
    // Declare a nusll pointer
    signal(SIGSEGV, handle_segfault);

    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}