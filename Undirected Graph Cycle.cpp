class Solution {
  public:
    bool solve(int index,unordered_map<int,bool> &visit,vector<vector<int>> adj){
    unordered_map<int,int> parent;

    parent[index] = -1;

    queue<int> q;
    q.push(index);
    visit[index] = 1;

    while(!q.empty()){
        int f = q.front();
        q.pop();

        for(auto i : adj[f]){
            if((visit[i] == true )&& (i != parent[f])){
                return true;
            }else if(visit[i] == 0){
                q.push(i);
                visit[i] = true;
                parent[i] = f;
            }
        }
    }

    return false;
}
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        unordered_map<int,bool> visit;

        for(int i = 0;i<V;i++){
        if(visit[i] == 0){
            bool ans = solve(i,visit,adj);
            if(ans == 1){
                return true;
                }
            }
        }

        return false;
    }
};

