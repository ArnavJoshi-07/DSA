#include <stdio.h>
#include <string.h>
#include "job.h"

void set_job(job_t *ptr_job, int id, const char *name)
{
    ptr_job->id_ = id;
    strncpy(ptr_job->name_, name, NAME_LEN - 1);
    ptr_job->name_[NAME_LEN - 1] = '\0';
}

void disp_job(const job_t *ptr_job)
{
    printf("(%d, %s)", ptr_job->id_, ptr_job->name_);
}
