// Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
#include <stdio.h>
#include <stdbool.h>

#define V 6

void topologicalSortUtil(int v, int adj[V][V], bool visited[], int stack[], int* top) {
    visited[v] = true;

    for (int i = 0; i < V; i++) {
        if (adj[v][i] && !visited[i]) {
            topologicalSortUtil(i, adj, visited, stack, top);
        }
    }

    stack[(*top)++] = v;
}

void topologicalSort(int adj[V][V]) {
    int stack[V];
    int top = 0;
    bool visited[V] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, adj, visited, stack, &top);
        }
    }

    while (top > 0) {
        printf("%d ", stack[--top]);
    }
    printf("\n");
}

int main() {
    // Example Graph: 5->2, 5->0, 4->0, 4->1, 2->3, 3->1
    int adj[V][V] = {0};
    adj[5][2] = 1; adj[5][0] = 1;
    adj[4][0] = 1; adj[4][1] = 1;
    adj[2][3] = 1; adj[3][1] = 1;

    topologicalSort(adj);

    return 0;
}