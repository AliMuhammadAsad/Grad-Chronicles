#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<pthread.h>

#define BUFFER_SIZE 10  // Size of the buffer

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER; // Mutex
static pthread_cond_t cond_not_full = PTHREAD_COND_INITIALIZER; // Conditional variable for when the buffer is not full
static pthread_cond_t cond_not_empty = PTHREAD_COND_INITIALIZER; // Conditional variable for when the buffer is not empty

static int buffer[BUFFER_SIZE];
static int write_pos = 0; // Position to write to
static int read_pos = 0; // Position to read from
static int count = 0;  // Number of items in the buffer

static int producers_done = 0; // Number of producers that have finished

// Function to simulate production: on write-position on buffer, write item, and increment write-position. Then update count of items
static void produce(int item){
    buffer[write_pos] = item;
    printf("Write position: %d\n", write_pos);
    write_pos = (write_pos + 1) % BUFFER_SIZE; count++;
}

// Function to simulate consumption: consume item from read-position on buffer, and increment read-position. Then update count of items
static int consume(){
    int item = buffer[read_pos];
    printf("Read position: %d\n", read_pos);
    read_pos = (read_pos + 1) % BUFFER_SIZE; count--;
    return item;
}

// Producer thread function
static void* producer_func(void* arg){
    int s;
    for(int i = 0; i < *((int*) arg); i++){
        sleep(1); // Simulate time to produce item

        s = pthread_mutex_lock(&mtx);
        if(s != 0){
            perror("pthread_mutex_lock"); exit(EXIT_FAILURE);
        }

        while(count == BUFFER_SIZE){ // Wait until there is space in the buffer
            s = pthread_cond_wait(&cond_not_full, &mtx);
            if(s != 0){
                perror("pthread_cond_wait"); exit(EXIT_FAILURE);
            }
        }
        produce(i); printf("Produced: %d\n", i);
        s = pthread_cond_signal(&cond_not_empty);
        if(s != 0){
            perror("pthread_cond_signal"); exit(EXIT_FAILURE);
        }
        s = pthread_mutex_unlock(&mtx);
        if(s != 0){
            perror("pthread_mutex_unlock"); exit(EXIT_FAILURE);
        }
    }
    return NULL;
}

// Consumer thread function
static void* consumer_func(void* arg){
    int item;
    while(1){
        int s = pthread_mutex_lock(&mtx);
        if(s != 0){
            perror("pthread_mutex_lock"); exit(EXIT_FAILURE);
        }

        while(count == 0){ // Wait until there is something to consume
            s = pthread_cond_wait(&cond_not_empty, &mtx);
            if(s != 0){
                perror("pthread_cond_wait"); exit(EXIT_FAILURE);
            }
        }
        item = consume(); printf("Consumed: %d\n", item);
        s = pthread_cond_signal(&cond_not_full);
        if(s != 0){
            perror("pthread_cond_signal"); exit(EXIT_FAILURE);
        }
        s = pthread_mutex_unlock(&mtx);
        if(s != 0){
            perror("pthread_mutex_unlock"); exit(EXIT_FAILURE);
        }
        if(item >= *((int*) arg) - 1) break; // Stop condition for the consumer
    }
    return NULL;
}

int main(int argc, char* argv[]){
    
    int num_items = atoi(argv[1]);
    pthread_t producer_thread, consumer_thread;
    int s = pthread_create(&producer_thread, NULL, producer_func, &num_items);
    if(s != 0){
        perror("pthread_create"); exit(EXIT_FAILURE);
    }
    s = pthread_create(&consumer_thread, NULL, consumer_func, &num_items);
    if(s != 0){
        perror("pthread_create"); exit(EXIT_FAILURE);
    }
    s = pthread_join(producer_thread, NULL);
    if(s != 0){
        perror("pthread_join"); exit(EXIT_FAILURE);
    }
    s = pthread_join(consumer_thread, NULL);
    if(s != 0){
        perror("pthread_join"); exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}