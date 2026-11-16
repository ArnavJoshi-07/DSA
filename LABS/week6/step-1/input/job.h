#ifndef JOB_H
#define JOB_H
struct job 
{
	int job_no_;
	int priority_;
	int depth_;
};
typedef struct job job_t;
void set(job_t* ptr_job, int job_no, int priority, int depth);
void disp(job_t* ptr_job);
int get_priority(job_t* ptr_job);
#endif
