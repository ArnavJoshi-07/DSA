#ifndef CLIST_H
#define CLIST_H

#define NAME_LEN 32

struct node
{
    int key_;
    char name_[NAME_LEN];
    struct node *next_;
};
typedef struct node node_t;

struct clist
{
    node_t *head_;
};
typedef struct clist clist_t;

void init_clist(clist_t *ptr_clist);
void insert_end(clist_t *ptr_clist, int key, const char *name);
node_t *last_node(clist_t *ptr_clist);

/* Unlinks the node after cur and returns it; the caller frees it */
node_t *remove_after(clist_t *ptr_clist, node_t *cur);

void disp_list(clist_t *ptr_clist);
void free_clist(clist_t *ptr_clist);

#endif
