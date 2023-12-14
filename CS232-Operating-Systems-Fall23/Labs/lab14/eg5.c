#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // This is the child process
        printf("Child process ID: %d\n", getpid());
        printf("Parent process ID: %d\n", getppid());

        if (raise(SIGTERM) == -1) {
            perror("Failed to kill self");
            return 1;
        }

        printf("Sent SIGTERM to self\n");
    } else if (pid > 0) {
        // This is the parent process
        printf("Parent process ID: %d\n", getpid());

        // Wait for the child process to terminate
        printf("Waiting for child process to terminate...\n");
        // sleep(2);
        wait(NULL);
    } else {
        // Fork failed
        perror("fork failed");
        return 1;
    }

    return 0;
}
