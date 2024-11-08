/* race.c */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<time.h>

#define INC_SIZE 10000000
// #define INC_SIZE 1000

static volatile int glob = 0; // shared global variable

void* access_global(void* arg) { // thread start routine
    char* p = (char*)arg; // thread name
    int loc = 0; // local variable
    printf("%s: thread started\n", p); 
    for(int i = 0 ; i < INC_SIZE ; i++) { // increment global variable
        loc = glob; loc++; glob = loc;
    }
    printf("%s: thread ending\n", p);
    return NULL;
}

int main(int argc, char* argv[]){
    printf("#--------------------------- 4: Performance Measuring---------------------------#\n\n#--------------Listing 1 Timed--------------#\n");
    pthread_t t1, t2; 
    // create a new thread that runs hellp_arg with argument hello
    clock_t start = clock();
    printf("main: creating threads\n");
    pthread_create(&t1, NULL, access_global, "Thread 0");
    pthread_create(&t2, NULL, access_global, "Thread 1");
    printf("main: threads created\n");

    // wait until the threads complete
    pthread_join(t1, NULL); pthread_join(t2, NULL);
    clock_t end = clock();
    printf("main: threads joined\n");
    printf("main: glob = %d\n", glob);
    printf("Listing 1; main: time = %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}

/*
gcc -lpthread -o l1_timed l1_timed.c
./l1_timed
rm -rf l1_timed
*/