class Solution {
  public:
    virtual int fun(Node *root, int &ans){
        if(!root)
          return 0;

        int l = fun(root->left, ans);
        int r = fun(root->right, ans);
        
        int one = (root->data) + max(0, max(l, r));
        int two = (root->data) + l + r;
        
        ans = max(ans, max(one, two));
        return one;        
    }
  
    int findMaxSum(Node *root) {
        // code here
        int ans = INT_MIN;
        fun(root, ans);
        return ans;
    }
};

