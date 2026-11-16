#include <stdio.h>
#include "tree.h"

int main()
{
	// case 1
	tree_t t1;
	init(&t1);
		int a1[] = {40, 20, 60, 10, 70, 30, 50};
	int n1 = 7;
	for(int i = 0; i < n1; ++i)
	{
		insert(&t1, a1[i]);
	}
	disp(&t1);
	level_order(&t1);
	level_order_lines(&t1);
	disp_tree(&t1);
	deinit(&t1);
	
	// case 2
	tree_t t2;
	init(&t2);
	
	int a2[] = {10, 20, 30, 40, 50, 60, 70};
	int n2 = 7;
	for(int i = 0; i < n2; ++i)
	{
		insert(&t2, a2[i]);
	}
	disp(&t2);	
	level_order(&t2);
	level_order_lines(&t2);
	disp_tree(&t2);
	deinit(&t2);
	
	// case 3
	tree_t t3;
	init(&t3);
	disp(&t3);	
	level_order(&t3);
	level_order_lines(&t3);
	disp_tree(&t3);
	deinit(&t3);
	
	// case 4
	tree_t t4;
	init(&t4);
	
	int a4[] = {50, 30, 70, 20, 40, 60, 80, 35, 45, 65, 5, 100};
	int n4 = 12;
	for(int i = 0; i < n4; ++i)
	{
		insert(&t4, a4[i]);
	}
	disp(&t4);
	level_order(&t4);
	level_order_lines(&t4);
	disp_tree(&t4);
	deinit(&t4);

}