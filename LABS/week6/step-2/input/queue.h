#ifndef QUEUE_H
#define QUEUE_H
#include"dll.h"

typedef struct queue {
	dll_t deq;
}queue;

void q_init(queue* q);
void q_deinit(queue* q);
void enqueue(queue* q, int v);
int dequeue(queue* q);
void q_print(queue* q);
#endif
