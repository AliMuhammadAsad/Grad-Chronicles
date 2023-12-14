#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void catchsigt(int signo) {
    char *handmsg = "I got Ctrl-C\n";
    size_t msglen = sizeof(handmsg);

    write(STDERR_FILENO, handmsg, msglen);
}

int main(void) {
    printf("PID is %d\n", getpid());
    struct sigaction act;
    act.sa_handler = catchsigt;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

    if (sigaction(SIGINT, &act, NULL) == -1) {
        perror("Failed to set up SIGINT handler");
        return 1;
    }

    printf("SIGINT handler set up\n");

    /* Loop forever, waiting for signals */
    for ( ; ; ) ;

    return 0;
}
