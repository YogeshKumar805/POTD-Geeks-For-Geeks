class Solution {
  public:
   void solve(Node* root, vector<int>&ans){
        if(root == NULL) return ;
        
        solve(root->left,ans);
        ans.push_back(root->data);
        solve(root->right,ans);
   }
    vector<int> getKClosest(Node* root, int target, int k) {
        vector<int>ans;
        solve(root,ans);
        sort(ans.begin(),ans.end());
        int n = ans.size();
        priority_queue<int,vector<int>, greater<int>>q;
        for(int i=0; i<n; i++){
            if(q.size() < k){
                q.push(ans[i]);
            }
            else{
                int t = q.top();
                if(abs(t-target) > abs(ans[i] - target)){
                    q.pop();
                    q.push(ans[i]);
                }
            }
        }
        vector<int>res;
        while(!q.empty()){
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};

