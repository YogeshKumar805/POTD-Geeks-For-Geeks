class Solution {
    public int diameter(int V, int[][] edges) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) adj.add(new ArrayList<>());
        for (int[] e : edges) {
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]);
        }
        int nodeA = bfs(0, adj, V)[0];
        int[] result = bfs(nodeA, adj, V);
        return result[1];
    }
    private int[] bfs(int start, List<List<Integer>> adj, int V) {
        int[] dist = new int[V];
        Arrays.fill(dist, -1);
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        dist[start] = 0;
        int farthestNode = start;
        while (!q.isEmpty()) {
            int node = q.poll();
            for (int nei : adj.get(node)) {
                if (dist[nei] == -1) {
                    dist[nei] = dist[node] + 1;
                    q.add(nei);
                    if (dist[nei] > dist[farthestNode]) {
                        farthestNode = nei;
                    }
                }
            }
        }
        return new int[]{farthestNode, dist[farthestNode]};
    }
}
