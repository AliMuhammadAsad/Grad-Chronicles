#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void corruptHukamran(){
    int* p = NULL;
    asm("movq %%rbp, %0" : "=r"(p)); //Getting a pointer to the current function's stack frame
    // asm means an assembly block, where we can inlcude assembly instructions
    // the movq instruction is used to move the value of the rbp (base pointer) register to a variable. %0 is a space holder for the output operand, : "=r"(p) is the output constraint which tells the compiler to store the result of the inline assembly. So it is stored in p which was our pointer.

    if(p != NULL) p[1] = 0xFFFFFFFF; //Corrupting the return address of the current function
}

int main(){
    printf("Before corruptHukamran() call\n");
    corruptHukamran();
    printf("After corruptHukamran() called - Should output some error or smthng\n");
    return 0;
}