#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigusr1(int sig) {
    printf("Received SIGUSR1\n");
}

int main() {
    signal(SIGUSR1, handle_sigusr1);

    printf("Process ID: %d\n", getpid());

    if (raise(SIGUSR1) != 0) {
        perror("Failed to raise SIGUSR1");
        return 1;
    }

    printf("Raised SIGUSR1\n");

    return 0;
}
