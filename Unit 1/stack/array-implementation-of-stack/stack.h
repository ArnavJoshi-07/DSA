#ifndef STACK_H
#define STACK_H
#define MAXSIZE 10
struct stack{
    char key_[MAXSIZE];
    int top_;
};
typedef struct stack stack_t;
void init_stack(stack_t *ptr_stack);
void push(stack_t *ptr_stack, char ch);
char pop(stack_t *ptr_stack);
int is_full(stack_t *ptr_stack);
int is_empty(stack_t *ptr_stack);
void destroyStack(stack_t *ptr_stack);
char peek(stack_t *ptr_stack);
#endif