#ifndef JOB_H
#define JOB_H
#define NAME_LEN 20
struct job {
    int id_;
    char name_[NAME_LEN];
};
typedef struct job job_t;
void set_job(job_t *ptr_job, int id, const char *name);
void disp_job(const job_t *ptr_job);

#endif
