#include <stdio.h>
#include <stdlib.h>
#include "dll.h"


void init_dll(dll_t *ptr_dll)
{
    ptr_dll->head_ = ptr_dll->cur_ = NULL;
}

void deinit_dll(dll_t *ptr_dll)
{
    node_t *pres = ptr_dll->head_;
    if (pres != NULL)
        pres->prev_->next_ = NULL;
    while (pres != NULL)
    {
        node_t *temp = pres;
        pres = pres->next_;
        free(temp);
    }
    ptr_dll->head_ = ptr_dll->cur_ = NULL;
}

/* Create a new node */
static node_t* create_node(int key)
{
    node_t *temp;
    temp = (node_t*)malloc(sizeof(node_t));

    // one of the possible ways of handling an exceptional case
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->key_ = key;
    temp->prev_ = temp;
    temp->next_ = temp;
    return temp;
}

static void link_before(node_t *pos, node_t *temp)
{
    temp->next_ = pos;
    temp->prev_ = pos->prev_;
    pos->prev_->next_ = temp;
    pos->prev_ = temp;
}

static node_t* find_node(dll_t *ptr_dll, int key)
{
    node_t *pres = ptr_dll->head_;
    if (pres == NULL)
        return NULL;
    do {
        if (pres->key_ == key)
            return pres;
        pres = pres->next_;
    } while (pres != ptr_dll->head_);
    return NULL;
}

static void remove_node(dll_t *ptr_dll, node_t *temp)
{
    if (temp->next_ == temp) {
        ptr_dll->head_ = ptr_dll->cur_ = NULL;
    } else {
        temp->prev_->next_ = temp->next_;
        temp->next_->prev_ = temp->prev_;
        if (ptr_dll->head_ == temp)
            ptr_dll->head_ = temp->next_;
        if (ptr_dll->cur_ == temp)
            ptr_dll->cur_ = temp->next_;
    }
    free(temp);
}

/* Insert at the beginning */
void insert_begin(dll_t *ptr_dll, int key)
{
    node_t *temp = create_node(key);
    if (ptr_dll->head_ == NULL) {
        ptr_dll->head_ = ptr_dll->cur_ = temp;
        return;
    }
    link_before(ptr_dll->head_, temp);
    ptr_dll->head_ = temp;
}

/* Insert at the end */
void insert_end(dll_t *ptr_dll, int key)
{
    node_t *temp = create_node(key);
    if (ptr_dll->head_ == NULL) {
        ptr_dll->head_ = ptr_dll->cur_ = temp;
        return;
    }
    link_before(ptr_dll->head_, temp);
}

void insert_before_cur(dll_t *ptr_dll, int key)
{
    node_t *temp = create_node(key);
    if (ptr_dll->cur_ == NULL) {
        ptr_dll->head_ = ptr_dll->cur_ = temp;
        return;
    }
    link_before(ptr_dll->cur_, temp);
}

/* Display from left to right */
void disp_forward(dll_t *ptr_dll)
{
    node_t *temp = ptr_dll->head_;
    printf("Forward: ");
    if (temp != NULL) {
        do {
            if (temp == ptr_dll->cur_)
                printf("[%d] ", temp->key_);
            else
                printf("%d ", temp->key_);
            temp = temp->next_;
        } while (temp != ptr_dll->head_);
    }
    printf("\n");
}

/* Display from right to left */
void disp_backward(dll_t *ptr_dll)
{
    printf("Backward: ");
    if (ptr_dll->head_ != NULL) {
        node_t *last = ptr_dll->head_->prev_;
        node_t *temp = last;
        do {
            if (temp == ptr_dll->cur_)
                printf("[%d] ", temp->key_);
            else
                printf("%d ", temp->key_);
            temp = temp->prev_;
        } while (temp != last);
    }
    printf("\n");
}


/* Insert after a given value */
// insert key2 after key1
void insert_after(dll_t *ptr_dll, int key1, int key2)
{
    node_t *pres = find_node(ptr_dll, key1);

    if (pres == NULL) {
        printf("Key not found\n");
        return;
    }

    link_before(pres->next_, create_node(key2));
}


/* Delete from beginning */
void delete_begin(dll_t *ptr_dll)
{
    if (ptr_dll->head_ == NULL) {
        printf("List is empty\n");
        return;
    }
    remove_node(ptr_dll, ptr_dll->head_);
}

/* Delete from end */
void delete_end(dll_t *ptr_dll)
{
    if (ptr_dll->head_ == NULL) {
        printf("List is empty\n");
        return;
    }
    remove_node(ptr_dll, ptr_dll->head_->prev_);
}

/* Delete a node containing a given value */
void delete_value(dll_t *ptr_dll, int key)
{
    node_t *temp = find_node(ptr_dll, key);

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }
    remove_node(ptr_dll, temp);
}

void delete_cur(dll_t *ptr_dll)
{
    if (ptr_dll->cur_ == NULL) {
        printf("List is empty\n");
        return;
    }
    remove_node(ptr_dll, ptr_dll->cur_);
}

void move_next(dll_t *ptr_dll)
{
    if (ptr_dll->cur_ == NULL) {
        printf("List is empty\n");
        return;
    }
    ptr_dll->cur_ = ptr_dll->cur_->next_;
}

void move_prev(dll_t *ptr_dll)
{
    if (ptr_dll->cur_ == NULL) {
        printf("List is empty\n");
        return;
    }
    ptr_dll->cur_ = ptr_dll->cur_->prev_;
}
