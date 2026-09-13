#include <stdio.h>
#include "dll.h"
#include <stdlib.h>

void init_list(dll_t *ptr_list){
    ptr_list->head= NULL;
}
static node_t* create_node(int key) {
    node_t *temp = malloc(sizeof(node_t));

    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    temp->key = key;
    temp->rlink = NULL;
    temp->llink = NULL;

    return temp;
}

void insert_begin(dll_t *ptr_dll, int key) {
    node_t *temp = create_node(key);

    temp->rlink = ptr_dll->head;
    temp->llink = NULL;

    if (ptr_dll->head != NULL)
        ptr_dll->head->llink = temp;

    ptr_dll->head = temp;
}

void insert_end(dll_t *ptr, int key) {
    node_t *temp = create_node(key);

    if (ptr->head == NULL) {
        ptr->head = temp;
        return;
    }

    node_t *q = ptr->head;

    while (q->rlink != NULL)
        q = q->rlink;

    q->rlink = temp;
    temp->llink = q;
}

void delete_begin(dll_t *ptr){
    if(ptr->head == NULL) return;
    node_t *q = ptr->head;
    ptr->head = q->rlink;
    if(ptr->head!=NULL){
        ptr->head->llink = NULL;
    }
    free(q);
}
void delete_end(dll_t *ptr){
    if(ptr->head == NULL) return;
    if(ptr->head->rlink == NULL){
        node_t *q = ptr->head;
        free(q);
        ptr->head = NULL;
        return;
    }
    node_t *q = ptr->head;
    while(q->rlink->rlink !=NULL) q = q->rlink;
    free(q->rlink);q->rlink=NULL;
}
void delete_val(dll_t *ptr, int key){
    node_t *curr = ptr->head;

    while(curr!=NULL){
        //last node containing key
        if(curr->key == key && curr->rlink == NULL){
            node_t *q = curr->llink;
            free(curr); q->rlink =NULL; return;
        }
        //first node has key
        if(curr->key == key && curr->llink == NULL){
            ptr->head= curr->rlink;
            if(ptr->head!=NULL) ptr->head->llink = NULL;
            free(curr);
            return;
        }
        if(curr->key == key && curr->llink != NULL && curr->rlink != NULL){
            node_t *p = curr->llink;
            node_t *q = curr->rlink;
            p->rlink = q;
            q->llink = p;
            free(curr);return;
        }
        curr=curr->rlink;
        


    }
    printf("Value Not Found!"); return; 
    
}
void disp_fwd(dll_t *ptr) {
    node_t *q = ptr->head;

    if (q == NULL) {
        printf("NULL\n");
        return;
    }

    while (q->rlink != NULL) {
        printf("%d->", q->key);
        q = q->rlink;
    }

    printf("%d->NULL\n", q->key);
}

void disp_bwd(dll_t *ptr) {
    node_t *q = ptr->head;

    if (q == NULL) {
        printf("NULL\n");
        return;
    }

    while (q->rlink != NULL)
        q = q->rlink;

    while (q->llink != NULL) {
        printf("%d->", q->key);
        q = q->llink;
    }

    printf("%d->NULL\n", q->key);
}
