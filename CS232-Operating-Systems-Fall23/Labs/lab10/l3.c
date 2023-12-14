/* hello_pthread_bad.c */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

void* hello_fun(){
    printf("Waiting for dhaagay\n");
    return NULL;
}

int main(int argc, char* argv[]){
    pthread_t thread;
    pthread_create(&thread, NULL, hello_fun, NULL);

    // sleep(1);

    return 0;
}

/*
gcc -lpthread -o l3 l3.c
./l3
rm -f l3
*/