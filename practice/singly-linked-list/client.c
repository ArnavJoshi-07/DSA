#include <stdio.h>
#include "sll.h"

int main(){
    sll_t ptr_list;
    init_list(&ptr_list);
    printf("Enter no of nodes to enter: ");
    int i = 0;
    scanf("%d",&i);
    int key = 0;
    for(int j = 0; j<i; j++){
        printf("Enter value of node %d: ",j+1);
        scanf("%d",&key);
        insert_list(&ptr_list, key);
    }
    disp_list(&ptr_list);
    freelist(&ptr_list);
}