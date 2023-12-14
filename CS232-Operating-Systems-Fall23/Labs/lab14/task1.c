#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>

int main(int argc, char* argv[]){
    if(argc != 3){
        fprintf(stderr, "Usage: %s <pid> <signal>\n", argv[0]); return EXIT_FAILURE;
    }

    pid_t pid = (pid_t)atoi(argv[1]);
    int sig = atoi(argv[2]), res;
    res = kill(pid, sig);

    if(res == 0){
        printf("Signal %d sent to process %d\n", sig, pid);
    } else {
        switch(errno){
            case EINVAL:
                fprintf(stderr, "Invalid signal\n"); break;
            case EPERM:
                fprintf(stderr, "No permission to send signal\n"); break;
            case ESRCH:
                fprintf(stderr, "No such process\n"); break;
            default:
                fprintf(stderr, "Unknown error\n"); break;
        } return EXIT_FAILURE;
    } return EXIT_SUCCESS;
}