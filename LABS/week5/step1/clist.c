#include <stdio.h>
#include <stdlib.h>
#include "clist.h"

void init_clist(clist_t *ptr_clist)
{
    ptr_clist->head_ = NULL;
}

static node_t *create_node(int key)
{
    node_t *temp = (node_t *)malloc(sizeof(node_t));

    if(temp == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->key_ = key;
    temp->next_ = NULL;
    return temp;
}

node_t *last_node(clist_t *ptr_clist)
{
    node_t *pres = ptr_clist->head_;

    if(pres == NULL)
        return NULL;

    while(pres->next_ != ptr_clist->head_)
        pres = pres->next_;

    return pres;
}

void insert_end(clist_t *ptr_clist, int key)
{
    node_t *temp = create_node(key);

    if(ptr_clist->head_ == NULL){
        temp->next_ = temp;
        ptr_clist->head_ = temp;
        return;
    }

    node_t *last = last_node(ptr_clist);
    last->next_ = temp;
    temp->next_ = ptr_clist->head_;
}

node_t *remove_after(clist_t *ptr_clist, node_t *cur)
{
    if(cur == NULL || ptr_clist->head_ == NULL)
        return NULL;

    node_t *victim = cur->next_;

    if(victim == cur)
        ptr_clist->head_ = NULL;            /* cur was the only node left */
    else{
        cur->next_ = victim->next_;
        if(victim == ptr_clist->head_)
            ptr_clist->head_ = victim->next_;
    }

    victim->next_ = NULL;
    return victim;
}

void disp_list(clist_t *ptr_clist)
{
    node_t *pres = ptr_clist->head_;

    if(pres == NULL){
        printf("List is empty\n");
        return;
    }

    node_t *temp = pres;
    printf("Circular List: ");
    do{
        printf("%d ", temp->key_);
        temp = temp->next_;
    }while(temp != pres);
    printf("\n");
}

void free_clist(clist_t *ptr_clist)
{
    node_t *pres = ptr_clist->head_;

    if(pres == NULL)
        return;

    node_t *temp = pres->next_;
    while(temp != pres){
        node_t *next = temp->next_;
        free(temp);
        temp = next;
    }
    free(pres);
    ptr_clist->head_ = NULL;
}
