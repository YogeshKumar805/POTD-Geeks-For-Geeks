class Solution {
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> outDeg(V, 0);
        vector<vector<int>> adj(V);
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            adj[v].push_back(u);
            outDeg[u]++;
        }
        queue<int> q;
        for (int i = 0; i < V; i++){
            if (outDeg[i]==0) q.push(i);
        }
        vector<int> ans;
        while (!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (int& nbr : adj[node]){
                outDeg[nbr]--;
                if (outDeg[nbr]==0) q.push(nbr);
            }
        }
        return ans;
    }
};
