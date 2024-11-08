#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

#define NUM_THREADS 5
#define NUM_INSERTS 100000
#define NUM_DELETES 1000

typedef struct Node{
    int data;
    struct Node* next;
} Node;

static volatile Node* head = NULL; // shared global variable for linked list
static pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void* insert_elements(void* arg){
    for(int i = 0; i < NUM_INSERTS; i++){
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = i; new_node->next = NULL;
        pthread_mutex_lock(&m);
        new_node->next = head; head = new_node;
        pthread_mutex_unlock(&m);
    }
    return NULL;
}

void* count_elements(){
    int count = 0;
    pthread_mutex_lock(&m);
    Node* temp = head;
    while(temp != NULL){
        count++; temp = temp->next;
    }
    pthread_mutex_unlock(&m);
    printf("count = %d\n", count);
    return NULL;
}

int main(int argc, char* argv[]){
    printf("#---------------------------Task 5.2---------------------------#\n");
    pthread_t threads[NUM_THREADS];
    printf("main: creating threads\n");
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, insert_elements, NULL);
        pthread_join(threads[i], NULL);
    }
    printf("main: threads created\n");
    // for(int i = 0; i < NUM_THREADS; i++){
    //     pthread_join(threads[i], NULL);
    // }
    count_elements();
    printf("main: threads joined\n");
    return 0;
}

/*
gcc -lpthread -o t5_2 t5_2.c
./t5_2
rm -rf t5_2
*/

// void* delete_elements(void* arg){
//     for(int i = 0; i < NUM_DELETES; i++){
//         pthread_mutex_lock(&m);
//         if(head != NULL){
//             Node* temp = head; head = head->next; free(temp);
//         }
//         pthread_mutex_unlock(&m);
//     }
//     return NULL;
// }
