#include <stdio.h>
#include <stdlib.h>

void dfs(int v, int n, int **adj, int *degree, int *visited) {
    visited[v] = 1;
    for (int i = 0; i < degree[v]; i++) {
        int neighbor = adj[v][i];
        if (!visited[neighbor]) {
            dfs(neighbor, n, adj, degree, visited);
        }
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int **adj = (int **)malloc((n + 1) * sizeof(int *));
    int *degree = (int *)calloc((n + 1), sizeof(int));
    int *visited = (int *)calloc((n + 1), sizeof(int));

    int (*edges)[2] = malloc(m * sizeof(*edges));
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &edges[i][0], &edges[i][1]);
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
    }

    for (int i = 1; i <= n; i++) {
        adj[i] = (int *)malloc(degree[i] * sizeof(int));
    }

    int *temp_degree = (int *)calloc((n + 1), sizeof(int));
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u][temp_degree[u]++] = v;
        adj[v][temp_degree[v]++] = u;
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            count++;
            dfs(i, n, adj, degree, visited);
        }
    }

    printf("%d\n", count);

    for (int i = 1; i <= n; i++) free(adj[i]);
    free(adj);
    free(degree);
    free(visited);
    free(temp_degree);
    free(edges);

    return 0;
}