#include<stdio.h>
#include<stdlib.h>
#include "node.h"
#include "my_stack.h"
#include "dynamic_list.h"

int main(int argc, char* argv[]){
    struct node* Stack = NULL;
    printf("--------------------------Stack--------------------------\n");
    push(&Stack, 10); push(&Stack, 69); push(&Stack, 420); print_stack(Stack);
    printf("Stack After Popping:\n");
    pop_stack(&Stack); print_stack(Stack);
    printf("Stack After Pushing:\n");
    push(&Stack, 73); print_stack(Stack);
    printf("\n\n");

    struct node* List = NULL;
    printf("------------------DYNAMIC LINKED LIST------------------\n");
    printf("Dynamic Linked List\n");
    append(&List, 10); append(&List, 69); append(&List, 420); append(&List, 73); printf("Length of list is %d\n", length(&List)); print_dll(List);
    pop_dynamic(&List); print_dll(List); pop_dynamic(&List); print_dll(List);
    insert(&List, 69, 0); print_dll(List); insert(&List, 10, 0); print_dll(List); insert(&List, 20, 1); print_dll(List); insert(&List, 99, 3); print_dll(List);
    delete(&List, 0); print_dll(List);
    delete(&List, 1); print_dll(List);
    get(&List, 1); get(&List, 3);
    return 0;
}