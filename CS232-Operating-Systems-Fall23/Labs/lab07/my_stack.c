#include<stdio.h>
#include<stdlib.h>
#include "node.h"
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

int pop_stack(struct node **head){
    if(*head == NULL) return -1;
    struct node* temp = *head;
    *head = (*head)->next; int val = temp->val; free(temp);
    return val;
}

void print_stack(struct node *head){
    if(head == NULL) printf("Nothing to print, Stack is empty");
    else{
        while(head != NULL){
            printf("%d \n", head->val);
            head = head->next;
        }
    }
}