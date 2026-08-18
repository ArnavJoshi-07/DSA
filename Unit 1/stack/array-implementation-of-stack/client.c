#include <stdio.h>
#include "stack.h"
int main(){
    char str[MAXSIZE+1]; char *s = str;
    scanf("%s",str);
    printf("\ninput string : %s\n",str);
    stack_t mystack;
    init_stack(&mystack);
    char ch;
    while((ch = *s++)!='\0'){
        printf("test : pushing %c\n",ch);
        push(&mystack,ch);
    }
    printf("Reversed String : ");
    while(!is_empty(&mystack)){
        putchar(pop(&mystack));
        
    }
    printf("\n");
    destroyStack(&mystack);
}