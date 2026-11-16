#ifndef GRAPH_H
#define GRAPH_H

#define MAXSIZE 10

typedef struct graph{
    int n_vertices;//# of vertices
    int n_edges;
    int adj_mat[MAXSIZE][MAXSIZE];
}graph_t;

void init_graph(graph_t *, int, int);
void add_edge(graph_t *, int from, int to);
void bfs(graph_t *, int u);
void disp(graph_t *);
void deinit_graph(graph_t *);
#endif

