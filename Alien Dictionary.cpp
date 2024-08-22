class Solution {
  public:
    void dfs(int cur,unordered_map<int,list<int>>&adj,vector<bool>&vis,stack<int>&st){
        vis[cur]=1;
        for(auto i:adj[cur]){
            if(!vis[i]){
                dfs(i,adj,vis,st);
                st.push(i);
            }
        }
        return;
    }
    string findOrder(string dict[], int n, int k) {
        unordered_map<int,list<int>>adj;
        vector<int>inDegree(k);
        for(int i=0;i<n-1;i++){
            int len=min(dict[i].length(),dict[i+1].length());
            for(int j=0;j<len;j++){
                if(dict[i][j]!=dict[i+1][j]){
                    adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                    inDegree[dict[i+1][j]-'a']++;
                    break;
                }
            }
        }
        vector<bool>vis(k);
        stack<int>st;
        for(int i=0;i<k;i++){
            if(inDegree[i]==0 && !vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        string ans="";
        while(!st.empty()){
            int temp=st.top();
            ans+=('a'+temp);
            st.pop();
        }
        return ans;
    }
};
