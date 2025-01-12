#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

int graph[MAX_VERTICES][MAX_VERTICES], key[MAX_VERTICES], parent[MAX_VERTICES], visited[MAX_VERTICES];

void prim(int vertices) {
    for (int i = 0; i < vertices; i++) {
        key[i] = INF;
        visited[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++) {
        int minKey = INF, u = -1;
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    for (int i = 1; i < vertices; i++) {
        printf("%d-%d %d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    int vertices = 5;
    int g[5][5] = { {0, 2, 0, 6, 0}, {2, 0, 3, 8, 5}, {0, 3, 0, 0, 7}, {6, 8, 0, 0, 9}, {0, 5, 7, 9, 0} };
    for (int i = 0; i < vertices; i++) for (int j = 0; j < vertices; j++) graph[i][j] = g[i][j];

    prim(vertices);
    return 0;
}
