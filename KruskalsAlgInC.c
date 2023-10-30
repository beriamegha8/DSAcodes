#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};
int v;
// Structure to represent a subset for union-find operations
struct Subset {
    int parent, rank;
};

// Function to create a graph with V vertices and E edges
struct Edge* createGraph(int V, int E) {
    struct Edge* graph = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// Function to find the set of an element 'i'
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function that does union of two sets of 'x' and 'y'
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Comparator function used for sorting edges
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Kruskal's algorithm to find the minimum spanning tree
void KruskalMST(struct Edge* graph, int V, int E) {
    struct Edge result[V]; // Stores the resultant MST
    int e = 0; // Index for the result[] array
    int i = 0; // Index for sorted edges

    // Step 1: Sort all the edges in non-decreasing order of their weight
    qsort(graph, E, sizeof(graph[0]), compareEdges);

    // Allocate memory for creating V subsets
    struct Subset subsets[V];

    // Initialize V subsets with single elements
    for (v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < E) {
        // Step 2: Pick the smallest edge. Increment the index for the next iteration.
        struct Edge next_edge = graph[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does not cause a cycle, add it to the result[] and increment the index of the result
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    printf("Edges in the MST:\n");
    for (i = 0; i < e; i++) {
        printf("%d -- %d with weight %d\n", result[i].src, result[i].dest, result[i].weight);
    }
}

int main() {
    int V = 4;
    int E = 5;
    struct Edge* graph = createGraph(V, E);

    graph[0].src = 0;
    graph[0].dest = 1;
    graph[0].weight = 10;

    graph[1].src = 0;
    graph[1].dest = 2;
    graph[1].weight = 6;

    graph[2].src = 0;
    graph[2].dest = 3;
    graph[2].weight = 5;

    graph[3].src = 1;
    graph[3].dest = 3;
    graph[3].weight = 15;

    graph[4].src = 2;
    graph[4].dest = 3;
    graph[4].weight = 4;

    KruskalMST(graph, V, E);

    free(graph);
    return 0;
}

