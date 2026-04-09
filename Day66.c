// Problem: Detect cycle in directed graph using DFS and recursion stack.
//
// Output:
// - YES if cycle exists

#include <stdio.h>
#include <stdbool.h>

#define V 4

bool isCyclicUtil(int v, int adj[V][V], bool visited[], bool recStack[]) {
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;

        for (int i = 0; i < V; i++) {
            if (adj[v][i]) {
                if (!visited[i] && isCyclicUtil(i, adj, visited, recStack))
                    return true;
                else if (recStack[i])
                    return true;
            }
        }
    }
    recStack[v] = false;
    return false;
}

bool isCyclic(int adj[V][V]) {
    bool visited[V] = {false};
    bool recStack[V] = {false};

    for (int i = 0; i < V; i++) {
        if (!visited[i] && isCyclicUtil(i, adj, visited, recStack))
            return true;
    }
    return false;
}

int main() {
    int adj[V][V] = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {1, 0, 0, 0}
    };

    if (isCyclic(adj))
        printf("YES\n");

    return 0;
}