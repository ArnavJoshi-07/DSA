#ifndef TREE_H
#define TREE_H
#include "stack.h" // MAXSIZE : one stack slot for every array index

struct node
{
	int key_;
	int left_;
	int right_;
};
typedef struct node node_t;

struct tree 
{
	int root_; // -1 on empty
	int count_; // # of elem 
	node_t elem_[MAXSIZE];
	stack_t stack_; // memory manager : free indices
};
typedef struct tree tree_t;

void init(tree_t *ptr_tree);
void insert(tree_t *ptr_tree, int key);
void disp(tree_t *ptr_tree);
// add 
int delete_key(tree_t* ptr_tree, int key);

#endif