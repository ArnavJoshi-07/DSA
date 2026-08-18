#include "stack.h"
#include <stdio.h>
void init_stack(stack_t *ptr_stack){
    ptr_stack -> top_ = -1;
}
void push(stack_t *ptr_stack, char ch){
    if(!is_full(ptr_stack)){
        ptr_stack -> key_[++ ptr_stack->top_] = ch;
    }
    else{printf("\nStack is full, cannot push.\n");}
}
char pop(stack_t *ptr_stack){
    if(!is_empty(ptr_stack)){
        return ptr_stack->key_[ptr_stack->top_--];
    }
    else{
        printf("\nStack is empty, cannot pop.\n");
        return '\0';
    }
}
int is_full(stack_t *ptr_stack){
    return ptr_stack->top_ == MAXSIZE-1;
}
int is_empty(stack_t *ptr_stack){
    return ptr_stack->top_ == -1;
}
char peek(stack_t *ptr_stack){
    return ptr_stack->key_[ptr_stack->top_];
}
void destroyStack(stack_t *ptr_stack){
    ptr_stack->top_ = -1;
}
