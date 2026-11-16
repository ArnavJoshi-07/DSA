#include <stdio.h>
#include "job.h"

void set(job_t* ptr_job, int job_no, int priority, int depth)
{
	ptr_job->job_no_ = job_no;
	ptr_job->priority_ = priority;
	ptr_job->depth_ = depth;
}
void disp(job_t* ptr_job)
{
	printf("job # : %d depth: %d, traffic: %d, priority : %d\n",
		ptr_job->job_no_, ptr_job->depth_, ptr_job->priority_ - ptr_job->depth_, ptr_job->priority_);
}
int get_priority(job_t* ptr_job)
{
	return ptr_job->priority_;
}
