#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

typedef struct {
    int src, dest, weight;
} Edge;

Edge edges[MAX_VERTICES];
int dist[MAX_VERTICES];

void bellmanFord(int vertices, int edgesCount, int start) {
    for (int i = 0; i < vertices; i++) dist[i] = INF;
    dist[start] = 0;

    for (int i = 1; i < vertices; i++) {
        for (int j = 0; j < edgesCount; j++) {
            int u = edges[j].src, v = edges[j].dest, w = edges[j].weight;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // 음의 사이클 검사
    for (int i = 0; i < edgesCount; i++) {
        int u = edges[i].src, v = edges[i].dest, w = edges[i].weight;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Graph contains a negative weight cycle\n");
            return;
        }
    }
}
