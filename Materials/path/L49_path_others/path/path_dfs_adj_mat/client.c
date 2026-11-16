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
	graph_t g;
	int n_edge = 14;
	int n_vertex = 12;
	init_graph(&g, n_vertex, n_edge);
	int e[][2] = {{0, 1}, {1, 2}, {2, 0},
		{3, 4}, {4, 5}, {5, 6}, {6, 3}, {3, 5},
			{7, 8}, {8, 9}, {9, 10}, {10, 11}, {11, 7}, {7, 9}
	};
	for(int i = 0; i < n_edge; ++i)
	{
		printf("%d->%d\n", e[i][0] , e[i][1] );
		add_edge(&g, e[i][0], e[i][1]);
	}
	#endif
	#if 1
	graph_t g;
	int n_edge = 6;
	int n_vertex = 7;
	init_graph(&g, n_vertex, n_edge);
	int e[][2] = {{0, 1}, {1, 2}, {2, 3},
		{3, 4}, {4, 5}, {5, 6}
	};
	for(int i = 0; i < n_edge; ++i)
	{
		add_edge(&g, e[i][0], e[i][1]);
	}
	#endif
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
