#ifndef sll_h
#define sll_h

typedef struct node {
    int key;
    struct node *next;
}node_t;

typedef struct sll{
    node_t *head;
}sll_t;

void init_list(sll_t *ptr_list);
void insert_list(sll_t *, int);
void disp_list(sll_t *);
void freelist(sll_t *);
#endif