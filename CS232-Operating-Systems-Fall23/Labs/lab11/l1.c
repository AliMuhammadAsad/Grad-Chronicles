/* race.c */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

// #define INC_SIZE 10000000
#define INC_SIZE 1000

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
    pthread_t t1, t2; 
    // create a new thread that runs hellp_arg with argument hello
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
gcc -lpthread -o l1 l1.c
./l1
rm -rf l1
*/