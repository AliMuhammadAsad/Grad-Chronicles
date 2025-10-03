#include<stdio.h>
#include<stdlib.h>
#include "my_stack.h"

void push(struct node **head, int val){
    struct node* n = malloc(sizeof(struct node));
    n->val = val; n->next = NULL;
    if(*head == NULL) *head = n;
    else{
        struct node* temp = *head;
        *head = n;
        (*head)->next = temp;
    }
}

int pop(struct node **head){
    if(*head == NULL) return -1;
    struct node* temp = *head;
    *head = (*head)->next; int val = temp->val; free(temp);
    return val;
}

void print(struct node *head){
    if(head == NULL) printf("Nothing to print, Stack is empty");
    else{
        while(head != NULL){
            printf("%d \n", head->val);
            head = head->next;
        }
    }
}

int main(){
    struct node* Stack = NULL;
    printf("--------------------------Stack--------------------------\n");
    push(&Stack, 10); push(&Stack, 69); push(&Stack, 420); print(Stack);
    printf("Stack After Popping:\n");
    pop(&Stack); print(Stack);
    printf("Stack After Pushing:\n");
    push(&Stack, 73); print(Stack);
    printf("\n\n");
}