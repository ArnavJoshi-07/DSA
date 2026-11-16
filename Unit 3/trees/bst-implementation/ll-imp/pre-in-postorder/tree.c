#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void init(tree_t *ptr){
    ptr->root = NULL;
}

static void deinit_recursive(node_t *root){
    if(root){
        deinit_recursive(root->left);
        deinit_recursive(root->right);
        free(root);
    }
}
void deinit(tree_t *ptr){
    deinit_recursive(ptr->root);
    ptr->root = NULL;
}

static void disp_in_recursive(node_t *root){
    if(root){
        disp_in_recursive(root->left);
        printf("%d ",root->key);
        disp_in_recursive(root->right);
    }
}

static void disp_pre_recursive(node_t *root){
    if(root){
        printf("%d ",root->key);
        disp_pre_recursive(root->left);
        disp_pre_recursive(root->right);
    }
}

static void disp_post_recursive(node_t *root){
    if(root){
        disp_post_recursive(root->left);
        disp_post_recursive(root->right);
        printf("%d ", root->key);
    }
}

void disp_in(tree_t *ptr){
    printf("TREE: ");
    disp_in_recursive(ptr->root);
    printf("\n");
}

void disp_pre(tree_t *ptr){
    printf("TREE: ");
    disp_pre_recursive(ptr->root);
    printf("\n");
}


void disp_post(tree_t *ptr){
    printf("TREE: ");
    disp_post_recursive(ptr->root);
    printf("\n");
}

static node_t* insert_recursive(node_t *root, node_t* temp){
    if(root == NULL){
        root = temp;
    }
    else if(root->key > temp->key){
        root->left = insert_recursive(root->left, temp);
    }
    else if (root->key < temp->key){
        root->right = insert_recursive(root->right, temp);
    }
    return root;
}

void insert(tree_t *ptr, int key){
    node_t *temp;
    temp = malloc(sizeof(node_t));
    temp->key = key;
    temp->left = temp->right = NULL;
    ptr->root = insert_recursive(ptr->root, temp);
}

static int num_nodes_recursive(node_t *root){
    if(root == NULL) return 0;
    else{
        return 1 + num_nodes_recursive(root->left) + num_nodes_recursive(root->right);
    }
}

static int num_leaves_recursive(node_t *root){
    if(root==NULL) return 0;
    else if(root->left == NULL && root->right == NULL){
        return 1;
    }
    else if(root->left == NULL || root->right == NULL){
        return 0;
    }
    else{
        return num_leaves_recursive(root->left) + num_leaves_recursive(root->right);
    }
}

int num_nodes(tree_t *ptr){
    return num_nodes_recursive(ptr->root);
}

int num_leaves(tree_t *ptr){
    return num_leaves_recursive(ptr->root);
}

static node_t * inorder_successor(node_t *root){
    node_t *temp = root;
    while(temp!=NULL){
        temp = temp->left;
    }
    return temp;
}

static node_t * delete_key_recursive(node_t *root, int key){
    if(root == NULL) return root;
    else if(key<root->key){
        root->left = delete_key_recursive(root->left, key);
    }
    else if(key>root->key){
        root->right = delete_key_recursive(root->right, key);
    }
    else{
        //key match scenario

        if(root->left == NULL && root->right == NULL){
            //leaf
            free(root);return NULL;
        }
        else if(root->left == NULL){
            //no left subtree
            node_t *temp = root->right;
            free(root);return temp;
        }
        else if(root->right == NULL){
            //no right subtree
            node_t *temp = root->left;
            free(root);return temp;
        }
        else{
            //both subtrees are present

            node_t *temp = inorder_successor(root);
            root->key = temp->key;
            root->right = delete_key_recursive(root->right, temp->key);
        }
    }
}

void delete_key(tree_t *ptr, int key){
    ptr->root = delete_key_recursive(ptr->root, key);
}


