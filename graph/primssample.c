#include <stdio.h>
#define V 3
#define INF 9999

// Your graph as adjacency matrix
int g[V][V] = {
    {0, 19, 8},
    {21, 0, 13},
    {15, 18, 0}
};

// Function to find index of vertex with minimum key value
int minKey(int key[], int visited[]) {
    int min = INF, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (visited[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Prim’s Algorithm
void prims() {
    int parent[V];  // To store MST edges
    int key[V];     // To store minimum edge weight to reach node
    int visited[V] = {0}; // To mark visited nodes

    // Step 1: Initialize all keys as INF
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        parent[i] = -1;
    }

    // Start from node 0
    key[0] = 0;

    // Step 2: Loop to build MST
    for (int count = 0; count < V - 1; count++) {
        // Pick unvisited node with smallest key value
        int u = minKey(key, visited);
        visited[u] = 1;

        // Update keys and parents of unvisited neighbors
        for (int v = 0; v < V; v++) {
            if (g[u][v] && !visited[v] && g[u][v] < key[v]) {
                parent[v] = u;
                key[v] = g[u][v];
            }
        }
    }

    // Step 3: Print MST edges
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, g[i][parent[i]]);
    }
}

int main() {
    prims();
    return 0;
}
