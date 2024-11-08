// #include<sys/ipc.h>
// #include<sys/shm.h>
// #include<stdio.h>

// int main(){
//     key_t key = ftok("shmfileA", 65); // generate a unique key
//     long long int shmid = shmget(key, 1024, 0666|IPC_CREAT); // create a shared memory segment
//     long long int* num = (long long int*) shmat(shmid, (void*)0, 0); // attach the shared memory segment to the address space of the calling process

//     *num = 0; // initial value
//     printf("Program A writes value %lld\n", *num);
//     shmdt(num); // detach the shared memory segment from the address space of the calling process
//     return 0;
// }

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 27
void die(char* str){
    perror(str); exit(1);
}

int main(void){
    int shmid; key_t key = 2211;
    int *shm, *s;

    if((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0) die("shmget");

    if((shm = shmat(shmid, NULL, 0)) == (int*)-1) die("shmat");

    s = shm; *s = 0;
    while(*shm != '*') sleep(1);
    exit(0);
}