#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<math.h>

int main(){
    key_t key1 = ftok("t2_p1.c", 65);
    int shmid1 = shmget(key1, 1024, 0666|IPC_CREAT);
    double* num1 = (double*) shmat(shmid1, (void*)0, 0);

    key_t key2 = ftok("t2_p2.c", 65);
    int shmid2 = shmget(key2, 1024, 0666|IPC_CREAT);
    double* num2 = (double*) shmat(shmid2, (void*)0, 0);

    while(1){
        double quotient = (int)(*num2 / *num1) * (int)(*num1);
        double rem = *num2 - quotient;
        printf("Program 3 reads values %.2f and %.2f and writes remainder %.2lf\n", *num1, *num2, rem);
        sleep(10);
    }
    shmdt(num1); shmdt(num2);
    return 0;
}