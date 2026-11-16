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
void disp(tree_t *);
void insert(tree_t *, int);

int num_nodes(tree_t *);
int num_leaves(tree_t *);

void copy(tree_t*, tree_t *);
int compare(tree_t*, tree_t *);

#endif

