#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
void init_stack(stack_t *ptr){
    ptr->top = -1;
}

void push(stack_t *ptr, char ch){
    if(!is_full(ptr)){
        ptr->key[++ptr->top] = ch;
    }
    else{printf("\nStack is full; Cannot Push.\n");}
}

char pop(stack_t *ptr){
    if(is_empty(ptr)) {printf("\nStack is empty; Cannot pop.\n"); return '\0';}
    else{
        return ptr->key[ptr->top--];
    }
}
int is_full(stack_t *ptr){
    return ptr->top == MAXSIZE-1;
}

int is_empty(stack_t *ptr){
    return ptr->top == -1;
}

char peek(stack_t *ptr){
    return ptr->key[ptr->top];
}
void destroy_stack(stack_t *ptr){
    ptr->top = -1;
}