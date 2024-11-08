#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<pthread.h>
#include<string.h>

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER; // mutex
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER; // conditional variable

static int avail = 0; // shared variable

static void* threadFunc(void* arg){ 
/* Thread Function simulates the production of items, each thread will produce 'cnt' items. It locks the mutex, incremenets the 'avail' -> available units to indicate a new item is available, signals the conditional variable to wake up a waiting consumer, and then unlocks the mutex. */
    int cnt = atoi((char*) arg); // consume count
    int s, j; // status, loop variable

    for(j = 0; j < cnt; j++){ 
        sleep(1); 

        s = pthread_mutex_lock(&mtx);
        avail++; 
        s = pthread_cond_signal(&cond); 
        s = pthread_mutex_unlock(&mtx); 
    }
    return NULL;
}

int main(int argc, char* argv[]){
    pthread_t tid; // thread id
    int s, j; // status, loop variable
    int totRequired; // total number of units that all threads will produce

    int numConsumed; // number of units so far consumed
    int done; // variable to indicate when all units have been consumed
    time_t t; // time variable
    t = time(NULL); 
    /* Create all threads */
    totRequired = 0; // initialize total number of units to 0
    for(j = 1; j < argc; j++){ // for each argument
        totRequired += atoi(argv[j]); // add the number of units to the total
        s = pthread_create(&tid, NULL, threadFunc, argv[j]); // create a thread
    }

    numConsumed = 0; done = 0; // initialize number of units consumed and done to 0

    for(;;){ // infinite loop
        s = pthread_mutex_lock(&mtx); // lock mutex
        while(avail == 0){ // while no units are available
            s = pthread_cond_wait(&cond, &mtx); // wait for a signal
        }
        while(avail > 0){ // while units are available
            numConsumed++; // increment number of units consumed
            avail--; // decrement number of units available
            printf("T=%ld: numConsumed=%d\n", (long)(time(NULL) - t), numConsumed); // print the time and number of units consumed
            done = numConsumed >= totRequired; // check if all units have been consumed
        }
        s = pthread_mutex_unlock(&mtx); // unlock mutex
        if(done) break; // if all units have been consumed, break out of the loop
    }
    exit(EXIT_SUCCESS);
}