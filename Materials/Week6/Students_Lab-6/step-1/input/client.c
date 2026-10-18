#include <stdio.h>
#include "priority_queue.h"

int main()
{
	priority_queue_t q;
	job_t job;
	int job_no = 1;
	int priority;
	init(&q);
	int opt;
	printf("1. enqueue 2. dequeue 0. exit : ");
	scanf("%d", &opt);
	while(opt)
	{
		switch(opt)
		{
			case 1 : printf("Enter priority : ");
					 scanf("%d", &priority);
					 set(&job, job_no++, priority);
					 enqueue(&q, job);
					 break;
					 
			case 2 : job = dequeue(&q);
					 disp(&job);
					 break;
		}
		printf("1. enqueue 2. dequeue 0. exit : ");
		scanf("%d", &opt);
	}
	
	deinit(&q);
}