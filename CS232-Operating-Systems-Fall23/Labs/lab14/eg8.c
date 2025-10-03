#include <stdio.h>
#include <signal.h>

int main(void) {
    sigset_t sigset;

    if ((sigemptyset(&sigset) == -1) ||
        (sigaddset(&sigset, SIGINT) == -1) ||
        (sigaddset(&sigset, SIGQUIT) == -1)) {
        perror("Failed to set up signal mask");
        return 1;
    }

    printf("Signal set initialized\n");

    return 0;
}
