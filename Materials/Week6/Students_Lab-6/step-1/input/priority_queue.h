#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include "job.h"
// implementing using an unordered list 
struct node
{
	job_t job_;
	struct node *next_;
};

typedef struct node node_t;

struct priority_queue
{
	node_t* rear_;
	node_t* front_;
};
typedef struct priority_queue priority_queue_t;

void init(priority_queue_t* ptr_queue);
void deinit(priority_queue_t* ptr_queue);

void enqueue(priority_queue_t* ptr_queue, job_t job);
job_t dequeue(priority_queue_t* ptr_queue);

int is_empty(priority_queue_t* ptr_queue);
int is_full(priority_queue_t* ptr_queue);


#endif
