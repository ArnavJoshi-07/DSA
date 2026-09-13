#ifndef STACK_H
#define STACK_H
#define MAXSIZE 10
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char key[MAXSIZE];
    int top;
}stack_t;

void init_stack(stack_t *);
void push(stack_t *,char);
char pop(stack_t *);
int is_full(stack_t *);
int is_empty(stack_t *);
char peek(stack_t *);
void destroy_stack(stack_t *);
#endif
