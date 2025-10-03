#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(int argc, char* argv[]){
    // pthread_t t1;
    void* res; int s;

    // srand(time(NULL));
    // int a[1000000000];
    int *a = malloc(1000000000 * sizeof(int));
    if(a == NULL){
        perror("error: memory failure");
        exit(EXIT_FAILURE);
    }
    clock_t start = clock();
    for(int i = 0; i < 1000000000; i++){
        a[i % 1000000000] = 1000000000;
    }
    clock_t end = clock();
    double time_taken = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Program took %f seconds to execute\n", time_taken);
    free(a);
    exit(EXIT_SUCCESS);
}

/*
gcc -lpthread -o l5 l5.c
./l5
rm -f l5
*/