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
static int t; // Time variable
static int producers_done = 0; // Number of producers that have finished

// Function to simulate production: on write-position on buffer, write item, and increment write-position. Then update count of items
static void produce(int item){
    buffer[write_pos] = item;
    // printf("Write position: %d\n", write_pos);
    // printf("T=%ld: Produced item %d at position %d\n", (long)(time(NULL) - t), item + 1, write_pos + 1);
    write_pos = (write_pos + 1) % BUFFER_SIZE; count++;
}

// Function to simulate consumption: consume item from read-position on buffer, and increment read-position. Then update count of items
static int consume(){
    int item = buffer[read_pos];
    // printf("Read position: %d\n", read_pos);
    // printf("T=%ld: Consumed item %d from position %d\n", (long)(time(NULL) - t), item + 1, read_pos + 1);
    read_pos = (read_pos + 1) % BUFFER_SIZE; count--;
    return item;
}

// Producer thread function
static void* producer_func(void* arg){
    int s;
    t = time(NULL);
    int num_items = *((int*) arg);
    for(int i = 0; i < num_items; i++){
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

        produce(i); printf("Produced: %d\n", i + 1);
        s = pthread_cond_signal(&cond_not_empty);
        if(s != 0){
            perror("pthread_cond_signal"); exit(EXIT_FAILURE);
        }
        s = pthread_mutex_unlock(&mtx);
        if(s != 0){
            perror("pthread_mutex_unlock"); exit(EXIT_FAILURE);
        }
    }
    s = pthread_mutex_lock(&mtx);
    producers_done++;
    pthread_cond_broadcast(&cond_not_empty);
    s = pthread_mutex_unlock(&mtx);

    return NULL;
}

// Consumer thread function
static void* consumer_func(void* arg){
    int s, num_producers = *((int*) arg), item;
    while(1){
        sleep(1);
        s = pthread_mutex_lock(&mtx);
        if(s != 0){
            perror("pthread_mutex_lock"); exit(EXIT_FAILURE);
        }

        while(count == 0 && producers_done < num_producers){ // Wait until there is an item in the buffer
            s = pthread_cond_wait(&cond_not_empty, &mtx);
            if(s != 0){
                perror("pthread_cond_wait"); exit(EXIT_FAILURE);
            }
        }
        if(count == 0 && producers_done == num_producers){
            s = pthread_mutex_unlock(&mtx); break;
        }
        item = consume(); printf("Consumed: %d\n", item + 1);
        s = pthread_cond_signal(&cond_not_full);
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

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("Usage: %s <num_items1> <num_items2> <num_items3> ... <num_itemsN>\n", argv[0]); exit(EXIT_FAILURE);
    }
    int num_producers = argc - 1;
    pthread_t producer_threads[num_producers], consumer_thread;
    int num_items[num_producers];

    for(int i = 0; i < num_producers; i++){
        num_items[i] = atoi(argv[i + 1]);
        int s = pthread_create(&producer_threads[i], NULL, producer_func, &num_items[i]);
        if(s != 0){
            perror("pthread_create"); exit(EXIT_FAILURE);
        }
    }

    int s = pthread_create(&consumer_thread, NULL, consumer_func, &num_producers);
    if(s != 0){
        perror("pthread_create"); exit(EXIT_FAILURE);
    }

    for(int i = 0; i < num_producers; i++){
        s = pthread_join(producer_threads[i], NULL);
        if(s != 0){
            perror("pthread_join"); exit(EXIT_FAILURE);
        }
    }

    s = pthread_join(consumer_thread, NULL);
    if(s != 0){
        perror("pthread_join"); exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}