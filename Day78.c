
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int to;
    int weight;
} Edge;

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int *degree = (int *)calloc(n + 1, sizeof(int));
    int (*input_edges)[3] = malloc(m * sizeof(*input_edges));

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &input_edges[i][0], &input_edges[i][1], &input_edges[i][2]);
        degree[input_edges[i][0]]++;
        degree[input_edges[i][1]]++;
    }

    Edge **adj = (Edge **)malloc((n + 1) * sizeof(Edge *));
    for (int i = 1; i <= n; i++) {
        adj[i] = (Edge *)malloc(degree[i] * sizeof(Edge));
    }

    int *current_pos = (int *)calloc(n + 1, sizeof(int));
    for (int i = 0; i < m; i++) {
        int u = input_edges[i][0];
        int v = input_edges[i][1];
        int w = input_edges[i][2];
        adj[u][current_pos[u]].to = v;
        adj[u][current_pos[u]++].weight = w;
        adj[v][current_pos[v]].to = u;
        adj[v][current_pos[v]++].weight = w;
    }

    int *key = (int *)malloc((n + 1) * sizeof(int));
    int *inMST = (int *)calloc(n + 1, sizeof(int));
    for (int i = 1; i <= n; i++) key[i] = INT_MAX;

    key[1] = 0;
    int total_weight = 0;

    for (int count = 0; count < n; count++) {
        int u = -1, min = INT_MAX;
        for (int v = 1; v <= n; v++) {
            if (!inMST[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        if (u == -1) break;

        inMST[u] = 1;
        total_weight += key[u];

        for (int i = 0; i < degree[u]; i++) {
            int v = adj[u][i].to;
            int weight = adj[u][i].weight;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
            }
        }
    }

    printf("%d\n", total_weight);

    for (int i = 1; i <= n; i++) free(adj[i]);
    free(adj);
    free(degree);
    free(input_edges);
    free(current_pos);
    free(key);
    free(inMST);

    return 0;
}