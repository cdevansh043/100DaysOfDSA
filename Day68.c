// Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

#include <stdio.h>
#include <stdbool.h>

#define V 6

void khansTopologicalSort(int adj[V][V]) {
    int in_degree[V] = {0};
    int queue[V];
    int front = 0, rear = 0;
    int topo_order[V];
    int count = 0;

    // 1. Calculate in-degree of each vertex
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j]) {
                in_degree[j]++;
            }
        }
    }

    // 2. Enqueue all vertices with in-degree 0
    for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // 3. Process the queue
    while (front < rear) {
        int u = queue[front++];
        topo_order[count++] = u;

        for (int v = 0; v < V; v++) {
            if (adj[u][v]) {
                // Reduce in-degree of neighbors
                if (--in_degree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    // 4. Output the result
    if (count != V) {
        printf("The graph contains a cycle. Topological sort not possible.\n");
    } else {
        for (int i = 0; i < count; i++) {
            printf("%d ", topo_order[i]);
        }
        printf("\n");
    }
}

int main() {
    // Example: 5->2, 5->0, 4->0, 4->1, 2->3, 3->1
    int adj[V][V] = {0};
    adj[5][2] = 1; adj[5][0] = 1;
    adj[4][0] = 1; adj[4][1] = 1;
    adj[2][3] = 1; adj[3][1] = 1;

    khansTopologicalSort(adj);

    return 0;
}