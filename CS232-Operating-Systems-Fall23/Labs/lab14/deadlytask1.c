#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
    if(argc < 3) {
        fprintf(stderr, "Usage: %s <signal> <pid1> [pid2] [...] | all\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sig = atoi(argv[1]), res;
    
    if(strcmp(argv[2], "all") == 0) {
        if(getuid() != 0) {
            fprintf(stderr, "Killing all processes requires root privileges.\n");
            return EXIT_FAILURE;
        }
        res = kill(-1, sig);
        if(res == 0) {
            printf("Signal %d sent to all processes.\n", sig);
        } else {
            fprintf(stderr, "Failed to send signal %d to all processes: %s\n", sig, strerror(errno));
            return EXIT_FAILURE;
        }
    } else {
        for(int i = 2; i < argc; i++) {
            pid_t pid = (pid_t)atoi(argv[i]);
            res = kill(pid, sig);
            if(res == 0) {
                printf("Signal %d sent to process %d\n", sig, pid);
            } else {
                fprintf(stderr, "Failed to send signal %d to process %d: %s\n", sig, pid, strerror(errno));
            }
        }
    }
    return EXIT_SUCCESS;
}

