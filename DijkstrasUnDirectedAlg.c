#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 100

int i, j;

void make(int matrix[V][V], int v) {
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            matrix[i][j] = 0;
        }
    }
}

void print(int matrix[V][V], int v) {
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_edge(int matrix[V][V], int from, int to, int weight) {
    matrix[from][to] = weight;
    matrix[to][from] = weight; // For an undirected graph, add both directions
}

void dijkstra(int graph[V][V], int src, int v) {
    int dist[v];
    bool sptSet[v];

    for (int i = 0; i < v; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < v - 1; count++) {
        int u, min = INT_MAX;
        for (u = 0; u < v; u++) {
            if (!sptSet[u] && dist[u] < min) {
                min = dist[u];
                i = u;
            }
        }

        sptSet[i] = true;

        for (int x = 0; x < v; x++) {
            if (!sptSet[x] && graph[i][x] && dist[i] != INT_MAX && dist[i] + graph[i][x] < dist[x]) {
                dist[x] = dist[i] + graph[i][x];
            }
        }
    }

    printf("Shortest distances from source node %d:\n", src);
    for (int i = 0; i < v; i++) {
        printf("Node %d: %d\n", i, dist[i]);
    }
}

int main() {
    int v;
    printf("Enter the number of nodes (vertices): ");
    scanf("%d", &v);
    
    int matrix[V][V];
    make(matrix, v);

    while (1) {
        int from, to, weight;
        printf("Enter an edge (from to weight) or enter -1 to terminate: ");
        scanf("%d", &from);

        if (from == -1) {
            break;
        }

        scanf("%d %d", &to, &weight);
        add_edge(matrix, from, to, weight);
    }

    printf("Graph Adjacency Matrix:\n");
    print(matrix, v);

    int source_node;
    printf("Enter the source node: ");
    scanf("%d", &source_node);

    dijkstra(matrix, source_node, v);

    return 0;
}

