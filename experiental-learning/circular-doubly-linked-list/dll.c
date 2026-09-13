#include <stdio.h>
#include <stdlib.h>
#include "dll.h"


void init_dll(dll_t *ptr_dll)
{
	ptr_dll->current_= NULL;
}

void deinit_dll(dll_t *ptr_dll)
{
	node_t* pres = ptr_dll->current_;
	if (pres==NULL){
        return;
    }
    do
	{
		node_t* temp = pres;
		pres = pres->next_;
		free(temp);
	}while(pres!=ptr_dll->current_);
	ptr_dll->current_= NULL;
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

    return temp;
}

/*add at current position*/
void add_current(dll_t *ptr_dll,int key){
    node_t *temp = create_node(key);
    if(ptr_dll->current_ == NULL){
        temp->next_ = temp;
        temp->prev_ = temp;
    }
    else{
        temp->next_ = ptr_dll->current_;
        temp->prev_ = ptr_dll->current_->prev_;
        temp->next_->prev_ = temp;
        temp->prev_->next_ = temp;
    }
}
/* Display from left to right */
void disp_forward(dll_t *ptr_dll)
{
    node_t *temp = ptr_dll->head_;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->key_);
        temp = temp->next_;
    }
    printf("\n");
}

/* Display from right to left */
void disp_backward(dll_t *ptr_dll)
{
    node_t *temp = ptr_dll->tail_;
    printf("Backward: ");
    while (temp != NULL) {
        printf("%d ", temp->key_);
        temp = temp->prev_;
    }
    printf("\n");
}




/* Insert after a given value */
// insert key2 after key1
void insert_after(dll_t *ptr_dll, int key1, int key2)
{
    node_t *pres = ptr_dll->head_;

    while (pres != NULL && pres->key_ != key1)
        pres = pres->next_;

    if (pres == NULL) {
        printf("Key not found\n");
        return;
    }

    node_t* temp = create_node(key2);

    temp->next_ = pres->next_;
    temp->prev_ = pres;
	
	if(pres->next_ == NULL)
		ptr_dll->tail_ = temp;
	else
		pres->next_->prev_ = temp;
	pres->next_ = temp;
	
}


/* Delete from beginning */
void delete_begin(dll_t *ptr_dll)
{
    node_t *temp = ptr_dll->head_;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
	ptr_dll->head_ = temp->next_;
	if(ptr_dll->head_ == NULL)
		ptr_dll->tail_ = NULL;
	else 
		ptr_dll->head_->prev_ = NULL;
		
    free(temp);
}

/* Delete from end */
void delete_end(dll_t *ptr_dll)
{
    node_t *temp = ptr_dll->tail_;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
	ptr_dll->tail_ = temp->prev_;
	if(ptr_dll->tail_ == NULL)
		ptr_dll->head_ = NULL;
 	else
		ptr_dll->tail_->next_ = NULL;
	free(temp);
}

/* Delete a node containing a given value */
void delete_value(dll_t *ptr_dll, int key)
{
    node_t *temp = ptr_dll->head_;

    while (temp != NULL && temp->key_ != key)
        temp = temp->next_;

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    if (temp->prev_ != NULL)
        temp->prev_->next_ = temp->next_;
    else
        ptr_dll->head_ = temp->next_;

    if (temp->next_ != NULL)
        temp->next_->prev_ = temp->prev_;
	else 
		ptr_dll->tail_ = temp->prev_;
	

    free(temp);
}


