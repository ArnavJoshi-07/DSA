#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void init_queue(queue_t *ptr){
    ptr->front = ptr->rear = NULL;
}
void deinit_queue(queue_t *ptr){
    while(!is_empty(ptr)) dequeue(ptr);
    ptr->front = ptr->rear = NULL;
}
void enqueue(queue_t *ptr, int key){
    if(!is_full(ptr)){
    node_t *temp = malloc(sizeof(node_t));
    temp->key = key;
    temp->next = NULL;
    if(ptr->rear == NULL) ptr->front = temp;
    else{
        ptr->rear->next = temp;
    }
    ptr->rear = temp;
    }
    else{
        printf("Queue full, cannot push\n");exit(1);
    }
}
int dequeue(queue_t *ptr){
    if(!is_empty(ptr)){
        node_t *temp = ptr->front;
        int key = temp->key;
        ptr->front= temp->next;
        if(ptr->front ==NULL){
            ptr->rear = NULL;
        }
        free(temp);return key;
        
    }
    else{printf("Queue empty\n"); exit(1);}
}
int is_empty(queue_t *ptr){
    return ptr->front == NULL;
}
int is_full(queue_t *ptr){
    node_t *temp = malloc(sizeof(node_t));
    if(temp==NULL) return 1;
    free(temp);
    return 0;
}