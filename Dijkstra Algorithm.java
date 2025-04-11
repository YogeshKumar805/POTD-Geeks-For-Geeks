class Solution 
{
    public int[] dijkstra(int V, int[][] edges, int src){
        
        List<List<int[]>> adj = new ArrayList<>();
        
        for(int i=0;i<V;i++)
            adj.add(new ArrayList<>());
        
        for(int[] edge: edges){
            
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj.get(u).add(new int[]{u,w});
            adj.get(v).add(new int[]{u,w});
        }
        
        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)-> a[1]-b[1]);
        pq.add(new int[]{src,0});
        
        while(!pq.isEmpty()){
            
            int [] curr = pq.poll();
            int u = curr[0];
            int d = curr[1];
            
            if(d>dist[u]) continue;
            
            for(int[] neighbor : adj.get(u)){
                int v = neighbor[0];
                int w = neighbor[1];
                
                if(dist[u]+w<dist[v]){
                    dist[v]= dist[u]+w;
                    pq.add(new int[]{v,dist[v]});
                }
            }
        }
        return dist;
    }
}

