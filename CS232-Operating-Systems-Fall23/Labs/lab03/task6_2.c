#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv){
    FILE *stream = fopen("processes.dat", "r");
    if(stream == NULL){
        printf("Error opening file \n");
        return 1;
    }
    char line[1024]; int process_id; char name[256]; float duration; int priority;
    printf("Process ID: \t Name: \t Duration: \t Priority: \t \n");
    while(fscanf(stream, "%d %s %f %d", &process_id, name, &duration, &priority) != EOF){
        printf("%d \t \t %s \t %f \t %d \t \n", process_id, name, duration, priority);
    }

    return 0;
}