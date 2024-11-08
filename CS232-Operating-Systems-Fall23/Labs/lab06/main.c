#include<stdio.h>
#include "add.h"
#include "sub.h"

int main(int argc, char* argv[]){
    printf("Sum of 2 and 5 is %d\n", add(2, 5));
    printf("Difference of 2 and 5 is %d\n", sub(2, 5));
    return 0;
}