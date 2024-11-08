#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<time.h>

#define SIZE 1000000000
#define NUM_THREADS 5

void* fill_array(void* args){
    int* a = (int*) args;
    for(int i = 0; i < SIZE/NUM_THREADS; i++) a[i] = SIZE;
    return NULL;
}

int main(int argc, char* argv[]){
    printf("#----------------Task 6.1.1----------------#\n");
    printf("The array is divided into a number of threads segments and a thread is created for each segment.\nThis allows the array to be filled in parallel, thus reducing time taken from average 8 seconds in Listing 5 to an average of 2 seconds.\n\n");
    pthread_t threads[NUM_THREADS];
    int* a = malloc(SIZE * sizeof(int));
    if(a == NULL){
        perror("error: memory failure"); exit(EXIT_FAILURE);
    }

    clock_t start = clock();

    for(int i = 0; i < NUM_THREADS; i++) pthread_create(&threads[i], NULL, fill_array, &a[i * SIZE/NUM_THREADS]);

    for(int i = 0; i < NUM_THREADS; i++) pthread_join(threads[i], NULL);

    clock_t end = clock();
    double time_taken = (double) (end - start) / (CLOCKS_PER_SEC * NUM_THREADS);
    printf("Program took %f seconds to execute\n", time_taken);

    free(a); exit(EXIT_SUCCESS);
}

/*
gcc -lpthread -o t_6.1.1 t_6.1.1.c
./t_6.1.1
rm -f t_6.1.1
*/