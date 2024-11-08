#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

void address(){
    int x = 42, y = 73;
    int* px = &x; int* py = px + 1; *py = 69;
    printf("Pointer of x %p points to %d, \t Pointer of y %p points to %d\n", px, x, py, y);
}

int main(){
    address();
    return 0;
}
