#include <stdio.h>
#include <stdlib.h>
#include "graph_2.h"

/* ------------------------------------------------------------------
 * Problem 2 : Connecting groups of cities (ADJACENCY MATRIX + DFS)
 *
 * Cities are vertices A, B, C ... (0, 1, 2 ...). A train connection is an
 * undirected edge. Cities that can reach each other form a group (connected
 * component). There are no connections between different groups.
 * Suggest the MINIMUM number of new connections so that every city can
 * reach every other city.
 *
 * Complete every function marked TODO. Do not change graph_2.h or main2.c.
 * ------------------------------------------------------------------ */

// TODO 1: store n_vertices and n_edges and set every adj_mat_[i][j] to 0.
void init_graph(graph_t *ptr_graph, int n_vertices, int n_edges)
{
	/* your code here */
}

// TODO 2: undirected edge => set BOTH adj_mat_[from][to] and adj_mat_[to][from] to 1.
void add_edge(graph_t *ptr_graph, int from, int to)
{
	/* your code here */
}

// TODO 3: recursive depth first search from vertex u.
//   - mark u visited
//   - print "visited X \n" where X is the letter u + 'A'
//   - for every vertex i that is adjacent to u and NOT yet visited, recurse on i
// n = number of vertices, a = adjacency matrix, visited[] = 0/1 flags
void dfs_recursive(int n, int a[n][MAXSIZE], int visited[], int u)
{
	/* your code here */
}

// TODO 4: set visited[] to 0 for all vertices, call dfs_recursive from u,
//         then print a blank line.
void dfs(graph_t *ptr_graph, int u)
{
	/* your code here */
}

// TODO 5: print "displaying", a header row of letters, then one row per vertex:
//             A   0  1  0 ...
//         (row letter = i + 'A', each entry printed with "%2d ").
void disp(graph_t *ptr_graph)
{
	/* your code here */
}

// GIVEN
void deinit_graph(graph_t *ptr_graph)
{
	ptr_graph->n_vertices_ = 0;
	ptr_graph->n_edges_ = 0;
}

// GIVEN: returns the first vertex with v[i] == 0, or -1 if all are visited
int to_visit(int v[], int n)
{
	for(int i = 0; i < n; ++i)
	{
		if(v[i] == 0)
			return i;
	}
	return -1;
}

// TODO 6: count the groups of cities.
//   - visited[] all 0, count = 0
//   - u = to_visit(...)
//   - while u != -1 : print "count : <++count>", run dfs_recursive from u,
//                     print a blank line, u = to_visit(...)
//   - return count
int connected_components(graph_t *ptr_graph)
{
	/* your code here */
	return 0;
}

// TODO 7 (main task): add the MINIMUM number of connections.
//   Idea: k groups need exactly k - 1 new edges.
//   - Find the groups like in connected_components, but remember ONE
//     representative city of each group in reps[] (the vertex u you start DFS from).
//   - print "Components = <k>, connections needed = <k-1>"
//   - for i = 0 .. k-2 : print "Connect X - Y" (letters of reps[i], reps[i+1]),
//     call add_edge(reps[i], reps[i+1]) and increment n_edges_.
//   - return the number of edges added (0 if k is 0 or 1).
//   Why is k - 1 the minimum? (one new edge can merge at most two groups)
int connect_components(graph_t *ptr_graph)
{
	/* your code here */
	return 0;
}
