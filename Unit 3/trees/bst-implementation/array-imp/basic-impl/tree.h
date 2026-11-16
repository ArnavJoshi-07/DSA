#ifndef TREE_H
#define TREE_H
#define MAXSIZE 100

struct node{
    int key;
    int left;
    int right;
};
typedef struct node node_t;

struct tree{
    int root;
    int count;
    node_t elem[MAXSIZE];
};
typedef struct tree tree_t;

void init(tree_t *ptr);
void deinit(tree_t *pre);
void display(tree_t *ptr);
void insert(tree_t*, int);

#endif