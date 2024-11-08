#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main(int argc, char* argv[]){
    printf("I am Batman (pid:%d)\n", (int)getpid());
    int rc = fork();
    if(rc < 0){
        fprintf(stderr, "BatFork failed\n"); exit(1);
    }
    else if(rc == 0){
        printf("Hello, I am Robin(child) (pid:%d)\n", (int)getpid());
        char *myargs[3];
        myargs[0] = strdup("wc"); // program: "wc" (word count)
        myargs[1] = strdup("exec.c"); // argument: file to count
        myargs[2] = NULL; // marks end of array
        execvp(myargs[0], myargs); // runs word count
        printf("This shouldn't print out");
    }
    else{
        int wc = wait(NULL);
        printf("Hello, I am Batman(parent) of Robin %d (wc:%d) (pid:%d)\n", rc, wc, (int)getpid());
    }

    return 0;
}