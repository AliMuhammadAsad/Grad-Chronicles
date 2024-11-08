#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void my_sighand(int sig) {
    printf("Received SIGINT\n");
}

int main(void) {
    struct sigaction newact;
    printf("PID: %d\n", getpid());
    newact.sa_handler = my_sighand; /* set the new handler */
    newact.sa_flags = 0; /* no special options */

    if (sigemptyset(&newact.sa_mask) == -1 ||
        sigaction(SIGINT, &newact, NULL) == -1) {
        perror("Failed to install SIGINT signal handler");
        return 1;
    }

    printf("SIGINT handler installed\n");

    /* Loop forever, waiting for signals */
    for ( ; ; ) ;

    return 0;
}
