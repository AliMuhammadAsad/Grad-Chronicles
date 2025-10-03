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
    char c; // character
    int shmid; // shared memory id
    key_t key; // key
    char* shm, *s; // shared memory pointer

    key = 2211; // key

    // Create a shared memory segment - if the shared memory segment is not created, shmget() will fail
    if((shmid = shmget(key, MAXSIZE, IPC_CREAT|0666)) < 0) die("shmget");

    // Attach the shared memory segment to the address space of the calling process - if the shared memory segment is not attached, shmat() will fail
    if((shm = shmat(shmid, NULL, 0)) == (char*)-1) die("shmat");

    s = shm; // shared memory pointer

    // Write the lowercase English alphabet to the shared memory    
    for(c = 'a'; c <= 'z'; c++) *s++ = c;

    // Wait until a ‘*’ character appears in the first byte of the shared memory, indicating that the client has read the data
    while(*shm != '*') sleep(1);

    exit(0);
}

/*
This file is responsible for creating a shared memory segment and writing data to it. It first creates a shared memory segment using the shmget function. Then, it attaches this shared memory segment to its address space using the shmat function. After that, it writes the lowercase English alphabet to the shared memory. Finally, it waits until a ‘*’ character appears in the first byte of the shared memory, indicating that the client has read the data.
*/