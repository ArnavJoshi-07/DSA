
#include <stdio.h>
#include <string.h>
#include "graph.h"

void init_graph(graph_t *g, int n)
{
    g->n_vertices_ = n;
    g->n_edges_ = 0;
    memset(g->adj_mat_, 0, sizeof(g->adj_mat_));
}

void add_edge(graph_t *g, int u, int v)
{
    if (u < 0 || v < 0 || u >= g->n_vertices_ ||
        v >= g->n_vertices_ || u == v || g->adj_mat_[u][v])
        return;

    g->adj_mat_[u][v] = g->adj_mat_[v][u] = 1;
    g->n_edges_++;
}

void disp(graph_t *g)
{
    int i, j;

    printf("  ");
    for (i = 0; i < g->n_vertices_; i++)
        printf("%c ", 'A' + i);
    printf("\n");

    for (i = 0; i < g->n_vertices_; i++) {
        printf("%c ", 'A' + i);
        for (j = 0; j < g->n_vertices_; j++)
            printf("%d ", g->adj_mat_[i][j]);
        printf("\n");
    }
}

static void visit(graph_t *g, int v, int seen[])
{
    int i;
    seen[v] = 1;

    for (i = 0; i < g->n_vertices_; i++)
        if (g->adj_mat_[v][i] && !seen[i])
            visit(g, i, seen);
}

void dfs(graph_t *g, int start)
{
    int seen[MAXSIZE] = {0};
    int i;

    if (start < 0 || start >= g->n_vertices_)
        return;

    visit(g, start, seen);

    printf("DFS: ");
    for (i = 0; i < g->n_vertices_; i++)
        if (seen[i])
            printf("%c ", 'A' + i);
    printf("\n");
}

void deinit_graph(graph_t *g)
{
    memset(g, 0, sizeof(*g));
}

int degree(graph_t *g, int v)
{
    int i, d = 0;

    if (v < 0 || v >= g->n_vertices_)
        return -1;

    for (i = 0; i < g->n_vertices_; i++)
        d += g->adj_mat_[v][i];

    return d;
}

int count_edges(graph_t *g)
{
    int i, j, count = 0;

    for (i = 0; i < g->n_vertices_; i++)
        for (j = i + 1; j < g->n_vertices_; j++)
            count += g->adj_mat_[i][j];

    return count;
}

int is_connected(graph_t *g)
{
    int seen[MAXSIZE] = {0};
    int i;

    if (g->n_vertices_ == 0)
        return 0;

    visit(g, 0, seen);

    for (i = 0; i < g->n_vertices_; i++)
        if (!seen[i])
            return 0;

    return 1;
}

int check_eulerian(graph_t *g)
{
    int seen[MAXSIZE] = {0};
    int i, odd = 0, start = -1;

    if (count_edges(g) == 0)
        return 0;

    for (i = 0; i < g->n_vertices_; i++)
        if (degree(g, i) > 0) {
            start = i;
            break;
        }

    visit(g, start, seen);

    for (i = 0; i < g->n_vertices_; i++) {
        if (degree(g, i) > 0 && !seen[i])
            return 0;
        if (degree(g, i) % 2)
            odd++;
    }

    if (odd == 0) return 2;
    if (odd == 2) return 1;
    return 0;
}

int check_star(graph_t *g)
{
    int i, hub = -1, n = g->n_vertices_;

    if (n < 3)
        return -1;

    for (i = 0; i < n; i++)
        if (degree(g, i) == n - 1) {
            if (hub != -1)
                return -1;
            hub = i;
        }

    if (hub == -1)
        return -1;

    for (i = 0; i < n; i++)
        if (i != hub && degree(g, i) != 1)
            return -1;

    return hub;
}

topology_t identify_topology(graph_t *g)
{
    int i, n = g->n_vertices_, edges = count_edges(g);
    int ones = 0, twos = 1, full = 1;

    if (n < 2 || !is_connected(g))
        return NOT_NETWORK;

    for (i = 0; i < n; i++) {
        int d = degree(g, i);
        if (d == 1) ones++;
        if (d != 2) twos = 0;
        if (d != n - 1) full = 0;
    }

    if (n >= 3 && twos) return RING;
    if (edges == n - 1 && ones == 2) return BUS;
    if (check_star(g) != -1) return STAR;
    if (full) return FULL_MESH;
    if (edges == n - 1) return TREE;

    return HYBRID;
}

const char *topology_name(topology_t t)
{
    switch (t) {
        case RING: return "Ring";
        case BUS: return "Bus";
        case STAR: return "Star";
        case FULL_MESH: return "Full Mesh";
        case TREE: return "Tree";
        case HYBRID: return "Hybrid";
        default: return "Not a network";
    }
}
