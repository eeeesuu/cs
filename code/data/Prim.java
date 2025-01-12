import java.util.*;

class Prim {
    static final int INF = Integer.MAX_VALUE;

    public static void prim(int vertices, int[][] graph) {
        int[] key = new int[vertices];
        int[] parent = new int[vertices];
        boolean[] visited = new boolean[vertices];

        Arrays.fill(key, INF);
        Arrays.fill(parent, -1);
        key[0] = 0;

        for (int count = 0; count < vertices - 1; count++) {
            int minKey = INF, u = -1;
            for (int v = 0; v < vertices; v++) {
                if (!visited[v] && key[v] < minKey) {
                    minKey = key[v];
                    u = v;
                }
            }

            visited[u] = true;

            for (int v = 0; v < vertices; v++) {
                if (graph[u][v] != 0 && !visited[v] && graph[u][v] < key[v]) {
                    key[v] = graph[u][v];
                    parent[v] = u;
                }
            }
        }

        for (int i = 1; i < vertices; i++) {
            System.out.println(parent[i] + "-" + i + " " + graph[i][parent[i]]);
        }
    }

    public static void main(String[] args) {
        int vertices = 5;
        int[][] graph = {
            {0, 2, 0, 6, 0},
            {2, 0, 3, 8, 5},
            {0, 3, 0, 0, 7},
            {6, 8, 0, 0, 9},
            {0, 5, 7, 9, 0}
        };

        prim(vertices, graph);
    }
}
