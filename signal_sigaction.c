/* 
* Filename: signal_sigaction.c
* Author: Jaden Hipe
* Course Section: 112
* Date: 11/10/2025
* Compile info: make signal_sigaction
* Description: Uses sig action to recieve the SIGUSR1 signal from another terminal.
* Upon successfully sending the signal to the program, it will respond with the sender's pid.
* To stop running, send SIGINT using CTRL + C.
* Sample output:
* Main Terminal -
* This PID is: 4812
* Waiting for signal
* Recieved signal from PID: 4709
*
* Secondary Terminal:
* Inputting: kill -SIGUSR1 4812
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
    printf("Recieved signal from PID: %d\n", info->si_pid);
    
}

int main() {

    // Register for the signal
    

    struct sigaction sigact;
    sigact.sa_sigaction = signal_handler;
    sigact.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sigact, NULL);
    printf("This PID is: %d\n", getpid());
    printf("Waiting for signal\n");


    //do nothing 
    while(1)
    {

    }
    return 0;
}



