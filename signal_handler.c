/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */

/**
 * Modified by: Jaden Hipe
 * 
 * Brief summary of modifications:
 * - Used a fork, where parent waits for child to stop looping to exit the program.
 * - Added a global signal variable, since it seemed to be the easiest approach,
 * though may not be most preferable. It updates upon receiving SIGINT.
 * - To exit the program, kill(pid, SIGKILL) was used to kill the current process.
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include <stdbool.h>

//Global signal boolean for signal method and main method to see
bool sig = false;
/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */
void handle_signal() {
    printf("Received a signal\n");
    sig = true;
    
}

int main() {

    // Register for the signal
    signal(SIGINT, handle_signal);

    pid_t pid = fork();

    if (pid == 0)
    {
        // Wait until a signal is received in child Process
        while(!sig) {
            printf("Sleeping\n");
            sleep(1);
        }
    }
    else
    {
        wait(NULL);
        printf("returned\n");
        kill(pid, SIGKILL);
    }

    return 0;
}