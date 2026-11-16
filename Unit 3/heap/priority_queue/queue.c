#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void init_queue(queue_t *ptr){
    init(&ptr->q);
}

void deinit_queue(queue_t *ptr){
    deinit(&ptr->q);
}


void enqueue(queue_t* ptr, int key){
    insert(&ptr->q, key);
}

int dequeue(queue_t *ptr){
    return delete_max(&ptr->q);
}

