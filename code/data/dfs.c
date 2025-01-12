#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX_VERTICES]; // 인접 리스트
int visited[MAX_VERTICES];   // 방문 여부 배열

// 그래프에 간선 추가
void addEdge(int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

// DFS 함수
void DFS(int start) {
    visited[start] = 1;
    printf("%d ", start);

    Node* temp = adjList[start];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFS(adjVertex);
        }
        temp = temp->next;
    }
}

int main() {
    int vertices = 6;

    // 초기화
    for (int i = 0; i < vertices; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    // 그래프 정의
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);

    printf("DFS traversal starting from vertex 0:\n");
    DFS(0);

    return 0;
}
