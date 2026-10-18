#include <stdio.h>
#include <stdlib.h>

#include "bt.h"

int main(){
    //case 1
    tree_t t1;
    init_tree(&t1);
    int a1[] = {40,20,60,10,70,30,50};
    int n1 = 7;
    for(int i = 0; i<n1; ++i){
        insert_tree(&t1,a1[i]);
    }
    disp_inorder(&t1);
    destroy_tree(&t1);


    //case 2
    tree_t t2;
    init_tree(&t2);
    int n; 
    printf("Enter no of nodes to insert in tree: "); scanf(" %d", &n);
    int a2[n];
    for(int i =0; i<n; i++){
        printf("Enter value of node %d: ",i+1);scanf("%d", &a2[i]);
    }
    for(int i = 0; i<n; i++){
        insert_tree(&t1, a2[i]);
    }
    disp_inorder(&t2);
    destroy_tree(&t2);

}