#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void init_stack(stack_t * ptr){
    ptr->top = NULL;
}

void destroy_stack(stack_t *ptr){
    while(!is_empty(ptr)){
        pop(ptr);
    }
    ptr->top = NULL;
}

void push(stack_t *ptr, char ch){
    if(!is_full(ptr)){
        node_t *temp = malloc(sizeof(node_t));
        temp->key = ch;
        temp->next = ptr->top;
        ptr->top = temp;
    }
    else{
        printf("Stack is full! Cannot Push;\n");
    }
}
char pop(stack_t *ptr){
    if(!is_empty(&ptr)){
        char ch;
        node_t *temp = ptr->top;
        ch = temp->key;
        ptr->top = temp->next;
        free(temp);
        return ch;
    }
    else{
        printf("Stack is empty, cannot pop!\n"); return '\0';
    }
}
char peek(stack_t *ptr){
    if(!is_empty(ptr)){
        char ch;
        ch = ptr->top->key;
        return ch;
    }
    else{
        printf("Stack is empty, cannot peek.");
    }
}

int is_empty(stack_t *ptr){
    return ptr->top == NULL;
}
int is_full(stack_t *ptr){
    node_t *temp = malloc(sizeof(node_t));
    if(temp == NULL){
        return 1;
    }
    free(temp);
    return 0;
}


