#include <stdio.h>
#include "graph.h" 
// E ={AB,AC,BC,BD,CE,DE,DF, EG,FG,FH,GH} 
int main()
{
	graph_t g;
	int n_edge = 14;
	int n_vertex = 12;
	init_graph(&g, n_vertex, n_edge);
	int e[][2] = {{0, 1}, {1, 2}, {2, 0},
		{3, 4}, {4, 5}, {5, 6}, {6, 3}, {3, 5},
			{7, 8}, {8, 9}, {9, 10}, {10, 11}, {11, 7}, {7, 9}
	};
	//disp(&g);
	
	for(int i = 0; i < n_edge; ++i)
	{
	//	printf("%d->%d\n", e[i][0], e[i][1] );
		add_edge(&g, e[i][0], e[i][1]);
	}
	//printf("disp:\n");
	//disp(&g);
	int count = connected_components(&g);
	printf("# of components : %d\n", count);
} 
