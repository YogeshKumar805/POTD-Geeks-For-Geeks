class Solution {
  public:
    // Function to find the vertical width of a Binary Tree.
    int mini = INT_MAX;
    int maxi = -1;
    void solve(Node* root,int i){
        if (!root){
            return ;
        }
        mini = min(i,mini);
        maxi = max(maxi,i);
        solve(root->left,i-1);
        
        solve(root->right,i+1);
        
    }
    int verticalWidth(Node* root) {
        // code here
        if (!root) return 0;
        int i =0,j=0;
        solve(root,i);
        return maxi-mini+1;
    }
};

