#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 27

void die(char* str){ // error handling function
    perror(str);
    exit(1);
}

int main(void){
    int shmid; // shared memory id
    key_t key; // key
    char* shm, *s; // shared memory pointer

    key = 2211; // key
    fflush(stdin); // flush the input buffer

    // Create a shared memory segment - if the shared memory segment is not created, shmget() will fail
    if((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0) die("shmget");

    // Attach the shared memory segment to the address space of the calling process - if the shared memory segment is not attached, shmat() will fail
    if((shm = shmat(shmid, NULL, 0)) == (char*)-1) die("shmat");

    // Write the lowercase English alphabet to the shared memory
    for(s = shm; *s != '\0'; s++) putchar(*s);

    // Wait until a ‘*’ character appears in the first byte of the shared memory, indicating that the client has read the data
    *shm = '*';
    printf("\n");
    exit(0);
}

/*
This file is responsible for reading data from the shared memory segment created by shm_server.c. It attaches the shared memory segment to its address space using shmat, then reads and prints the data from it. After reading the data, it writes a ‘*’ character to the first byte of the shared memory to signal to the server that it has finished reading.
*/