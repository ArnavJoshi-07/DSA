#ifndef dll_h
#define dll_h
typedef struct node{
    int key;
    struct node *llink;
    struct node *rlink;
}node_t;

typedef struct{
    node_t *head;
}dll_t;



void init_list(dll_t *);
void insert_begin(dll_t *, int);
void insert_end(dll_t *, int);
void delete_begin(dll_t *);
void delete_end(dll_t *);
void delete_val(dll_t *, int);
void disp_fwd(dll_t *);
void disp_bwd(dll_t *);
#endif