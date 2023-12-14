#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(void) {
    struct sigaction act;
    printf("PID: %d\n", getpid());
    if (sigaction(SIGINT, NULL, &act) == -1) { /* Find current SIGINT handler */
        perror("Failed to get old handler for SIGINT");
        return 1;
    } else if (act.sa_handler == SIG_DFL) { /* If SIGINT handler is default */
        act.sa_handler = SIG_IGN; /* Set new SIGINT handler to ignore */

        if (sigaction(SIGINT, &act, NULL) == -1) {
            perror("Failed to set new handler for SIGINT");
            return 1;
        }
    }

    printf("SIGINT handler set to ignore\n");

    /* Loop forever, waiting for signals */
    for ( ; ; ) ;

    return 0;
}
