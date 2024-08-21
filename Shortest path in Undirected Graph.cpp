class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int>adj[N];
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>dist(N,INT_MAX);
        vector<bool>visit(N,false);
        dist[src]=0;
        visit[src]=true;
        queue<int>q;
        q.push(src);
        while(q.empty()==false){
            int u=q.front();
            q.pop();
            for(auto v:adj[u]){
                if(visit[v]==false){
                    dist[v]=dist[u]+1;
                    q.push(v);
                    visit[v]=true;
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX)
            dist[i]=-1;
        }
        return dist;
    }
};

