/* 
* Filename: recv_signal.c
* Author: Jaden Hipe
* Course Section: 112
* Date: 11/10/2025
* Compile info: make recv_signal
* Description: This recieves a value generated from send_signal, by signals.
* It uses sigaction as its handler and first outputs its pid for use by send_signal.
* Use SIGINT to terminate the process.
*/ 

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * @brief Signal handler for SIGUSR1 - prints a message and exits
 * from man page sigaction(2)
 */
void signal_handler(int sig, siginfo_t *info, void *ucontext)
{
    printf("Printing sival_int: %d\n", info->si_value.sival_int);
    
}

int main() {

    // Register for the signal
    struct sigaction sigact;
    sigact.sa_sigaction = signal_handler;
    sigact.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sigact, NULL);
    printf("This PID is: %d\n", getpid());


    //do nothing 
    while(1)
    {

    }
    return 0;
}

