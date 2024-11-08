/* hello_pthread.c */
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#include<pthread.h>

void* hello_fun(void* args){
    printf("Strings, dhaagay, threads\n");
    return NULL;
}

int main(int argc, char* argv[]){
    printf("#----------------Program 1: hello_pthread.c----------------#\n");
    pthread_t t0, t1; // thread identifiers

    // create a new thread have  it run the function hello_fun
    pthread_create(&t0, NULL, hello_fun, NULL);
    pthread_create(&t1, NULL, hello_fun, NULL);

    // wait until the thread completes
    pthread_join(t0, NULL);
    pthread_join(t1, NULL);

    return 0;
}

/*
Copy Paste the below (include rm command if you want to remove the file immediately as well) in your terminal to run your program

gcc -lpthread -o l1 l1.c
./l1
rm -f l1
*/