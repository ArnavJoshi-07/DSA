#ifndef JOB_H
#define JOB_H
#define NAME_LEN 20
struct job {
    int id_;
    char name_[NAME_LEN];
    int time_needed_;
    int time_allotted_;
};
typedef struct job job_t;
void set_job(job_t *ptr_job, int id, const char *name, int time_needed);
void disp_job(const job_t *ptr_job);
void allot_time(job_t *ptr_job, int slice);
int is_complete(const job_t *ptr_job);

#endif
