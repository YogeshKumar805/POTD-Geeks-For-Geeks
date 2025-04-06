class Solution {
    static ArrayList<ArrayList<Integer>> adjList;
    static ArrayList<Integer> ans;
    static boolean[] visited;
    static void dfs(int v) {
        visited[v] = true;
        for(int u: adjList.get(v)) {
            if(!visited[u]) {
                dfs(u);
            }
        }
        ans.add(v);
    }
    public static ArrayList<Integer> topoSort(int V, int[][] edges) {
        // code here
        adjList = new ArrayList<>();
        ans = new ArrayList<>();
        for(int i = 0; i < V; i++) adjList.add(new ArrayList<>());
        for(int i = 0; i < edges.length; i++) {
            int src = edges[i][0];
            int dest = edges[i][1];
            adjList.get(src).add(dest);
        }
        visited = new boolean[V];
        Arrays.fill(visited, false);
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(i);
            }
        }
        
        Collections.reverse(ans);
        return ans;
    }
}
