#ifndef STACK_H 
#define STACK_H
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    char key;
    struct node *next;
}node_t;

typedef struct stack{
    node_t *top;
}stack_t;

void init_stack(stack_t *);
void push(stack_t *, char);
char pop(stack_t *);
int is_full(stack_t *);
int is_empty(stack_t *);
char peek(stack_t *);
void destroy_stack(stack_t *);
#endif