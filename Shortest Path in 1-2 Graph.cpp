class Solution {
  public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        int totalNodes = V;

        vector<vector<int>> adj(V + edges.size());

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (w == 1) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            } else {
                int newNode = totalNodes++;

                adj[u].push_back(newNode);
                adj[newNode].push_back(u);

                adj[newNode].push_back(v);
                adj[v].push_back(newNode);
            }
        }

        vector<int> dist(totalNodes, -1);

        queue<int> q;

        q.push(src);
        dist[src] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int next : adj[node]) {
                if (dist[next] == -1) {
                    dist[next] = dist[node] + 1;
                    q.push(next);
                }
            }
        }

        return dist[dest];
    }
};
