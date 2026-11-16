#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


void init_stack(stack_t* ptr){
    ptr->top = -1;
}

void deinit_stack(stack_t *ptr){
    ptr->top = -1;
}

static node_t *create_node(char ch){
    node_t *temp = malloc(sizeof(node_t));
    if(temp == NULL){
        printf("Memory FULL!!\n"); exit(1);
    }
    temp->ch = ch;
    temp->left = temp->right = NULL;
    return temp;
}
void push_operand(stack_t *ptr, char ch){
    if(!is_full(ptr)){
        node_t *temp = create_node(ch);
        ptr->key[++ptr->top] = temp;
    }
    else{
        printf("Stack full; cannot push!\n");
    }
}

void push_operator(stack_t *ptr, char ch){
    if(!is_full(ptr)){
        node_t *temp = create_node(ch);
        temp->right = pop(ptr);
        temp->left = pop(ptr);
        ptr->key[++ptr->top]=temp;
    }
}

node_t* pop(stack_t *ptr){
    if(!is_empty(ptr)){
        return ptr->key[ptr->top--];
    }
    else{
        return '\0';
    }
}

int is_empty(stack_t *ptr){
    return ptr->top == -1;
}

int is_full(stack_t *ptr){
    return ptr->top + 1 == MAXSIZE;
}

int eval_recursive(node_t *root){
    int left,right;
    if(root->left == NULL && root->right ==NULL){
        return root->ch - '0';
    }
    left = eval_recursive(root->left);
    right = eval_recursive(root->right);
    switch (root->ch){
        case '+' : return left + right;
        case '-' : return left - right;
        case '*' : return left * right;
        case '/' : return left/right;
    }
    return 0;
}

int eval(stack_t *ptr){
    return eval_recursive(pop(ptr));
}