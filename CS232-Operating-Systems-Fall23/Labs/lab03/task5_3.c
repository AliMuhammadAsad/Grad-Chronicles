#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    FILE *stream = fopen(argv[1], "r");
    if(stream == NULL){
        printf("Error opening file \n");
        return 1;
    }
    char lines[1024]; int counter = 0;
    while(counter < 10 && (fscanf(stream, "%[^\n]%*c", lines) != EOF)){
        printf("%s \n", lines);
        counter++;
    }
    fclose(stream);
    return 0;
}