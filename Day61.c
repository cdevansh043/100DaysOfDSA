// Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
// The graph may be directed or undirected.
//
// Input:
// - n (vertices)
// - m (edges)
// - m pairs (u, v)
//
// Output:
// - n x n adjacency matrix

#include <stdio.h>

int main() {
    int n, m;

    // Get number of vertices and edges
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Initialize n x n matrix with zeros
    int adj[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    // Process m edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // Assuming 0-indexed vertices.
        // For 1-indexed input, use adj[u-1][v-1]
        adj[u][v] = 1;

        // Uncomment the next line if the graph is UNDIRECTED
        // adj[v][u] = 1;
    }

    // Print the resulting matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}