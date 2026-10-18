#ifndef DLL_H
#define DLL_H
#include "job.h"
struct node {
    job_t key_;
    struct node *prev_;
    struct node *next_;
};
typedef struct node node_t;

struct DLL {
    node_t *head_;
    node_t *cur_;
};
typedef struct DLL dll_t;
void init_dll(dll_t *ptr_dll);
void deinit_dll(dll_t *ptr_dll);
void insert_begin(dll_t *ptr_dll, job_t key);
void insert_end(dll_t *ptr_dll, job_t key);
void disp_forward(dll_t *ptr_dll);
void disp_backward(dll_t *ptr_dll);
void insert_after(dll_t *ptr_dll, int id, job_t key);
void delete_begin(dll_t *ptr_dll);
void delete_end(dll_t *ptr_dll);
void delete_value(dll_t *ptr_dll, int id);
void insert_before_cur(dll_t *ptr_dll, job_t key);
void delete_cur(dll_t *ptr_dll);
void move_next(dll_t *ptr_dll);
void move_prev(dll_t *ptr_dll);
job_t* get_cur(dll_t *ptr_dll);

#endif
