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

void disp(graph_t *ptr_graph)
{
	printf("displaying\n");
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

int to_visit(int v[], int n)
{
	for(int i = 0; i < n; ++i)
	{
		if(v[i] == 0)
			return i;
	}
	return -1;
}

int find_path_bfs(graph_t *ptr_graph,  int parent[], 
			int from, int to)
{
	queue_t q;
	init_queue(&q);

	int v;
	int visited[MAXSIZE];
	for(int i = 0; i < ptr_graph->n_vertices_; ++i)
		visited[i] = 0;
	
	visited[from] = 1;
	
	int u = from;
	enqueue(&q, u);
	while(!is_empty(&q))
	{
		u = dequeue(&q);
		node_t* temp = ptr_graph->adj_list_[u].head_;
		while(temp)
		{
			v = temp->vertex_;
			if(!visited[v])
			{
				visited[v] = 1;
				parent[v] = u;
				if(v == to)
					return 1;
				enqueue(&q, v);
			}
			temp = temp->next_;
		}
		
	}
	deinit_queue(&q);
	return 0;
}

static void reverse(int a[], int n)
{
	int i = 0; int j = n - 1;
	while(i < j)
	{
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
		++i;
		--j;
	}
}

void fill_path(int parent[], int path[], int *ptr_len, int to)
{
	while(parent[to] != -1)
	{
		path[(*ptr_len)++] = to;
		to = parent[to];
	}
	path[(*ptr_len)++] = to;
	reverse(path, *ptr_len);

}

int find_path(graph_t *ptr_graph, int path[], int* ptr_len,
	int from, int to)
{
	int n = ptr_graph->n_vertices_;
	// parent array
	int parent[MAXSIZE];
	for(int i = 0; i < n; ++i)
	{
		parent[i] = -1; 
	}
	int res = find_path_bfs(ptr_graph, parent, from, to);
	#if DEBUG
	for(int i = 0; i < n; ++i)
	{
		printf("(%d - %d)", i, parent[i]);
	}
	printf("\n");
	#endif
	if(res)
	{	
		fill_path(parent, path, ptr_len, to);
	}
	return res;
	
}