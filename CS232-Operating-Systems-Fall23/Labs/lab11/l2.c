/* race.c */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

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
    pthread_t t1, t2;

    printf("main: creating threads\n");
    pthread_create(&t1, NULL, access_global, "Thread 0");
    pthread_create(&t2, NULL, access_global, "Thread 1");
    printf("main: threads created\n");

    // wait until the threads complete
    pthread_join(t1, NULL); pthread_join(t2, NULL);
    printf("main: threads joined\n");
    printf("main: glob = %d\n", glob);
    return 0;
}

/*
gcc -lpthread -o l2 l2.c
./l2
rm -rf l2
*/