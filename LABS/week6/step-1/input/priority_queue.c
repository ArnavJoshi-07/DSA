#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

// most interesting and challenging routine is deque 
// let us complete the remaining first 


void init(priority_queue_t* ptr_queue)
{
	ptr_queue->front_ = NULL;
}

void deinit(priority_queue_t* ptr_queue)
{
	node_t *pres = ptr_queue->front_;
	while(pres != NULL)
	{
		node_t* temp = pres;
		pres = pres->next_;
		free(temp);
	}
	ptr_queue->front_ = NULL;
}

void enqueue(priority_queue_t* ptr_queue, job_t job)
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	if(temp == NULL)
	{
		printf("queue full\n"); exit(1);
	}
	temp->job_ = job; 
	temp->next_ = NULL;
	
	// 1. empty 
	if(ptr_queue->front_ == NULL)
	{
		ptr_queue->front_ = temp;
	}
	else 
	{
		// traverse to find the position
		node_t* prev = NULL;
		node_t* pres = ptr_queue->front_;
		while(pres != NULL && get_priority(&pres->job_) >=
			get_priority(&job))
		{
			prev = pres;
			pres = pres->next_;
		}
		// beginning 
		if(prev == NULL)
		{
			temp->next_ = ptr_queue->front_;
			ptr_queue->front_ = temp;
		}
		else // middle 
		{
			prev->next_ = temp;
			temp->next_ = pres;
		}
		
	}
	
	
	

}

job_t dequeue(priority_queue_t* ptr_queue)
{
	if(is_empty(ptr_queue))
	{
		printf("empty\n"); exit(1);
	}
	else 
	{
		node_t* temp = ptr_queue->front_;
		job_t job = temp->job_;
		
		ptr_queue->front_ = temp->next_;
		
		free(temp);
		return job;
	}
	
}

int is_empty(priority_queue_t* ptr_queue)
{
	return ptr_queue->front_ == NULL;
}
int is_full(priority_queue_t* ptr_queue)
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	free(temp);
	return temp == NULL;
}
