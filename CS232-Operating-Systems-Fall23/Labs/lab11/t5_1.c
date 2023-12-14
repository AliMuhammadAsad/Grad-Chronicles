#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

#define NUM_INSERTS 100000
#define NUM_DELETES 1000

typedef struct Node{
    int data;
    struct Node* next;
} Node;

static volatile Node* head = NULL;

void insert_elements(){
    for(int i = 0; i < NUM_INSERTS; i++){
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = i; new_node->next = NULL;
        new_node->next = head; head = new_node;
    }
}

void delete_elements(){
    for(int i = 0; i < NUM_DELETES; i++){
        if(head != NULL){
            Node* temp = head; head = head->next; free(temp);
        }
    }
}

void count_elements(){
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        count++; temp = temp->next;
    }
    printf("count = %d\n", count);
}

int main(int argc, char* argv[]){
    printf("#---------------------------Task 5: Linked List---------------------------#\n\n");
    printf("#---------------------------Task 5.1---------------------------#\n");
    printf("main: Starting Operations\n");
    insert_elements();
    delete_elements();
    count_elements();
    printf("main: Operations Completed\n");
    return 0;
}

/*
gcc -lpthread -o t5_1 t5_1.c
./t5_1
rm -rf t5_1
*/