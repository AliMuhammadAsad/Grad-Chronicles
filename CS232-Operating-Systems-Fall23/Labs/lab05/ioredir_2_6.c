#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<assert.h>
#include<sys/wait.h>

int main(int argc, char* argv[]){
    char line[100], command[100], arg1[100], arg2[100];
    while(1){
        printf("prompt> ");
        if(fgets(line, sizeof(line), stdin) == NULL){
            perror("Failed to read command\n"); exit(1);
        }

        line[strcspn(line, "\n")] = '\0';
        if(strcmp(line, "exit") == 0){
            printf("Exiting the mini-shell\n"); break;
        }
        
        printf("I am Batman (pid:%d)\n", (int)getpid());
        int rc = fork();
        if(rc < 0){
            fprintf(stderr, "BatFork Failed\n"); exit(1);
        }
        else if(rc == 0){
            printf("Hello, I am Robin(child) (pid:%d)\n", (int)getpid());
            if(sscanf(line, "%s %s %s", command, arg1, arg2) >= 1){
                int redirect = 0;
                for(int i = 0; line[i] != '\0'; i++){
                    if(line[i] == '>'){
                        redirect = 1; line[i] = ' ';
                        break;
                    }
                }
                if(redirect == 1){
                    char filename[100];
                    if(sscanf(line, "%s %s", command, filename) != 2){
                        fprintf(stderr, "Invalid redirection format\n");
                        exit(1);
                    }

                    int fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC | S_IRWXU);
                    if(fd == -1){
                        perror("Failed to open file for redirection\n"); exit(1);
                    }
                    dup2(fd, STDOUT_FILENO);
                    close(fd);
                }
                char* arr[3];
                arr[0] = strdup(command);
                arr[1] = strdup(arg1);
                arr[2] = NULL;
                execvp(arr[0], arr);
            }
            else printf("\n");

            exit(0);
        }
        else{
            int wc = wait(NULL);
            printf("Hello, I am Batman, parent of Robin %d (wc:%d) (pid:%d)\n", rc, wc, (int)getpid());
        }
    }
    return 0;
}