#include<stdio.h>
#include<unistd.h>

int main(void){
    int pipefd[2], pid; // pipe file descriptor array, process id
    char buffer[15]; // buffer to store the data
    pipe(pipefd); pid = fork(); // creating the pipe and the child process

    if(pid > 0){ // if parent process, print the prompt we are in parent process, read the data from the pipe, and write the data to the stdout
        sleep(5); fflush(stdin);
        printf("task5_1 [INFO] Parent process\n");
        read(pipefd[0], buffer, sizeof(buffer));
        write(1, buffer, sizeof(buffer));
        printf("\n");
    }else if(pid == 0){ // if child process, flush the buffer, print the prompt we are in child process, and write the data to the pipe
        fflush(stdin);
        printf("task5_1 [INFO] Child process\n");
        write(pipefd[1], "I am Robin", 11);
    }
    if(pid == 0) wait(); // wait for the parent process to finish
    return 0;
}