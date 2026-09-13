#include "stack.h"



int main(){
    stack_t ptr_stack;
    init_stack(&ptr_stack);

    printf("Enter no of elements to push: ");
    int i = 0; 
    scanf("%d",&i);
    if(i>MAXSIZE){
        printf("Please enter a smaller size."); exit(0);
    }
    char ch;
    for(int k = 0; k< i; k++){
        printf("Enter char to push: ");scanf(" %c", &ch);
        push(&ptr_stack, ch);
    }
    printf("Element popped: %c\n", pop(&ptr_stack));

    printf("Peeking: Element at top: %c\n",peek(&ptr_stack));
    printf("Destroying Stack\n "); destroy_stack(&ptr_stack);

}