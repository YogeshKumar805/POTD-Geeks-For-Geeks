class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj[V];
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pair<int,int>, vector<pair<int, int>>,
        greater<pair<int, int>>>pq;
        vector<int>time(V, 1e9);
        vector<int>ways(V, 0);

        pq.push({0, 0});
        time[0]=0;
        ways[0]=1;

        while(!pq.empty()){
            auto [t, node]=pq.top();
            pq.pop();
            
            for(auto &it:adj[node]){
                int adjN=it[0];
                int adjW=it[1];
                if(t+adjW<time[adjN]){
                    time[adjN]=t+adjW;
                    ways[adjN]=ways[node];
                    pq.push({time[adjN], adjN});
                }else if(t+adjW==time[adjN]){
                    ways[adjN]+=ways[node];
                }
            }
        }

        return ways[V-1];        
    }
};
