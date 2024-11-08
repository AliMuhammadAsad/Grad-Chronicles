#ifndef MY_STACK_H
#define MY_STACK_H

struct node{
    int val;
    struct node *next;
};

void push(struct node **head, int val);

int pop(struct node **head);

void print(struct node *head);

#endif // !MY_STACK_H