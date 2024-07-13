class Solution {
    public List<Integer> shortestPath(int n, int m, int edges[][]) {
        //  Code Here.
        //Initialization of adjacencylist 
        List<List<int[]>> adj=new ArrayList<>();
        for(int i=0;i<=n;i++) adj.add(new ArrayList<>());
        for(int[] e:edges){
            adj.get(e[0]).add(new int[]{e[1],e[2]});
            adj.get(e[1]).add(new int[]{e[0],e[2]});
        }
        //Iitialization of distances as max and parents
        int dis[]=new int[n+1],parent[]=new int[n+1];
        Arrays.fill(dis,(int)(1e9));
        Queue<int[]> pq=new PriorityQueue<>((x,y)->x[1]-y[1]); //sort based on distances
        pq.add(new int[]{1,0});
        dis[1]=0;
        //traversal and finding the minimum distances
        while(!pq.isEmpty()){
            int[] curr=pq.poll();
            int u=curr[0],d=curr[1]; //u->current node, d->distance from 1
            if(d>dis[u]) continue;
            for(int[] a:adj.get(u)){
                int v=a[0],w=a[1]; //v->node connected to u, w->distance from u to v
                if(dis[u]+w<dis[v]){
                    dis[v]=dis[u]+w;
                    parent[v]=u;
                    pq.add(new int[]{v,dis[v]});
                }
            }
        }
        //If from 1-n not possible 
        if(dis[n]==(int)(1e9)) return Arrays.asList(-1);
        //find the shortest path from n to 1 and then reverse it
        List<Integer> ans=new ArrayList<>();
        int node=n;
        while(node!=0){
            ans.add(node);
            node=parent[node];
        }
        ans.add(dis[n]);
        Collections.reverse(ans);
        return ans;
    }
}
