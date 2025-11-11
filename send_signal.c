/* 
* Filename: send_signal.c
* Author: Jaden Hipe
* Course Section: 112
* Date: 11/10/2025
* Compile info: make send_signal
* Description: Sends a signal with a random value attached. The user must manually print the given
* pid by recv_signal, and use ./send with the pid after it to send SIGUSR1.
*/ 

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int pid = atoi(argv[1]);
        
        srand(time(NULL));
        int random = rand();
        printf("Value is %d\n", random);

        //sigqueue(pidtarget, signal,value)
        //value must come from union sigval val
        union sigval value;
        value.sival_int = random;

        sigqueue(pid,SIGUSR1,value);
        sleep(1);
        printf("Signal Sent.\n");
    }
    else 
    {
        printf("Couldn't read PID.\n");
    }
    
}
