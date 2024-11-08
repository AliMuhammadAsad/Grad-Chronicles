// #include<sys/ipc.h>
// #include<sys/shm.h>
// #include<stdio.h>

// int main(){
//     int n;
//     printf("Enter the number of processes (between 1 and 100): ");
//     scanf("%d", &n);
//     key_t key = ftok("shmfile", 65);
//     long long int shmid = shmget(key, 1024, 0666|IPC_CREAT);
//     long long int* num = (long long int*) shmat(shmid, (void*)0, 0);

//     long long int prev = 0, curr = *num, next;

//     printf("Program C reads value %lld and %lld\n", prev, curr);
//     for(int i = 0; i < n; i++){
//         next = prev + curr; prev = curr; curr = next;
//         *num = next;
//         printf("Program C writes value %lld\n", *num);
//     }

//     shmdt(num);
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
    int n;
    printf("Enter the number of processes (between 1 and 100): ");
    scanf("%d", &n);
    int shmidA, shmidB;
    key_t keyA = 2211, keyB = 1122;
    int *shmA, *sA , *shmB, *sB;
    fflush(stdin);
    
    if((shmidA = shmget(keyA,MAXSIZE,IPC_CREAT | 0666)) <0) die("shmget");
    if((shmA = shmat(shmidA,NULL,0)) == (int*) -1) die("shmat");
    sA = shmA;

    if((shmidB = shmget(keyB,MAXSIZE,IPC_CREAT | 0666)) <0) die("shmget");
    if((shmB = shmat(shmidB,NULL,0)) == (int*) -1) die("shmat");
    sB = shmB;

    int next, curr;
    printf("A had value %d\n", *sA); printf("B had value %d\n", *sB);
    for(int i = 0; i < n; i++){
        // printf("A: %d \n", *sA); printf("B: %d \n", *sB);
        next = *(sA) + *(sB); curr = *sB;
        *sB = next; *sA = curr;
        printf("Program C writes value %d\n", next);
    }
    *shmA = '*'; *shmB = '*';
    printf("\n");
    exit(0);
}