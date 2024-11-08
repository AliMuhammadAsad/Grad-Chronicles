#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

void append(struct node **head, int val);

int pop_dynamic(struct node **head);

int insert(struct node **head, int val, int index);

int delete(struct node **head, int index);

int get(struct node **head, int index);

int length(struct node **head);

void print_dll(struct node *head);

#endif // !DYNAMIC_LIST_H
