/* hello_argc_pthred.c */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

void* hello_arg(void* args){
    char* str = (char*) args;
    printf("%s\n", str);
    return NULL;
}

void* hello_arg_int(void* args){
    int* str = (int*) args;
    printf("%d\n", *str);
    return NULL;
}

int main(int argc, char* argv[]){
    printf("#----------------Program 2: hello_argc_pthread.c----------------#\n");
    char hello[] = "Hello World!";
    int x = 33;
    pthread_t t1, t2; // thread identifiers

    // create a new thread have it run the function hello_arg with arg hello
    pthread_create(&t1, NULL, hello_arg, (void*) hello);
    pthread_create(&t2, NULL, hello_arg_int, (void*) &x);

    // wait until the thread completes
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}

/*
gcc -lpthread -o l2 l2.c
./l2
rm -f l2
*/