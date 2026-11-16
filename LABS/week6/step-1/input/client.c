#include <stdio.h>
#include "priority_queue.h"

int main()
{
	priority_queue_t q;
	job_t job;
	int job_no = 1;
	int depth;
	int traffic;
	init(&q);
	int opt;
	printf("----POTHOLE REPAIR PRIORITY QUEUE----\n");
	do {
		printf("1. enqueue 2. dequeue 3. display all pending jobs 0. exit : ");
		scanf("%d", &opt);
		switch(opt)
		{
			case 1 : printf("Enter depth : ");
				 scanf("%d", &depth);
				 printf("Enter traffic: ");
				 scanf("%d", &traffic);
				 set(&job, job_no++, traffic + depth, depth);
				 enqueue(&q, job);
				 break;

			case 2 : job = dequeue(&q);
				 disp(&job);
				 break;
			case 3: 
				printf("Job infos:\n");
				
				struct node* p = q.front_;
				for(;p != NULL; p = p->next_) {
					disp(&p->job_);
				}

		}
	} while(opt);
	
	deinit(&q);
}
