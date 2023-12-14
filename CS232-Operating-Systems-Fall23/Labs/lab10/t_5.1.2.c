#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>

void* hello_fun(void* args){
    printf("Thread %lu thak gaya hai bohot zyada (pthread_exit() called)\n", pthread_self());
    pthread_exit(NULL);
}

void* goodbye(void* args){
    printf("Thread %lu dunya se farigh ho chuka hai, dunya jhooti log luteray (exit call hua - dunya se exit)\n\n", pthread_self());
    exit(0);
}

void* hehehe(void* args){
    printf("Ye print nhi hona chahye, agar print hua then code mein koi masla hai\n");
    // return NULL;
    pthread_exit(NULL);
}

int main(int argc, char* argv[]){
    printf("#----------------Task 5.1.2----------------#\n");
    printf("Note: pthread_exit() terminates only the calling thread, whereas exit() terminates the entire process including the main process\n\n");
    pthread_t t0, t1, t2;

    pthread_create(&t0, NULL, hello_fun, NULL); pthread_join(t0, NULL);

    pthread_create(&t1, NULL, goodbye, NULL); pthread_join(t1, NULL);

    pthread_create(&t2, NULL, hehehe, NULL); pthread_join(t2, NULL);

    return 0;
}

/*
gcc -lpthread -o t_5.1.2 t_5.1.2.c
./t_5.1.2
rm -f t_5.1.2
*/