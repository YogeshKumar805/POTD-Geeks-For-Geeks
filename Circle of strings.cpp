class Solution {
  public:
   void dfs(char node, unordered_map<char, list<char>>&adj, vector<bool>&visited){
       int idx = node-'a';
       visited[idx] = true;
       for(auto nbr : adj[node]){
           if(!visited[nbr-'a']){
               dfs(nbr, adj, visited);
           }
       }
   }
    int isCircle(vector<string> &arr) {
       unordered_map<char, list<char>>adj;
       vector<int> in_degree(26, 0);
    vector<int> out_degree(26, 0);
       for(auto str: arr){
           int n = str.size();
           char u = str[0];
           char v = str[n-1];
           adj[u].push_back(v);
            out_degree[u - 'a']++;
        in_degree[v - 'a']++;
       }
        for (int i = 0; i < 26; ++i) {
        if (in_degree[i] != out_degree[i]) {
            return 0;
        }
    }
       vector<bool>visited(26, 0);
       dfs(arr[0][0], adj, visited);
       for(auto m : adj){
           if(!visited[m.first-'a']){
               return 0;
           }
       }
       return 1;
    }
};
