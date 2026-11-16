
#include <stdio.h>
#include "graph.h"

static void test_graph(const char *name, int n,
                       const int edges[][2], int m)
{
    graph_t g;
    int i, euler, hub;

    init_graph(&g, n);

    for (i = 0; i < m; i++)
        add_edge(&g, edges[i][0], edges[i][1]);

    printf("\n=== %s ===\n", name);
    disp(&g);

    euler = check_eulerian(&g);
    hub = check_star(&g);

    printf("Eulerian: %s\n",
           euler == 2 ? "Euler circuit" :
           euler == 1 ? "Euler path only" : "Not Eulerian");

    printf("Star: ");
    if (hub == -1)
        printf("No\n");
    else
        printf("Yes, hub = %c\n", 'A' + hub);

    printf("Topology: %s\n", topology_name(identify_topology(&g)));

    deinit_graph(&g);
}

int main(void)
{
    const int handout[][2] = {
        {0,1},{1,2},{2,3},{3,4},{4,5},{5,6},
        {6,7},{7,0},{0,2},{3,5},{1,6}
    };
    const int cycle[][2] = {
        {0,1},{1,2},{2,3},{3,4},{4,0}
    };
    const int path[][2] = {{0,1},{1,2},{2,3}};
    const int star[][2] = {
        {0,1},{0,2},{0,3},{0,4},{0,5}
    };
    const int tree[][2] = {
        {0,1},{0,2},{1,3},{1,4},{2,5},{2,6}
    };
    const int bowtie[][2] = {
        {0,1},{1,2},{2,0},{0,3},{3,4},{4,0}
    };
    const int disconnected[][2] = {{0,1},{2,3}};
    int mesh[10][2], i, j, k = 0;

    test_graph("Handout Graph", 8, handout, 11);
    test_graph("Cycle of 5", 5, cycle, 5);
    test_graph("Path of 4", 4, path, 3);
    test_graph("Star with 5 Leaves", 6, star, 5);

    for (i = 0; i < 5; i++)
        for (j = i + 1; j < 5; j++) {
            mesh[k][0] = i;
            mesh[k++][1] = j;
        }

    test_graph("Complete Graph K5", 5, mesh, 10);
    test_graph("Binary Tree", 7, tree, 6);
    test_graph("Bow-Tie Graph", 5, bowtie, 6);
    test_graph("Disconnected Graph", 4, disconnected, 2);

    return 0;
}
