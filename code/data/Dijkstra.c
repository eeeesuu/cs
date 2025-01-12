#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

int graph[MAX_VERTICES][MAX_VERTICES];
int dist[MAX_VERTICES];
int visited[MAX_VERTICES];

int minDistance(int vertices) {
    int min = INF, minIndex;
    for (int i = 0; i < vertices; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void dijkstra(int vertices, int start) {
    for (int i = 0; i < vertices; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[start] = 0;

    for (int i = 0; i < vertices - 1; i++) {
        int u = minDistance(vertices);
        visited[u] = 1;

        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}
