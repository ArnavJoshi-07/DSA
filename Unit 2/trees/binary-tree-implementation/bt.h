#ifndef BT_H
#define BT_H

typedef struct node{
    int key;
    struct node *left;
    struct node *right;
}node_t;

typedef struct tree{
    node_t *root;
}tree_t;

void init_tree(tree_t *ptr);
void destroy_tree(tree_t *ptr);//following postorder traversal for deleting tree
//delete left -> delete right -> delete root
void insert_tree(tree_t *ptr, int key);
void disp_inorder(tree_t *ptr); // use inorder traversal jugsss
int num_nodes(tree_t *ptr);
int num_leaves(tree_t *ptr);

#endif

