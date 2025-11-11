/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Jaden Hipe
 * 
 * Brief summary of modifications:
 * - Implemented a signal handler for SIGSEGV
 * - Added exit(0) into the signal handler 
 */


#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
/**
 * @brief Signal handler for SIGSEG - prints a message and exits
 */
void handle_signal() {
    printf("Received a signal\n");
    //This prevents infinite loop of receiving the SIGSEGV and rerunning the dereference statment.
    exit(0);
}

int main (int argc, char* argv[]) {
    //Register for signal
    signal(SIGSEGV,handle_signal);
    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}