#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"

#define DEBUG 0
void init_graph(graph_t *ptr_graph, int n_vertices, int n_edges)
{
	ptr_graph->n_vertices_ = n_vertices;
	ptr_graph->n_edges_ = n_edges;
	for(int i = 0; i < ptr_graph->n_vertices_; ++i)
	{
		for(int j = 0; j < ptr_graph->n_vertices_; ++j)
		{		
			ptr_graph->adj_mat_[i][j] = 0;
		}
	}
}

void add_edge(graph_t *ptr_graph, int from, int to)
{
	if(DEBUG)
		printf("Adding an edge %d - %d\n", from, to);
	ptr_graph->adj_mat_[from][to] = 1;
	ptr_graph->adj_mat_[to][from] = 1;
}


void bfs(graph_t *ptr_graph,  int u)
{
	int n = ptr_graph->n_vertices_;
	
	queue_t q;
	init_queue(&q);
	int visited[MAXSIZE];
	for(int i = 0; i < n; ++i)
	{
		visited[i] = 0;
	}
	int v;
	visited[u] = 1;
	enqueue(&q, u);
	while(!is_empty(&q))
	{
		v = dequeue(&q);
		printf("visiting : %c\n", v + 'A');
		for(int i = 0; i < n; ++i)
		{
			if(ptr_graph->adj_mat_[v][i] && !visited[i])
			{
				visited[i] = 1;
				enqueue(&q, i);
			}
		}
	}
	deinit_queue(&q);
}

void disp(graph_t *ptr_graph)
{
	printf("displaying\n");
	printf("   A  B  C  D  E  F  G  H\n");
	for(int i = 0; i < ptr_graph->n_vertices_; ++i)
	{
		printf("%c  ", i + 'A');
		for(int j = 0; j < ptr_graph->n_vertices_; ++j)
		{
			printf("%2d ", ptr_graph->adj_mat_[i][j]);
		}
		printf("\n");
	}

}

void deinit_graph(graph_t *ptr_graph)
{
	ptr_graph->n_vertices_ = 0;
	ptr_graph->n_edges_ = 0;

}