#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_balanced(char *expr){
    stack_t mystack;
    init_stack(&mystack);
    char ch;
    while((ch = *expr++) != '\0'){
        if(ch == '('){
            push(&mystack,ch);
        }
        else if(ch == ')'){
            if(is_empty(&mystack)){
                return 0;
            }
            pop(&mystack);
        }
    }
    int balanced = is_empty(&mystack);
    destroyStack(&mystack);
    return balanced;
}

int main(){
    char expr[MAXSIZE+1];
    printf("Enter expression : ");
    scanf("%s",expr);
    printf("The given expression is : %s\n",expr);
    if(is_balanced(expr)){
        printf("\nExpression is balanced.\n");
    }
    else{
        printf("\nExpression is not balanced.\n");
    }
    return 0;
}
