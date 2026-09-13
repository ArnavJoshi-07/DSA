#include "cll.h"
#include <stdio.h>
#include <stdlib.h>

void init_clist(clist_t * ptr){
    ptr->head = NULL;
}
static node_t* createnode(int key){
    node_t *temp = malloc(sizeof(node_t));
    temp->key = key;
    temp->next=NULL;
    return temp;
}
void insert_begin(clist_t * ptr, int key){
    node_t *temp = createnode(key);
    //if empty list
    if (ptr->head==NULL){
        ptr->head = temp;
        temp->next = temp;
        return;
    }
    node_t *q = ptr->head;
    while(q->next!=ptr->head){
        q = q->next;
    }
    q->next = temp;
    temp->next = ptr->head;
    ptr->head = temp;
}

void insert_end(clist_t *ptr, int key){
    node_t *temp = createnode(key);
    //empty list
    if(ptr->head == NULL){
        ptr->head = temp;
        temp->next = temp;
        return;
    }
    node_t *q = ptr->head;
    while(q->next != ptr->head){
        q = q->next;
    }
    q->next = temp;
    temp ->next = ptr->head;
    return;
}

void disp_list(clist_t *ptr){
    if(ptr->head == NULL){printf("Empty List :(\n");}
    else{
    node_t *q = ptr->head;
    printf("%d->",q->key);
    q=q->next;
    while(q->next!=ptr->head){
        
        printf("%d->",q->key);
        q = q->next;
        }
    printf("%d -> repeat\n",q->key);
    }
}

void free_clist(clist_t *ptr)
{
    if (ptr->head == NULL)
    {
        return;
    }

    node_t *head = ptr->head;
    node_t *q = head->next;

    while (q != head)
    {
        node_t *temp = q;
        q = q->next;
        free(temp);
    }

    free(head);
    ptr->head = NULL;
}