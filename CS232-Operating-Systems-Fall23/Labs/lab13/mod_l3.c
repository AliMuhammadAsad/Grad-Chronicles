#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

static char sig_handler(int sig){
    printf("Ouch!\n"); return 'a';
}

int main(int argc, char* argv[]){
    int j;
    if(signal(SIGINT, sig_handler) == SIG_ERR){
        fprintf(stderr, "signal handler not registered\n");
        exit(1);
    }
    for(j = 0; ;j++){
        printf("%d\n", j);
        sleep(3);
    }
}


/* Sets a custom signal handler for SIGINT, which executes the sig_handler instead of terminating.
It cancels the same way as listing 2 */