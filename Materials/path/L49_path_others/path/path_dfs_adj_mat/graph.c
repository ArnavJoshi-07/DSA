#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
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

void disp(graph_t *ptr_graph)
{
	printf("displaying\n");
	for(int i = 0; i < ptr_graph->n_vertices_; ++i)
	{
		printf("%c  ", i);
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

int find_path_recursive(graph_t *ptr_graph, int path[], int* ptr_len,
	int from, int to, int visited[])
{
	visited[from] = 1;
	if(from == to)
		return 1;
	int n = ptr_graph->n_vertices_;
	for(int i = 0; i < n; ++i)
	{
		if(ptr_graph->adj_mat_[from][i] && ! visited[i])
		{
			path[(*ptr_len)++] = i;
			if(find_path_recursive(ptr_graph, path, ptr_len,
					i, to, visited))
				return 1;
			--(*ptr_len);
		}
	}
	
	return 0;
}

int find_path(graph_t *ptr_graph, int path[], int* ptr_len,
	int from, int to)
{
	int visited[MAXSIZE];
	path[(*ptr_len)++] = from;
	for(int i = 0; i < ptr_graph->n_vertices_; ++i)
		visited[i] = 0;
	return find_path_recursive(ptr_graph, path, ptr_len, from, to, visited);
}