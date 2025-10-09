class Solution {
  public:
    vector<int> ans;
    void solve(Node* root){
        if(root == NULL){
            return;
        }
        
        solve(root->left);
        solve(root->right);
        ans.push_back(root->data);
        
    }
    vector<int> postOrder(Node* root) {
        // code here
    
        solve(root);
        return ans;
        
    }
};

