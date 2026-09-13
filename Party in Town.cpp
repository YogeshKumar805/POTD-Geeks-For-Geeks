class Solution {
  public:
    int partyHouse(vector<vector<int>> &adj) {
        int n = adj.size();
        if (n == 1) return 0;
        
        auto bfs = [&](int start) {
            vector<int> dist(n, -1);
            queue<int> q;
            q.push(start);
            dist[start] = 0;
            int far = start;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    int idx = v - 1;
                    if (dist[idx] == -1) {
                        dist[idx] = dist[u] + 1;
                        q.push(idx);
                        if (dist[idx] > dist[far]) far = idx;
                    }
                }
            }
            return make_pair(far, dist[far]);
        };
        
        auto [u, _] = bfs(0);
        auto [v, diameter] = bfs(u);
        
        return (diameter + 1) / 2;
    }
};
