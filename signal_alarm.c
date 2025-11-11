/* 
* Filename: signal_alarm.c
* Author: Jaden Hipe
* Course Section: 112
* Date: 11/10/2025
* Compile info: make signal_alarm
* Description: Creates an alarm after 5 seconds of the process running.
* Also prints out a recieved signal notification
*/ 

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * @brief Signal handler for SIGALRM - prints a message and exits
 */
void handle_signal() {
    printf("Received a signal\n");
    exit(0);
}

int main() {

    // Register for the signal
    signal(SIGALRM, handle_signal);

    alarm(5);

    //do nothing while waiting for alarm
    while(1)
    {

    }
    return 0;
}
