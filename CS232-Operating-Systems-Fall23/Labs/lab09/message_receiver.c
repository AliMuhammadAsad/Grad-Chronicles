#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>

struct msgbuf{
    long mtype;         // message type, must be > 0
    char msgtxt[200];   // message data
};

int main(void){
    struct msgbuf msg; // message buffer
    int msgid;        // message id
    key_t key;       // key

    // Generate a unique key - if the file message_send.c does not exist, ftok() will fail
    if((key = ftok("message_send.c", 'b')) == -1){ 
        perror("ftok"); exit(1);
    }

    // Access the message queue - if the message queue is not created, msgget() will fail
    if((msgid = msgget(key, 0644)) == -1){
        perror("msgget"); exit(1);
    }

    // receive messages of any type -> infinite loop
    for(;;){
        if(msgrcv(msgid, &msg, sizeof(msg), 0, 0) == -1){ // receive the message
            perror("msgrcv"); exit(1);
        }
        printf("message_receive [INFO] Message: %s\n", msg.msgtxt);
    }

    return 0;
}