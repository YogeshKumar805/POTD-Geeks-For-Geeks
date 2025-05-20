class Solution {
  public:
  void Solve(Node* root,int &maxi){
      if(!root)
      return;
      maxi=max(root->data,maxi);
      Solve(root->left,maxi);
      Solve(root->right,maxi);
  }
  void consGraph(vector<int>g[],Node* root){
      if(!root)
      return;
      if(root->left){
          g[root->data].push_back(root->left->data);
          g[root->left->data].push_back(root->data);
      }
      if(root->right){
          g[root->data].push_back(root->right->data);
          g[root->right->data].push_back(root->data);
          
      }
      consGraph(g,root->left);
      consGraph(g,root->right);
  }
    int minTime(Node* root, int target) {
        
        int maxi=INT_MIN;
        Solve(root,maxi);
        vector<int>graph[maxi+1];
        consGraph(graph,root);
        vector<bool>visit(maxi+1,false);
        visit[target]=true;
        queue<pair<int,int>>q;
        q.push({target,0});
        int ans=INT_MIN;
        while(q.empty()==false){
            int u=q.front().first;
            int dist=q.front().second;
            q.pop();
            ans=max(ans,dist);
            for(auto v:graph[u]){
                if(visit[v]==false){
                    q.push({v,dist+1});
                    visit[v]=true;
                }
            }
        }
        return ans;
    }
};

