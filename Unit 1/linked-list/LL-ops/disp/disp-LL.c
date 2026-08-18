#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int key;
    struct node *next;
}node_t;

void disp(node_t * q){
    while(q!=NULL){
        printf("%d",q->key);
        q = q->next;
    }
}