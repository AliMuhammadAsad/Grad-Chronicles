#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<unistd.h>

/*
Example 1 and 2 code:
*/
int main(){
    for(;;){
        printf("PID: %d\n", getpid());
        sleep(2);
    }
}