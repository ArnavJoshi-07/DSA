
#ifndef GRAPH_H
#define GRAPH_H

#define MAXSIZE 10

typedef struct graph {
    int n_vertices_;
    int n_edges_;
    int adj_mat_[MAXSIZE][MAXSIZE];
} graph_t;

typedef enum {
    RING, BUS, STAR, FULL_MESH, TREE, HYBRID, NOT_NETWORK
} topology_t;

void init_graph(graph_t *g, int n);
void add_edge(graph_t *g, int u, int v);
void disp(graph_t *g);
void dfs(graph_t *g, int start);
void deinit_graph(graph_t *g);

int degree(graph_t *g, int v);
int count_edges(graph_t *g);
int is_connected(graph_t *g);
int check_eulerian(graph_t *g);
int check_star(graph_t *g);
topology_t identify_topology(graph_t *g);
const char *topology_name(topology_t t);

#endif
