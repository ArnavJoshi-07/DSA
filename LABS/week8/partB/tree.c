#include <stdio.h>
#include <stdlib.h>
#include "tree.h" 

void init(tree_t *ptr_tree)
{
	ptr_tree->root_ = -1;
	ptr_tree->count_ = 0;
	// every index is free; pushed in reverse so index 0 is allocated first
	init_stack(&ptr_tree->stack_);
	for(int i = MAXSIZE - 1; i >= 0; --i)
	{
		push(&ptr_tree->stack_, i);
	}
}

int insert_recursive(node_t elem[], int root, int temp)
{
	if(root == -1)
	{
		root = temp;
	}
	else if(elem[root].key_ > elem[temp].key_)
	{
		elem[root].left_ = insert_recursive(elem, elem[root].left_, temp);
	}
	else
	{
		elem[root].right_ = insert_recursive(elem, elem[root].right_, temp);
	}
	return root;
}
void insert(tree_t *ptr_tree, int key)
{
	// pop the stack to get the location
	int temp = pop(&ptr_tree->stack_);
	if(temp == -1)
	{
		printf("tree full; %d not inserted\n", key);
		return;
	}
	++ptr_tree->count_;

	ptr_tree->elem_[temp].key_ = key;
	ptr_tree->elem_[temp].left_ = ptr_tree->elem_[temp].right_ = -1;
	ptr_tree->root_ = insert_recursive(ptr_tree->elem_, ptr_tree->root_, temp);
	printf("%d stored at index %d\n", key, temp);
}

void disp_recursive(node_t elem[], int temp)
{
		if(temp != -1)
		{
			disp_recursive(elem, elem[temp].left_);
			printf("%d ", elem[temp].key_);
			disp_recursive(elem, elem[temp].right_);
		}
		
}


void disp(tree_t *ptr_tree)
{
	disp_recursive(ptr_tree->elem_, ptr_tree->root_); 
	printf("\n\n");
}

// release a node : push its index back on the stack (replaces free)
void free_node(tree_t *ptr_tree, int index)
{
	push(&ptr_tree->stack_, index);
	--ptr_tree->count_;
	printf("index %d freed\n", index);
}

// leftmost node of the right subtree
int inorder_successor(node_t elem[], int root)
{
	int temp = elem[root].right_;
	while(elem[temp].left_ != -1)
	{
		temp = elem[temp].left_;
	}
	return temp;
}

int delete_key_recursive(tree_t *ptr_tree, int root, int key)
{
	node_t *elem = ptr_tree->elem_;
	// locate the key
	// 1. empty tree 
	if(root == -1)
	{
		return -1;
	}
	// 2. in left subtree?
	else if(key < elem[root].key_)
	{
		elem[root].left_ = delete_key_recursive(ptr_tree, elem[root].left_, key);
	}
	// 3. in right subtree?
	else if(key > elem[root].key_)
	{
		elem[root].right_ = delete_key_recursive(ptr_tree, elem[root].right_, key);
	}
	// 4. key found
	else 
	{
		// 1. leaf 
		if(elem[root].left_ == -1 && elem[root].right_ == -1)
		{
			free_node(ptr_tree, root);
			return -1;
		}
		// 2. no left subtree 
		else if(elem[root].left_ == -1)
		{
			int temp = elem[root].right_;
			free_node(ptr_tree, root);
			return temp;
		}
		// 3. no right subtree
		else if(elem[root].right_ == -1)
		{
			int temp = elem[root].left_;
			free_node(ptr_tree, root);
			return temp;
		}
		// 4. has both left and right subtrees
		else 
		{
			// find the inorder successor
			int temp = inorder_successor(elem, root);
			// replace root key 
			elem[root].key_ = elem[temp].key_;
			// delete elem[temp].key_ in the right subtree 
			elem[root].right_ = delete_key_recursive(ptr_tree, elem[root].right_, elem[temp].key_);
			return root;
		}
	}
	return root;
}


// returns 1 if the key was deleted, 0 if not found
int delete_key(tree_t *ptr_tree, int key)
{
	int count = ptr_tree->count_;
	ptr_tree->root_ = delete_key_recursive(ptr_tree, ptr_tree->root_, key);
	return ptr_tree->count_ < count;
}

// additional exercise
int count_nodes_recursive(node_t elem[], int root)
{
	if(root == -1)
	{
		return 0;
	}
	return 1 + count_nodes_recursive(elem, elem[root].left_) + count_nodes_recursive(elem, elem[root].right_);
}

int count_nodes(tree_t *ptr_tree)
{
	return count_nodes_recursive(ptr_tree->elem_, ptr_tree->root_);
}

int count_leaves_recursive(node_t elem[], int root)
{
	if(root == -1)
	{
		return 0;
	}
	if(elem[root].left_ == -1 && elem[root].right_ == -1)
	{
		return 1;
	}
	return count_leaves_recursive(elem, elem[root].left_) + count_leaves_recursive(elem, elem[root].right_);
}

int count_leaves(tree_t *ptr_tree)
{
	return count_leaves_recursive(ptr_tree->elem_, ptr_tree->root_);
}

// same shape and same keys; the array indices may differ
int compare_recursive(node_t elem1[], int root1, node_t elem2[], int root2)
{
	if(root1 == -1 && root2 == -1)
	{
		return 1;
	}
	if(root1 == -1 || root2 == -1)
	{
		return 0;
	}
	return elem1[root1].key_ == elem2[root2].key_
		&& compare_recursive(elem1, elem1[root1].left_, elem2, elem2[root2].left_)
		&& compare_recursive(elem1, elem1[root1].right_, elem2, elem2[root2].right_);
}

int compare_trees(tree_t *ptr_tree1, tree_t *ptr_tree2)
{
	return compare_recursive(ptr_tree1->elem_, ptr_tree1->root_, ptr_tree2->elem_, ptr_tree2->root_);
}

// every node of the copy is allocated from dst's own stack
int copy_recursive(tree_t *dst, node_t src_elem[], int src_root)
{
	if(src_root == -1)
	{
		return -1;
	}
	int temp = pop(&dst->stack_);
	++dst->count_;
	dst->elem_[temp].key_ = src_elem[src_root].key_;
	dst->elem_[temp].left_ = copy_recursive(dst, src_elem, src_elem[src_root].left_);
	dst->elem_[temp].right_ = copy_recursive(dst, src_elem, src_elem[src_root].right_);
	return temp;
}

void copy_tree(tree_t *dst, tree_t *src)
{
	init(dst);
	dst->root_ = copy_recursive(dst, src->elem_, src->root_);
}
