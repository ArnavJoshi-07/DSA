#include <stdio.h>
#include <string.h>
#include "job.h"

void set_job(job_t *ptr_job, int id, const char *name, int time_needed)
{
    ptr_job->id_ = id;
    strncpy(ptr_job->name_, name, NAME_LEN - 1);
    ptr_job->name_[NAME_LEN - 1] = '\0';
    ptr_job->time_needed_ = time_needed;
    ptr_job->time_allotted_ = 0;
}

void disp_job(const job_t *ptr_job)
{
    printf("(%d, %s, %d/%d)", ptr_job->id_, ptr_job->name_,
           ptr_job->time_allotted_, ptr_job->time_needed_);
}

void allot_time(job_t *ptr_job, int slice)
{
    ptr_job->time_allotted_ += slice;
}

int is_complete(const job_t *ptr_job)
{
    return ptr_job->time_allotted_ >= ptr_job->time_needed_;
}
