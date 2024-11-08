#include<stdio.h>
#include<unistd.h>

int main(void){
    int pipefd[2]; // pipe file descriptor array
    int pid; // process id
    char buffer[15]; // buffer to store the data
    pipe(pipefd); // creating the pipe -> pipe returns two dile descriptors, pipefd[0] for reading, pipefd[1] for writing
    pid = fork(); // creating the child process

    if(pid > 0){ // if parent process, print the prompt we are in parent process, and write the data to the pipe
        fflush(stdin);
        printf("unnamed_pipe [INFO] Parent process\n");
        write(pipefd[1], "I am Batman", 12);
    }
    else if(pid == 0){ // if child process, sleep for a second, print the prompt we are in child process, and read the data from the pipe
        sleep(5);
        fflush(stdin);
        printf("unnamed_pipe [INFO] Child process\n");
        read(pipefd[0], buffer, sizeof(buffer));
        write(1, buffer, sizeof(buffer));
        printf("\n");
    }
    else{
        printf("unnamep_pipe [ERROR] Error in creating the child process\n");
    }
    if(pid > 0) wait(); // wait for the child process to finish
    return 0;
}