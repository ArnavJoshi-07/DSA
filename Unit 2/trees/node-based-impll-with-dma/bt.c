typedef struct node{
    int key;
    struct node* left;
    struct node* right;
}node_t;

typedef struct tree{
    node_t * root;
}tree_t;

