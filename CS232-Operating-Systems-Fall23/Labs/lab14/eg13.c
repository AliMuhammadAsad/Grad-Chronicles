#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int testignored(int signo) {
    struct sigaction act;
    if ((sigaction(signo, NULL, &act) == -1) ||
        (act.sa_handler == SIG_IGN))
        return 1;
    return 0;
}

int main(void) {
    int signo = SIGINT; /* Change this to the signal number you want to check */
    printf("PID is %d\n", getpid());
    if (testignored(signo)) {
        printf("Signal %d is ignored\n", signo);
    } else {
        printf("Signal %d is not ignored\n", signo);
    }

    return 0;
}
