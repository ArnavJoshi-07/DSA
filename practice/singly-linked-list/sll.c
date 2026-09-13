#include <stdio.h>
#include "sll.h"
#include <stdlib.h>

void init_list(sll_t* ptr_list){
    ptr_list->head = NULL;
}

void insert_list(sll_t * ptr_list, int val){
    node_t *temp = malloc(sizeof(node_t));
    temp->key = val;
    temp->next = NULL;
    if(ptr_list->head == NULL){
        ptr_list->head = temp;

    }
    else {
        node_t *prev = NULL;
        node_t *pres = ptr_list->head;
        while(pres!= NULL && temp->key > pres->key){
            prev = pres;
            pres = pres->next;
        }
        //insert at beginning
        if (prev == NULL){
            temp->next = ptr_list->head; //temp next points to the earlier first node
            ptr_list->head = temp;
        }
        //middle or end
        else{
        prev->next = temp;
        temp->next = pres;
        }
    }
}
void disp_list(sll_t *ptr_list){
    node_t *temp = malloc(sizeof(node_t));
    int i = 0;
    temp = ptr_list->head;
    while(temp!=NULL){
        printf("Key at node %d is %d\n", i++, temp->key);
        temp = temp->next;
    }
}

void freelist(sll_t *ptr_list){
    node_t *q = malloc(sizeof(node_t));
    q = ptr_list -> head;
    while(ptr_list != NULL){
        node_t *r = q->next;
        free(q);
        q = r;
    }
    printf("LIST FREED\n");
}