/* race.c */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<time.h>

#define INC_SIZE 10000000

static volatile int glob = 0; // shared global variable
static pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void* access_global(void* args){
    char* p = (char*)args; // thread name
    int loc = 0; // local variable
    printf("%s: thread started\n", p); 
    for(int i = 0 ; i < INC_SIZE ; i++) { // increment global variable
        pthread_mutex_lock(&m); // lock the mutex to protect the critical section
        loc = glob; loc++; glob = loc;
        pthread_mutex_unlock(&m); // unlock the mutex
    }
    printf("%s: thread ending\n", p);
    return NULL;
}

int main(int argc, char* argv[]){
    printf("\n#--------------Listing 2 Timed--------------#\n");
    pthread_t t1, t2;

    printf("main: creating threads\n");
    clock_t start = clock();
    pthread_create(&t1, NULL, access_global, "Thread 0");
    pthread_create(&t2, NULL, access_global, "Thread 1");
    printf("main: threads created\n");

    // wait until the threads complete
    pthread_join(t1, NULL); pthread_join(t2, NULL);
    clock_t end = clock();
    printf("main: threads joined\n");
    printf("main: glob = %d\n", glob);
    printf("Listing 2; main: time = %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("\nThe difference between the timings in Listing 1 and Listing 2 is due to the overhead of locking and unlocking the mutex. Due to locking and unlocking, one thread is locked until the previous thread gives up the lock - unlocks. This means that one thread has to wait for the other to give up the process which takes time. Unlike Listing 1 in which both threads were sharing the memory simultaneously, wich also resulted in the wrong output.\n\n");
    return 0;
}

/*
gcc -lpthread -o l2_timed l2_timed.c
./l2_timed
rm -rf l2_timed
*/