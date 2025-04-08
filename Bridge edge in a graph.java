import java.util.*;

class Solution {
    static void bfs(int src, ArrayList<ArrayList<Integer>> adj, int c, int d, boolean check, int[] visited) {
        Queue<Integer> q = new LinkedList<>();
        q.add(src);
        visited[src] = 1;
        while (!q.isEmpty()) {
            int node = q.poll();
            for (int next : adj.get(node)) {
                if (check && ((node == c && next == d) || (node == d && next == c))) {
                    continue;
                }
                if (visited[next] != 1) {
                    visited[next] = 1;
                    q.add(next);
                }
            }
        }
    }

    static boolean isBridge(int V, ArrayList<ArrayList<Integer>> adj, int c, int d) {
        int[] visited = new int[V];

        // Count the number of connected components before removing the edge
        Arrays.fill(visited, 0);
        int disjointSets = 0;
        for (int i = 0; i < V; i++) {
            if (visited[i] == 0) {
                bfs(i, adj, c, d, false, visited);
                disjointSets++;
            }
        }

        // Count the number of connected components after removing the edge
        Arrays.fill(visited, 0);
        int disjointSets2 = 0;
        for (int i = 0; i < V; i++) {
            if (visited[i] == 0) {
                bfs(i, adj, c, d, true, visited);
                disjointSets2++;
            }
        }

        // If the number of connected components increases, the edge is a bridge
        return disjointSets != disjointSets2;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = Integer.parseInt(sc.nextLine().trim());
        while (t-- > 0) {
            int V = Integer.parseInt(sc.nextLine().trim());
            int E = Integer.parseInt(sc.nextLine().trim());

            int[][] edges = new int[E][2];
            for (int i = 0; i < E; i++) {
                String[] parts = sc.nextLine().trim().split("\\s+");
                edges[i][0] = Integer.parseInt(parts[0]);
                edges[i][1] = Integer.parseInt(parts[1]);
            }

            int c = Integer.parseInt(sc.nextLine().trim());
            int d = Integer.parseInt(sc.nextLine().trim());

            // Convert edge list to adjacency list
            ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < V; i++) {
                adj.add(new ArrayList<>());
            }
            for (int[] edge : edges) {
                int u = edge[0];
                int v = edge[1];
                adj.get(u).add(v);
                adj.get(v).add(u); // Since the graph is undirected
            }

            Solution obj = new Solution();
            boolean result = obj.isBridge(V, adj, c, d);
            System.out.println(result ? "true" : "false");
            System.out.println("~");
        }

        sc.close();
    }
}
