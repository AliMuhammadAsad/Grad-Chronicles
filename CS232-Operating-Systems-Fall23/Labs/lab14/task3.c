#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    sigset_t new_mask, og_mask;
    pid_t pid;

    sigfillset(&new_mask);
    if(sigprocmask(SIG_SETMASK, &new_mask, &og_mask) < 0){
        perror("AJSDBAKSJDLBASKJD\n"); return EXIT_FAILURE;
    }
    
    pid = fork();
    printf("DW chal raha hai ye\n"); sleep(2);
    if(pid < 0){
        perror("Kya ajeeb lab hai\n"); return EXIT_FAILURE;
    } else if(pid == 0){
        printf("Mubarak ho, bacha hua hai\n");
        sleep(2);
        sigprocmask(SIG_SETMASK, &og_mask, NULL);
        printf("You have the following files:\n");
        execlp("ls", "ls", (char*)NULL);
        perror("AAAAAAAAAAAAAAAAAAAAAAAAA\n");
        return EXIT_FAILURE;
    } else {
        wait(NULL);
        sigprocmask(SIG_SETMASK, &og_mask, NULL);
        printf("Weeeeeeeeeeeeeeeee\n");
    }
    return EXIT_SUCCESS;
}