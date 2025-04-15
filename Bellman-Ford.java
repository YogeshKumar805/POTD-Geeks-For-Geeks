class Solution {
    public int[] bellmanFord(int V, int[][] edges, int src) {
        int[] dist = new int[V];
        // Initialize distances from src to all other vertices as INFINITE
        int INF = (int) Math.pow(10, 8);
        for (int i = 0; i < V; i++) {
            dist[i] = INF;
        }
        dist[src] = 0;

        // Relax all edges |V| - 1 times.
        for (int i = 1; i < V; i++) {
            for (int[] edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int weight = edge[2];
                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        // Check for negative-weight cycles.
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                return new int[]{-1};
            }
        }

        return dist;
    }
}
