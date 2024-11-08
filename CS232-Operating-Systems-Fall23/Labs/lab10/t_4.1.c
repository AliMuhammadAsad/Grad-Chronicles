#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

void* func_str(void* args){
    char* str = (char*) args;
    printf("Thread %lu of process %d says: %s\n", pthread_self(), getpid(), str);
    return NULL;
}

void* func_int(void* args){
    int* x = (int*) args;
    printf("Thread %lu of process %d has number: %d\n", pthread_self(), getpid(), *x);
    return NULL;
}

int main(int argc, char* argv[]){
    printf("#----------------Task 4.1----------------#\n");
    char c1[] = "I am Batman!";
    char c2[] = "Main hun Nightwing!";
    char c3[] = "Ironman and Batman are unparalleled";
    int x = 420;

    pthread_t t0, t1, t2, t3; // thread identifiers

    pthread_create(&t0, NULL, func_str, (void*) c1);
    pthread_create(&t1, NULL, func_str, (void*) c2);
    pthread_create(&t2, NULL, func_str, (void*) c3);
    pthread_create(&t3, NULL, func_int, (void*) &x);

    pthread_join(t0, NULL); pthread_join(t1, NULL); pthread_join(t2, NULL); pthread_join(t3, NULL);

    printf("\n"); 
    return 0;
}

/*
gcc -lpthread -o t_4.1 t_4.1.c
./t_4.1
rm -f t_4.1
*/