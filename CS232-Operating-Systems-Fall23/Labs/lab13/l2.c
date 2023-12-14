#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main(int argc, char* argv[]){
    int j;
    if(signal(SIGINT, SIG_IGN) == SIG_ERR){
        fprintf(stderr, "Error ignoring signal\n");
        exit(1);
    }
    for(j = 0; ;j++){
        printf("%d\n", j);
        sleep(3);
    }
}

/* Here the SIGINT signal is ignored by the program, signal(SIGINT, SIG_IGN) does this. Since Ctrl+C is ignored, we can use another terminal to send a different commmand to kill the program; 'SIGTERM' or 'SIGKILL'. A command like 'kill -SIGTERM <pid>' or 'kill -9 <pid>'. U can check the pid by writing 'top' in the terminal and observing the process id of the process  */

/*
gcc -o l2 l2.c
./l2
rm -f l2
*/