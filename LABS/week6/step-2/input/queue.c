#include"queue.h"

void q_init(queue* q) {
	init(&q->deq);
}

void q_deinit(queue* q) {
	deinit(&q->deq);
}

void enqueue(queue* q, int v) {
	add_at_end(&q->deq,v);	
}

int dequeue(queue* q) {
	return remove_in_begin(&q->deq);	
}

void q_print(queue* q) {
	disp_forward(&q->deq);
}

