#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
    if(argc !=3 ){
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        exit(1);
    }

    FILE *source = fopen(argv[1], "r"); FILE *destination = fopen(argv[2], "w+");
    if(source == NULL){
        printf("Error opening file \n");
        return 1;
    }
    char lines[1024];
    while(fscanf(source, "%[^\n]%*c", lines) != EOF){
        printf("%s \n", lines);
        fprintf(destination, "%s \n", lines);
    }

    fclose(source); fclose(destination);
    return 0;
}