#include <stdio.h>

#define V 4

int i, j;

void initializeGraph(int matrix[V][V]) {
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            matrix[i][j] = 0; // Initialize with 0 to indicate no edge
        }
    }
}

void printGraph(int matrix[V][V]) {
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addEdge(int matrix[V][V], int from, int to, int weight) {
    matrix[from][to] = weight;
}

int main() {
    int matrix[V][V];
    initializeGraph(matrix);
    printGraph(matrix);

    // Adding directed edges with weights
    addEdge(matrix, 1, 2, 3);
    addEdge(matrix, 3, 1, 5);

    printf("\nDirected Graph after adding edges:\n");
    printGraph(matrix);

    return 0;
}

