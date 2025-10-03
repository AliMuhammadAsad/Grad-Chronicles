#ifndef MY_STACK_H
#define MY_STACK_H

void push(struct node **head, int val);

int pop_stack(struct node **head);

void print_stack(struct node *head);

#endif // !MY_STACK_H