#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

void* hello_fun(){
    printf("Waiting for dhaagay\n");
    return NULL;
}

int main(int argc, char* argv[]){
    printf("#----------------Task 5.1: Correcting the Code----------------#\n");
    pthread_t dhaaga;
    pthread_create(&dhaaga, NULL, hello_fun, NULL);
    pthread_join(dhaaga, NULL);
    printf("\n");
    return 0;
}

/*
gcc -lpthread -o t_5.1.1 t_5.1.1.c
./t_5.1.1
rm -f t_5.1.1
*/