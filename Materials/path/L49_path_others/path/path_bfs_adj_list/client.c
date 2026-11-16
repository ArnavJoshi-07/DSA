#include <stdio.h>
#include "graph.h" 
/*
Component 1: (0,1), (1,2), (2,0)
Component 2: (3,4), (4,5), (5,6), (6,3), (3,5)
Component 3: (7,8), (8,9), (9,10), (10,11), (11,7), (7,9)
*/ 
int main()
{
	#if 0
	int n_edge = 14;
	int n_vertex = 12;
	int e[][2] = {{0, 1}, {1, 2}, {2, 0},
		{3, 4}, {4, 5}, {5, 6}, {6, 3}, {3, 5},
			{7, 8}, {8, 9}, {9, 10}, {10, 11}, {11, 7}, {7, 9}
	};
	#endif
	int n_edge = 6;
	int n_vertex = 7;
	int e[][2] = {{0, 1}, {1, 2}, {2, 3},
		{3, 4}, {4, 5}, {5, 6}
	};
	graph_t g;
	init_graph(&g, n_vertex, n_edge);
	
	for(int i = 0; i < n_edge; ++i)
	{
		printf("%d->%d\n", e[i][0] , e[i][1] );
		add_edge(&g, e[i][0], e[i][1]);
	}
	printf("disp:\n");
	disp(&g);
	
	int path[12];
	int len = 0;
	int from; int to;
	printf("Enter two vertices : ");
	scanf("%d %d", &from, &to);
	int found = find_path(&g, path, &len, from, to);
	if(found)
	{
		for(int i = 0; i < len; ++i)
		{
			printf("%d ", path[i]);
		}
		printf("\n");
	}
	else 
	{
		printf("no path\n");
	}
} 
