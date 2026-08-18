#include <stdio.h>
#include <stdlib.h>
typedef struct node 
{
    int key;
    struct node *next;
}node_t;
int main(){
    node_t *p = malloc(sizeof(node_t));
    p->key = 10;
    p->next = (node_t *)malloc(sizeof(node_t));
    p->next->key = 20; 
}
