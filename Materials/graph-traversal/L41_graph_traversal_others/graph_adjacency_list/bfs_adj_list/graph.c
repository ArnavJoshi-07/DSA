#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "graph.h"
#define DEBUG 0
// list functions 
void init_list(list_t *ptr_list)
{
	ptr_list->head_ = ptr_list->tail_ = NULL;
}
void add_list(list_t *ptr_list, int v)
{
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp->vertex_ = v; 
	temp->next_ = NULL;
	if(ptr_list->head_ == NULL)
	{
		ptr_list->head_ =  temp;
	}
	else 
	{
		ptr_list->tail_->next_ = temp;
	}
	ptr_list->tail_ = temp;
		
}
void disp_list(list_t* ptr_list)
{
	node_t* temp = ptr_list->head_;
	while(temp)
	{
		printf("%d ", temp->vertex_);
		temp = temp->next_;
	}
	printf("\n");
}

void init_graph(graph_t *ptr_graph, int n_vertices, int n_edges)
{
	ptr_graph->n_vertices_ = n_vertices;
	ptr_graph->n_edges_ = n_edges;
	for(int i = 0; i < ptr_graph->n_vertices_; ++i)
	{
		init_list(&ptr_graph->adj_list_[i]);
	}
}

void add_edge(graph_t *ptr_graph, int u, int v)
{
	if(DEBUG)
		printf("Adding an edge %d - %d\n", u, v);
	
	add_list(&ptr_graph->adj_list_[u], v);
	add_list(&ptr_graph->adj_list_[v], u);
	
}

#if 0
// a: adjancency list 
// array of pointers to lists
void dfs_recursive(int n, list_t a[MAXSIZE], int visited[], int u)
{
	visited[u] = 1;
	printf("visited %c \n", u + 'A');
	node_t* temp = a[u].head_;
	int v;
	while(temp)
	{
		v = temp->vertex_;
		if(! visited[v])
		{
			dfs_recursive(n, a, visited, v);
		}
		temp = temp->next_;
	}
}
// vertex to start : u 
// visited so far : visited 
void dfs(graph_t *ptr_graph,  int u)
{
	int visited[MAXSIZE];
	for(int i = 0; i < ptr_graph->n_vertices_; ++i)
		visited[i] = 0;
	dfs_recursive(ptr_graph->n_vertices_, ptr_graph->adj_list_, visited, u);
	printf("\n");
}
#endif 
/*
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
*/
void bfs(graph_t *ptr_graph,  int u)
{
	queue_t q;
	init_queue(&q);

	int visited[MAXSIZE];
	for(int i = 0; i < ptr_graph->n_vertices_; ++i)
		visited[i] = 0;
	int v;
	visited[u] = 1;
	enqueue(&q, u);
	while(!is_empty(&q))
	{
		u = dequeue(&q);
		printf("visiting : %c\n", u + 'A');
		node_t* temp = ptr_graph->adj_list_[u].head_;
		while(temp)
		{
			v = temp->vertex_;
			if(!visited[v])
			{
				visited[v] = 1;
				enqueue(&q, v);
			}
			temp = temp->next_;
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
		printf("%d : ", i);
		disp_list(&ptr_graph->adj_list_[i]);
		printf("\n");
	}

}

void deinit_graph(graph_t *ptr_graph)
{
	for(int i = 0; i < ptr_graph->n_vertices_; ++i)
	{
		init_list(&ptr_graph->adj_list_[i]);
	}
	ptr_graph->n_vertices_ = 0;
	ptr_graph->n_edges_ = 0;

}