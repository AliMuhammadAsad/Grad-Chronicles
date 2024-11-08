#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>

void sig_handler(int signo){
    if (signo == SIGUSR1) {
        printf("Received SIGUSR1\n");
        exit(0);  // Exit after receiving SIGUSR1
    }
}

int main(void){
    pid_t p = fork();
    
    if(p < 0){
        printf("fork failed\n"); exit(1);
    }
    
    if(p == 0){ // Child process
        signal(SIGINT, SIG_IGN); // Ignore SIGINT
        if (signal(SIGUSR1, sig_handler) == SIG_ERR) {
            printf("\ncan't catch SIGUSR1\n"); exit(1);
        }
        while(1){
            printf("Child process is running...\n"); sleep(1);
        }
    } else { // Parent Process
        sleep(10);
        printf("Parent process sends signal to child.\n");
        kill(p, SIGUSR1);
        wait(NULL); // Wait for child to exit
    }
    return 0;
}
