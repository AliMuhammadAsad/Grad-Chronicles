#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<time.h>

#define NUM_THREADS 4
#define INCS 1000000000

long long int gc = 0;

void* incremenet(void* arg){
    for(int i = 0; i < INCS; i++) gc++;
    return NULL;
}

int main(int argc, char* argv[]){
    printf("#----------------Task 6.1.2----------------#\n");
    printf("This'll take about 20 seconds. Please be patient.\n\n");
    pthread_t threads[NUM_THREADS];
    clock_t start = clock();
    for(int i = 0; i < NUM_THREADS; i++) pthread_create(&threads[i], NULL, incremenet, NULL);

    for(int i = 0; i < NUM_THREADS; i++) pthread_join(threads[i], NULL);

    clock_t end = clock();
    double time_taken = (double) (end - start) / (CLOCKS_PER_SEC * NUM_THREADS);
    printf("Program took %f seconds to execute\n", time_taken);

    printf("Global Counter = %lld\n", gc);
    printf("It is interesting to note that the final value of the global counter is not as one might expect.\nThere are 4 threads, and each thread increments the global counter a million times, so one would expect the final value to be 4 million.\nBut we see the value is less than that. This is because the operation of incrementing a variable is not atomic.\nIt involves first reading the current value, adding to it, then writing it back.\nIf two or three or four threads (our case) perform this operation at the same time, some or all might read the same value, increment it, and write it back, effectively incrementing the counter less than 4.\n\n");
    exit(EXIT_SUCCESS);
}

/*
gcc -lpthread -o t_6.1.2 t_6.1.2.c
./t_6.1.2
rm -f t_6.1.2
*/
