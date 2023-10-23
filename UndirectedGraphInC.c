#include <stdio.h>

#define V 4

void initializeGraph(int matrix[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            matrix[i][j] = 0; // Initialize with 0 to indicate no edge
        }
    }
}

void printGraph(int matrix[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addEdge(int matrix[V][V], int from, int to, int weight) {
    matrix[from][to] = weight;
    matrix[to][from] = weight; // Since it's an undirected graph
}

int main() {
    int matrix[V][V];
    initializeGraph(matrix);
    printGraph(matrix);

    // Adding edges with weights
    addEdge(matrix, 1, 2, 3);
    addEdge(matrix, 3, 1, 5);

    printf("\nGraph after adding edges:\n");
    printGraph(matrix);

    return 0;
}

