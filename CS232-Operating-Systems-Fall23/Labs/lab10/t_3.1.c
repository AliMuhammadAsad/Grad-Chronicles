#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

void* hello_fun(void* args){
    printf("Hello from thread %lu, process %d\n", pthread_self(), getpid());
    return NULL;
}

void* goodbye(void* args){
    printf("Goodbye from thread %lu, process %d\n", pthread_self(), getpid());
    return NULL;
}

int main(int argc, char* argv[]){
    printf("#----------------Task 3.1----------------#\n");
    pthread_t t0, t1;
    pthread_create(&t0, NULL, hello_fun, NULL);
    pthread_create(&t1, NULL, goodbye, NULL);
    pthread_join(t0, NULL); pthread_join(t1, NULL);
    printf("\n");
    return 0;
}

/*
gcc -lpthread -o t_3.1 t_3.1.c
./t_3.1
rm -f t_3.1
*/
