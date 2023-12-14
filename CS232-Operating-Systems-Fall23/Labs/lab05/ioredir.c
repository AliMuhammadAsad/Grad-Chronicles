#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<assert.h>
#include<fcntl.h>
#include<sys/types.h>

int main(int argc, char* argv[]){
    int rc = fork();
    if(rc < 0){
        fprintf(stderr, "Fork Failed\n"); exit(1);
    }
    else if(rc == 0){
        close(STDOUT_FILENO);
        open("./fork.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);

        char* arr[3];
        arr[0] = strdup("wc");
        arr[1] = strdup("fork.c");
        arr[2] = NULL;
        execvp(arr[0], arr);
    }
    else{
        int wc = wait(NULL);
        assert(wc >= 0);
    }
    return 0;
}