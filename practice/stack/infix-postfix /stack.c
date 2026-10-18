#include "stack.h"
#include <stdio.h>  
#include <stdlib.h>

void init_stack(stack_t*ptr){
    ptr->top = -1;
}
void deinit(stack_t*ptr){
    ptr->top = -1;
}
void push(stack_t*ptr,char ch){
    if(!is_full(ptr))
    {ptr->key[++ptr->top] = ch;return;}
    else{printf("Stack is full, cannot push.\n");}
    
}
char pop(stack_t*ptr){
    if(!is_empty(ptr)){
    char ch = ptr->key[ptr->top--];
    return ch;}
    else{return '\0';}
}
char peek(stack_t *ptr){
    if(!is_empty(ptr)){
        char ch = ptr->key[ptr->top]; return ch;
    }
    else return '\0';
}

int is_empty(stack_t *ptr){
    return ptr->top == -1;
}
int is_full(stack_t*ptr){
    return ptr->top == MAXSIZE-1;
}