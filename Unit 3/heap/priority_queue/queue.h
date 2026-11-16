#ifndef QUEUE_H
#define QUEUE_H
#include "heap.h"

typedef struct queue{
    heap_t *q;
}queue_t;

void init_queue(queue_t *ptr);
void deinit_queue(queue_t *ptr);
void enqueue(queue_t *ptr, int key);
int dequeue(queue_t *ptr);

int is_empty(queue_t *ptr);
int is_full(queue_t *ptr);
#endif