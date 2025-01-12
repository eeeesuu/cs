#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100
#define MAX_VERTICES 100

typedef struct {
    int u, v, weight;
} Edge;

Edge edges[MAX_EDGES];
int parent[MAX_VERTICES], rank[MAX_VERTICES];

int find(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

void unionSets(int u, int v) {
    int rootU = find(u), rootV = find(v);
    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV])
            parent[rootV] = rootU;
        else if (rank[rootU] < rank[rootV])
            parent[rootU] = rootV;
        else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

int compareEdges(const void *a, const void *b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

void kruskal(int vertices, int edgesCount) {
    for (int i = 0; i < vertices; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    qsort(edges, edgesCount, sizeof(Edge), compareEdges);

    int mstWeight = 0;
    for (int i = 0; i < edgesCount; i++) {
        int u = edges[i].u, v = edges[i].v;
        if (find(u) != find(v)) {
            printf("Edge: %d - %d, Weight: %d\n", u, v, edges[i].weight);
            mstWeight += edges[i].weight;
            unionSets(u, v);
        }
    }
    printf("Total weight of MST: %d\n", mstWeight);
}

int main() {
    int vertices = 4, edgesCount = 5;
    
    edges[0] = (Edge){0, 1, 10};
    edges[1] = (Edge){0, 2, 6};
    edges[2] = (Edge){0, 3, 5};
    edges[3] = (Edge){1, 3, 15};
    edges[4] = (Edge){2, 3, 4};
    
    kruskal(vertices, edgesCount);

    return 0;
}
