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
    int msgid;      // message id
    key_t key;      // key

    // Generate a unique key - if the file message_send.c does not exist, ftok() will fail
    if((key = ftok("message_send.c", 'b')) == -1){
        perror("ftok"); exit(1);
    }

    // Create a message queue - if the message queue is not created, msgget() will fail
    if((msgid = msgget(key, 0644|IPC_CREAT)) == -1){
        perror("msgget"); exit(1);
    }

    
    printf("message_send [INFO] The message ID is: %d\n", msgid);
    printf("message_send [PROMPT] Enter a text: ");
    msg.mtype = 1; // message type must be > 0
    // Loop over the message queue
    while(gets(msg.msgtxt), !feof(stdin)){
        if(msgsnd(msgid, &msg, sizeof(msg), 0) == -1){ // send the message 
            perror("msgsnd"); exit(1);
        }
    }

    // Delete the message queue
    if(msgctl(msgid, IPC_RMID, NULL) == -1){
        perror("msgctl"); exit(1);
    }
    return 0;
}

// to delete the message through the command line one can use the following command
// ipcrm -q <msgid>