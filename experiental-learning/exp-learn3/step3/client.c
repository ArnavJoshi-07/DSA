#include <stdio.h>
#include "heap.h"

// comparison functions
int max(int x, int y) { return x > y; }
int min(int x, int y) { return x < y; }

// left  : max heap - smaller half; root is the largest of the smaller half
// right : min heap - larger half;  root is the smallest of the larger half
void add_number(heap_t *left, heap_t *right, int x)
{
	// 1. insert
	if(left->n_ == 0 || x <= peek_max(left))
	{
		insert(left, x);
	}
	else
	{
		insert(right, x);
	}

	// 2. balance
	if(left->n_ > right->n_ + 1)
	{
		insert(right, delete_max(left));
	}
	else if(right->n_ > left->n_)
	{
		insert(left, delete_max(right));
	}
}

// 3. query median
void disp_median(heap_t *left, heap_t *right)
{
	if((left->n_ + right->n_) % 2 == 0)
	{
		printf("median : %.1f\n", (peek_max(left) + peek_max(right)) / 2.0);
	}
	else
	{
		// after balancing, left always has the extra element
		printf("median : %d\n", peek_max(left));
	}
}

int main()
{
	heap_t left;
	heap_t right;
	init(&left, max);
	init(&right, min);

	int n;
	int x;
	printf("number of elements : ");
	scanf("%d", &n);
	printf("enter %d numbers : ", n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &x);
		add_number(&left, &right, x);
		printf("after %d -> ", x);
		disp_median(&left, &right);
	}
	deinit(&left);
	deinit(&right);
}
