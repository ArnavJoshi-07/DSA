#ifndef TREE_H
#define TREE_H
#define MAXSIZE 100

typedef struct node{
    int key;
    int left;
    int right;
}node_t;

typedef struct tree{
    node_t elem[MAXSIZE];
    int root;
    int count;
}tree_t;

void insert(tree_t *ptr, int key);
void init(tree_t *);
void display(tree_t* );
void deinit(tree_t *);

int num_nodes(tree_t *);
int num_leaves(tree_t *);

//adding

void copy(tree_t *, tree_t *);
int compare(tree_t *, tree_t*);

#endif
