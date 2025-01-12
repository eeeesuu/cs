class BellmanFord {
    static final int INF = Integer.MAX_VALUE;

    static class Edge {
        int src, dest, weight;

        Edge(int src, int dest, int weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }
    }

    public static void bellmanFord(int vertices, Edge[] edges, int start) {
        int[] dist = new int[vertices];
        for (int i = 0; i < vertices; i++) dist[i] = INF;
        dist[start] = 0;

        for (int i = 1; i < vertices; i++) {
            for (Edge edge : edges) {
                if (dist[edge.src] != INF && dist[edge.src] + edge.weight < dist[edge.dest]) {
                    dist[edge.dest] = dist[edge.src] + edge.weight;
                }
            }
        }

        // 음의 사이클 검사
        for (Edge edge : edges) {
            if (dist[edge.src] != INF && dist[edge.src] + edge.weight < dist[edge.dest]) {
                System.out.println("Graph contains a negative weight cycle");
                return;
            }
        }
    }
}
