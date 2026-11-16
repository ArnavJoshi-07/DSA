#ifndef TREE_H
#define TREE_H

typedef struct node{
    int key;
    struct node *left;
    struct node *right;
}node_t;

typedef struct tree{
    node_t *root;
}tree_t;

void init(tree_t *);
void deinit(tree_t *);
void disp_in(tree_t*);
void disp_pre(tree_t *);
void disp_post(tree_t *);

void insert(tree_t *, int);
void delete_key(tree_t*, int);

int num_nodes(tree_t *);
int num_leaves(tree_t *);
#endif