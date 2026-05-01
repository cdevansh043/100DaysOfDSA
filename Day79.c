#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int to;
    int weight;
} Edge;

typedef struct {
    int v;
    int dist;
} Node;

typedef struct {
    Node *data;
    int size;
    int capacity;
} MinHeap;

void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap *hp, int v, int dist) {
    if (hp->size == hp->capacity) return;
    hp->data[hp->size].v = v;
    hp->data[hp->size].dist = dist;
    int i = hp->size++;
    while (i != 0 && hp->data[(i - 1) / 2].dist > hp->data[i].dist) {
        swap(&hp->data[i], &hp->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Node pop(MinHeap *hp) {
    Node res = hp->data[0];
    hp->data[0] = hp->data[--hp->size];
    int i = 0;
    while (2 * i + 1 < hp->size) {
        int j = 2 * i + 1;
        if (j + 1 < hp->size && hp->data[j + 1].dist < hp->data[j].dist) j++;
        if (hp->data[i].dist <= hp->data[j].dist) break;
        swap(&hp->data[i], &hp->data[j]);
        i = j;
    }
    return res;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int (*input)[3] = malloc(m * sizeof(*input));
    int *degree = (int *)calloc(n + 1, sizeof(int));
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &input[i][0], &input[i][1], &input[i][2]);
        degree[input[i][0]]++;
    }

    Edge **adj = (Edge **)malloc((n + 1) * sizeof(Edge *));
    for (int i = 1; i <= n; i++) adj[i] = (Edge *)malloc(degree[i] * sizeof(Edge));

    int *curr = (int *)calloc(n + 1, sizeof(int));
    for (int i = 0; i < m; i++) {
        int u = input[i][0];
        adj[u][curr[u]].to = input[i][1];
        adj[u][curr[u]++].weight = input[i][2];
    }

    int src;
    scanf("%d", &src);

    int *dist = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    MinHeap hp;
    hp.capacity = m * 2 + n;
    hp.data = (Node *)malloc(hp.capacity * sizeof(Node));
    hp.size = 0;

    push(&hp, src, 0);

    while (hp.size > 0) {
        Node top = pop(&hp);
        int u = top.v;
        int d = top.dist;

        if (d > dist[u]) continue;

        for (int i = 0; i < degree[u]; i++) {
            int v = adj[u][i].to;
            int w = adj[u][i].weight;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&hp, v, dist[v]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");

    for (int i = 1; i <= n; i++) free(adj[i]);
    free(adj); free(degree); free(input); free(curr); free(dist); free(hp.data);
    return 0;
}