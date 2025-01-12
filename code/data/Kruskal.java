import java.util.*;

class Kruskal {
    static class Edge {
        int u, v, weight;
        Edge(int u, int v, int weight) {
            this.u = u; this.v = v; this.weight = weight;
        }
    }

    static class UnionFind {
        int[] parent, rank;
        UnionFind(int size) {
            parent = new int[size];
            rank = new int[size];
            for (int i = 0; i < size; i++) parent[i] = i;
        }

        int find(int i) {
            if (parent[i] == i) return i;
            return parent[i] = find(parent[i]);
        }

        void union(int u, int v) {
            int rootU = find(u), rootV = find(v);
            if (rootU != rootV) {
                if (rank[rootU] > rank[rootV]) parent[rootV] = rootU;
                else if (rank[rootU] < rank[rootV]) parent[rootU] = rootV;
                else { parent[rootV] = rootU; rank[rootU]++; }
            }
        }
    }

    public static void kruskal(int vertices, List<Edge> edges) {
        UnionFind uf = new UnionFind(vertices);
        Collections.sort(edges, Comparator.comparingInt(e -> e.weight));

        int mstWeight = 0;
        for (Edge edge : edges) {
            if (uf.find(edge.u) != uf.find(edge.v)) {
                System.out.println("Edge: " + edge.u + " - " + edge.v + ", Weight: " + edge.weight);
                mstWeight += edge.weight;
                uf.union(edge.u, edge.v);
            }
        }
        System.out.println("Total weight of MST: " + mstWeight);
    }

    public static void main(String[] args) {
        List<Edge> edges = new ArrayList<>();
        edges.add(new Edge(0, 1, 10));
        edges.add(new Edge(0, 2, 6));
        edges.add(new Edge(0, 3, 5));
        edges.add(new Edge(1, 3, 15));
        edges.add(new Edge(2, 3, 4));

        kruskal(4, edges);
    }
}
