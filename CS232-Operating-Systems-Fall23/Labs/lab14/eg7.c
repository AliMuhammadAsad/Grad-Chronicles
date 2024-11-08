#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handle_sigalrm(int sig) {
    printf("Received SIGALRM, exiting\n");
    _exit(0);
}

int main(void) {
    signal(SIGALRM, handle_sigalrm);
    alarm(2);
    for ( ; ; ) ;
}
