class Solution {
  public:
    virtual void bfs(Node *r, map<int, int> &mp){
      int i=0;
      queue<pair<Node*, int>> q;
      q.push({r, 0});
      
      while(!q.empty()){
        auto [rr, i]=q.front(); q.pop();
        if(mp.find(i) == mp.end()) mp[i]=rr->data;
        
        if(rr->left) q.push({rr->left, i-1});
        if(rr->right) q.push({rr->right, i+1});
      }
      
      return;
    }
    
    virtual vector<int> topView(Node *root){
      map<int, int> mp;
      bfs(root, mp);
      
      vector<int> ans;
      for(auto x: mp){
        ans.push_back(x.second);  
      }
      return ans;
    }
};

