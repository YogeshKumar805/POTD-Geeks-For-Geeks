class Solution {
  public:
    #define pii pair<int, int>
    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {
        vector<int>MinCostToReachA(V, INT_MAX);
        vector<int>MinCostToReachB(V, INT_MAX);
        MinCostToReachB[b] = 0;
        MinCostToReachA[a] = 0;
        map<int, vector<pair<int, int>>>g;
        for(auto &edge : edges)
        {
            int x = edge[0], y = edge[1], w1 = edge[2], w2 = edge[3];
            g[x].push_back({y, w1});
            g[y].push_back({x, w1});
        }
        
        priority_queue<pii, vector<pii>, greater<pii>>pq;
        pq.push({0, a});
        while(pq.size())
        {
            auto cur = pq.top();
            pq.pop();
            int node = cur.second, cost = cur.first;
            if(cost > MinCostToReachA[node])
            {
                continue;
            }
            for(auto &ch : g[node])
            {
                int nxt = ch.first, wt = ch.second;
                if(MinCostToReachA[nxt] > wt + MinCostToReachA[node])
                {
                    MinCostToReachA[nxt] = wt + MinCostToReachA[node];
                    pq.push({MinCostToReachA[nxt], nxt});
                }
            }
        }
        pq.push({0, b});
        while(pq.size())
        {
            auto cur = pq.top();
            pq.pop();
            int node = cur.second, cost = cur.first;
            if(cost > MinCostToReachB[node])
            {
                continue;
            }
            for(auto &ch : g[node])
            {
                int nxt = ch.first, wt = ch.second;
                if(MinCostToReachB[nxt] > wt + MinCostToReachB[node])
                {
                    MinCostToReachB[nxt] = wt + MinCostToReachB[node];
                    pq.push({MinCostToReachB[nxt], nxt});
                }
            }
        }
        int ans = min(MinCostToReachA[b], MinCostToReachB[a]);
        for(auto &edge : edges)
        {
            int x = edge[0], y = edge[1], w1 = edge[2], w2 = edge[3];
            if(MinCostToReachA[x] != INT_MAX && MinCostToReachB[y] != INT_MAX)
            {
                int tmp = MinCostToReachA[x] + MinCostToReachB[y] + w2;
                if(tmp < ans)ans = tmp;
            }
            if(MinCostToReachA[y] != INT_MAX && MinCostToReachB[x] != INT_MAX)
            {
                int tmp = MinCostToReachA[y] + MinCostToReachB[x] + w2;
                if(tmp < ans)ans = tmp;
            }
        }
        if(ans == INT_MAX)ans = -1;
        return ans;
        
    }
};
