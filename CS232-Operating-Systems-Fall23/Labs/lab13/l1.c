#include<stdio.h>
#include<unistd.h>

int main(int argc, char* argv[]){
    int j;
    for(j = 0; ;j++){
        printf("%d\n", j);
        sleep(3);
    }
}

/* Pressing Ctrl+C sends a 'SIGINT' signal which, by default terminates the process */

/*
gcc -o l1 l1.c
./l1
rm -f l1
*/