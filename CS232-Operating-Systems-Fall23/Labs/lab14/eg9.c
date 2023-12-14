#include <stdio.h>
#include <signal.h>

int main(void) {
    sigset_t sigset;

    if ((sigemptyset(&sigset) == -1) ||
        (sigaddset(&sigset, SIGINT) == -1)) {
        perror("Failed to initialize the signal set");
        return 1;
    } else if (sigprocmask(SIG_BLOCK, &sigset, NULL) == -1) {
        perror("Failed to block SIGINT");
        return 1;
    }

    printf("SIGINT blocked\n");

    return 0;
}
