#include <stdio.h>
#include "graph.h" 
// E ={AB,AC,BC,BD,CE,DE,DF, EG,FG,FH,GH} 
int main()
{
	graph_t g;
	int n_edge = 11;
	int n_vertex = 8;
	init_graph(&g, n_vertex, n_edge);
	char* e[] = {"AB", "AC", "BC", "BD", "CE",
				"DE", "DF", "EG", "FG", "FH", "GH"};
	//disp(&g);
	
	for(int i = 0; i < n_edge; ++i)
	{
	//	printf("%d->%d\n", e[i][0] - 'A', e[i][1] - 'A');
		add_edge(&g, e[i][0] - 'A', e[i][1] - 'A');
	}
	//printf("disp:\n");
	//disp(&g);
	bfs(&g, 0);
} 
