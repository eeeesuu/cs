import java.util.*;

class Graph {
    private int vertices; // 정점의 개수
    private LinkedList<Integer>[] adjList; // 인접 리스트
    private boolean[] visited; // 방문 여부 배열

    // 생성자
    public Graph(int vertices) {
        this.vertices = vertices;
        adjList = new LinkedList[vertices];
        visited = new boolean[vertices];
        for (int i = 0; i < vertices; i++) {
            adjList[i] = new LinkedList<>();
        }
    }

    // 간선 추가
    public void addEdge(int src, int dest) {
        adjList[src].add(dest);
    }

    // DFS 함수
    public void DFS(int start) {
        visited[start] = true;
        System.out.print(start + " ");

        for (int neighbor : adjList[start]) {
            if (!visited[neighbor]) {
                DFS(neighbor);
            }
        }
    }

    public static void main(String[] args) {
        Graph graph = new Graph(6);

        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 3);
        graph.addEdge(1, 4);
        graph.addEdge(2, 5);

        System.out.println("DFS traversal starting from vertex 0:");
        graph.DFS(0);
    }
}
