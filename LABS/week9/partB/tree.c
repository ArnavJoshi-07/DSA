#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"
// node functions 
static void disp_recursive(tree_node_t* temp)
{
	if(temp)
	{
		disp_recursive(temp->left_);
		printf("%d ", temp->key_);
		disp_recursive(temp->right_);
	}
}

static tree_node_t* insert_recursive(tree_node_t* root, tree_node_t* temp)
{
	if(root == NULL)
	{
		root = temp;
	}
	else if(root->key_ > temp->key_)
	{
		root->left_ = insert_recursive(root->left_, temp);
	}
	else 
	{
		root->right_ = insert_recursive(root->right_, temp);
	}
	return root;
}

static void deinit_recursive(tree_node_t* root)
{
	if(root)
	{
		deinit_recursive(root->left_);
		deinit_recursive(root->right_);
		free(root);
	}
}
// helpers for disp_tree 
static int height_recursive(tree_node_t* root)
{
	if(root == NULL)
	{
		return 0;
	}
	int l = height_recursive(root->left_);
	int r = height_recursive(root->right_);
	return 1 + (l > r ? l : r);
}

static int count_recursive(tree_node_t* root)
{
	if(root == NULL)
	{
		return 0;
	}
	return 1 + count_recursive(root->left_) + count_recursive(root->right_);
}

static int max_width_recursive(tree_node_t* root)
{
	if(root == NULL)
	{
		return 0;
	}
	char buf[12];
	int w = sprintf(buf, "%d", root->key_);
	int l = max_width_recursive(root->left_);
	int r = max_width_recursive(root->right_);
	if(l > w)
	{
		w = l;
	}
	if(r > w)
	{
		w = r;
	}
	return w;
}

struct canvas
{
	char **grid_;	// rows_ x cols_ characters
	int rows_;
	int cols_;
	int width_;	// cell width
	int next_;	// inorder position of the next node to place
};
typedef struct canvas canvas_t;

// inorder walk : row = 2 * depth, column = inorder position * cell width
// returns the column of root, -1 if empty
static int place(tree_node_t* root, int depth, canvas_t* cv)
{
	if(root == NULL)
	{
		return -1;
	}
	int left = place(root->left_, depth + 1, cv);

	int col = cv->next_++ * cv->width_;
	char buf[12];
	int len = sprintf(buf, "%d", root->key_);
	for(int i = 0; i < len; ++i)
	{
		cv->grid_[2 * depth][col + i] = buf[i];
	}

	int right = place(root->right_, depth + 1, cv);

	// branch row : '-' between the children, '+' at the parent and child columns
	if(left != -1 || right != -1)
	{
		char *row = cv->grid_[2 * depth + 1];
		int from = (left != -1) ? left : col;
		int to = (right != -1) ? right : col;
		for(int c = from; c <= to; ++c)
		{
			row[c] = '-';
		}
		row[from] = row[col] = row[to] = '+';
	}
	return col;
}
// tree functions 
void init(tree_t *ptr_tree)
{
	ptr_tree->root_ = NULL;
}
void deinit(tree_t *ptr_tree)
{
	deinit_recursive(ptr_tree->root_);
	ptr_tree->root_ = NULL;
}
void disp(tree_t *ptr_tree)
{
	printf("Inorder     : ");
	disp_recursive(ptr_tree->root_);
	printf("\n");
}
void insert(tree_t *ptr_tree, int key)
{
	tree_node_t *temp = (tree_node_t*)malloc(sizeof(tree_node_t));
	temp->key_ = key;
	temp->left_ = temp->right_ = NULL;
	ptr_tree->root_ = insert_recursive(ptr_tree->root_, temp);
}
void level_order(tree_t *ptr_tree)
{
	queue_t q;
	init_queue(&q);

	printf("Level order : ");
	enqueue(&q, ptr_tree->root_);			// push the root
	while(! is_empty(&q))				// queue not empty
	{
		tree_node_t* temp = dequeue(&q);	// dequeue a node
		if(temp != NULL)
		{
			printf("%d ", temp->key_);	// display the node
			enqueue(&q, temp->left_);	// left subtree
			enqueue(&q, temp->right_);	// right subtree
		}
	}
	printf("\n");
	deinit_queue(&q);
}
void level_order_lines(tree_t *ptr_tree)
{
	if(ptr_tree->root_ == NULL) { printf("(empty tree)\n"); return; }

	queue_t q;  init_queue(&q);
	enqueue(&q, ptr_tree->root_);
	int cur = 1, next = 0, level = 0, printed = 0;

	while(! is_empty(&q))
	{
		tree_node_t* temp = dequeue(&q);
		--cur;
		if(temp != NULL)
		{
			if(printed == 0) printf("  Level %d : ", level);
			printf("%4d", temp->key_);		// fixed width = spacing
			++printed;
			enqueue(&q, temp->left_);
			enqueue(&q, temp->right_);
			next += 2;
		}
		if(cur == 0)				// one level finished
		{
			if(printed != 0)
			{
				printf("\n");
				++level;
			}
			cur = next; next = 0; printed = 0;
		}
	}
	deinit_queue(&q);
}
void disp_tree(tree_t *ptr_tree)
{
	if(ptr_tree->root_ == NULL)
	{
		printf("(empty tree)\n");
		return;
	}
	canvas_t cv;
	cv.width_ = max_width_recursive(ptr_tree->root_) + 2;
	cv.rows_ = 2 * height_recursive(ptr_tree->root_) - 1;
	cv.cols_ = count_recursive(ptr_tree->root_) * cv.width_;
	cv.next_ = 0;
	cv.grid_ = (char**)malloc(cv.rows_ * sizeof(char*));
	for(int r = 0; r < cv.rows_; ++r)
	{
		cv.grid_[r] = (char*)malloc(cv.cols_);
		for(int c = 0; c < cv.cols_; ++c)
		{
			cv.grid_[r][c] = ' ';
		}
	}

	place(ptr_tree->root_, 0, &cv);

	for(int r = 0; r < cv.rows_; ++r)
	{
		int len = cv.cols_;
		while(len > 0 && cv.grid_[r][len - 1] == ' ')	// trim trailing spaces
		{
			--len;
		}
		printf("  ");
		for(int c = 0; c < len; ++c)
		{
			putchar(cv.grid_[r][c]);
		}
		printf("\n");
		free(cv.grid_[r]);
	}
	free(cv.grid_);
}
