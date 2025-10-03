#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/mman.h>

int main(){
    void* mem_ptr = mmap(NULL, 1024 * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if(mem_ptr == MAP_FAILED){
        perror("mmap failed"); exit(1);
    }

    int* arr = (int*)mem_ptr;
    for(int i = 0; i < 1024; i++) arr[i] = i;

    printf("Verifying Data by printing 1024 integers in a 32x32 grid\n");
    int count = 0;
    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 32; j++) printf("%d ", arr[count++]);
        printf("\n");
    }

    if(munmap(mem_ptr, 1024 * sizeof(int)) == -1){
        perror("munmap failed"); exit(1);
    }

    return 0;
}