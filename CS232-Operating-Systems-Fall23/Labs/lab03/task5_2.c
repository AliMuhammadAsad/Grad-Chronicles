#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv){
    FILE *stream_hello = fopen("helloworld.txt", "a");
        for(int i = 0; i < 20; i++){
            // fprintf(stream_hello, "Hello World \n");
            fprintf(stream_hello, "Iteration: %d \n", i);
        }
    fclose(stream_hello);
    return 0;
}