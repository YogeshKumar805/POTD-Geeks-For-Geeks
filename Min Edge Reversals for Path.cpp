class Solution {
  public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        // code here  
        vector<vector<int>>adj(n) , rev_adj(n);
        for(const auto &i: edges){
            adj[i[0]-1].push_back(i[1] -1);
            rev_adj[i[1]-1].push_back(i[0]-1);
        }
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
        pq.push({0 , src-1});
        vector<int>dist(n , INT_MAX);
        while(!pq.empty()){
            auto [cost , node] = pq.top();
            pq.pop();
            if(node == dst -1)return cost;
            if(cost >= dist[node])continue;
            dist[node] = cost;
            for(int i: adj[node]){
                if(dist[i] > dist[node]){
                    pq.push({cost , i});
                }
            }
            for(int &i : rev_adj[node]){
                if(dist[i] > cost +1){
                    pq.push({cost +1 , i});
                }
            }
        }
        return -1;
    }
};
