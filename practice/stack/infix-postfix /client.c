#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int prec_in_str(char ch){
    int p;
    if(ch == '(') p = 3;
    else if(ch=='*' || ch =='/') p = 2;
    else if(ch == '+' || ch == '-') p = 1;
    return p;
}

int prec_in_stack(char ch){
    int p;
    if(ch == '(') p = 0;
    else if (ch == '*' || ch == '/') p = 2;
    else if (ch == '+'||ch =='-') p = 1;
    return p;
}

int main(){
    char in[MAXSIZE+1]; char *s = in;
    char post[MAXSIZE +1]; char *p = post;
    printf("Enter infix expression: \n"); 
    fgets(s,sizeof(s),stdin);
    printf("Input Expression : %s\n",s);
    stack_t stk;
    init_stack(&stk);
    char ch;
    char ch1;
    while((ch = *s++)!='\0'){
        if (ch == ')'){
            while((ch1 = pop(&stk))!= '('){
                *p++ = ' ';
                *p++ = ch1;
            }
        }
        else if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch =='/'){
            if(is_empty(&stk)) push(&stk, ch);
            else{
                while(!is_empty(&stk) && prec_in_str(ch)<=prec_in_stack(peek(&stk))){
                    *p++ = ' ';
                    *p++ = pop(&stk);
                }
                push(&stk, ch);
            }
        }
        else{*p++ = ch;}
    }
    while(!is_empty(&stk)){
        *p++ = ' ';
        *p++ = pop(&stk);
    }
    *p = '\0';

    printf("\nInfix = %s\n",in);
    printf("\nPostfix = %s\n",post);
    deinit(&stk);
    
}
