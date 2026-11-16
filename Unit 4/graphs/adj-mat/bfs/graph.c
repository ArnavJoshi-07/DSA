#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"

void init_graph(graph_t *ptr, int n_vert, int n_edg){
    ptr->n_edges = n_edg;
    ptr->n_vertices = n_vert;
    for(int i = 0; i<ptr->n_vertices; i++){
        for(int j = 0; j<ptr->n_vertices; j++){
            ptr->adj_mat[i][j] = 0;
        }
    }
}

void add_edge(graph_t *ptr, int from, int to){
    ptr->adj_mat[from][to] = 1;
    ptr->adj_mat[to][from] = 1;
    //both sides done cuz undirected...if it was a directed graph,
    //it would only be from -> to
}

void bfs(graph_t * ptr, int u){
    int n = ptr->n_vertices;
    queue_t q;
    init_queue(&q);
    int visited[MAXSIZE];
    for(int i = 0; i<ptr->n_vertices; i++){
        visited[i] = 0;
    }
    int v;
    visited[u] = 1;
    enqueue(&q, u);
    while(!is_empty(&q)){
        v = dequeue(&q);
        printf("Visiting : %c\n", v + 'A');
        //finding neighbours
        for(int i = 0; i<n; i++){
            if(!visited[i] && ptr->adj_mat[v][i]){
                visited[i] = 1;
                enqueue(&q,i);
            }
        }
    }
    deinit_queue(&q);
}

void disp(graph_t *ptr){
    printf("Displaying \n A B C D E F G H\n");
    for (int i = 0; i < ptr->n_vertices; ++i){
        printf("%c  ", i+ 'A');
        for(int j = 0; j< ptr->n_vertices; ++j){
            printf("%2d ", ptr->adj_mat[i][j]);
        }
        printf("\n");
    }
}

void deinit_graph(graph_t *ptr){
    ptr->n_edges =  ptr->n_vertices = 0;
}
