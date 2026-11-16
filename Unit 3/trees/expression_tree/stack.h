#ifndef STACK_H
#define STACK_H

#define MAXSIZE 100


typedef struct node{
    char ch;
    struct node* left;
    struct node* right;
}node_t;

typedef struct stack{
    node_t * key[MAXSIZE];
    int top;
}stack_t;

void init_stack(stack_t *);
void deinit_stack(stack_t *);
void push_operand(stack_t *, char);
void push_operator(stack_t *, char);

node_t *pop(stack_t *);

int is_empty(stack_t *);
int is_full(stack_t *);

int eval(stack_t *);

#endif