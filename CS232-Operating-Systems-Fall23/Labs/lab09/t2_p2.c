#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    key_t key = ftok("t2_p2.c", 65);
    int shmid = shmget(key, 1024, 0666|IPC_CREAT);
    double* num = (double*) shmat(shmid, (void*)0, 0);

    srand(time(0)); // seed for random number generation

    while(1){
        *num = 999.00 + (rand() / (double)RAND_MAX) * (1000.00 - 999.00); // generate a random number between 999.00 and 1000.00
        printf("Program 2 writes value %.2f\n", *num);
        sleep(2); // sleep for 2 seconds
    }
    shmdt(num);
    return 0;
}