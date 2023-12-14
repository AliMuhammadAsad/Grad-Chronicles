#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    key_t key = ftok("t2_p1.c", 65);
    int shmid = shmget(key, 1024, 0666|IPC_CREAT);
    double* num = (double*) shmat(shmid, (void*)0, 0);

    srand(time(0)); // seed for random number generation

    while(1){
        *num = rand() % 101; // generate a random number between 0 and 100
        printf("Program 1 writes value %f\n", *num);
        sleep(5); // sleep for 5 seconds
    }
    shmdt(num);
    return 0;
}
