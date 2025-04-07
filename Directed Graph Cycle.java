class Solution {
    public boolean isCyclic(int V, int[][] edges) {
        // code here
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<V; i++){
            adj.add(new ArrayList<>());
        }
        for(int[] edge : edges){
            adj.get(edge[0]).add(edge[1]);
        }
        
        boolean[] visited = new boolean[V];
        boolean[] recStack = new boolean[V];
        
        for(int i=0; i<V; i++){
            if(isCyclicUtil(i, visited, recStack, adj)){
                return true;
            }
        }
        return false;
    }
    
    private boolean isCyclicUtil(int v, boolean[] visited, boolean[] recStack, List<List<Integer>> adj){
        if(recStack[v]){
            return true;
        }
        if(visited[v]){
            return false;
        }
        
        visited[v] = true;
        recStack[v] = true;
        
        for(int neighbor : adj.get(v)){
            if(isCyclicUtil(neighbor, visited, recStack, adj)){
                return true;
            }
        }
        
        recStack[v] = false;
        return false;
    }
}
