class Solution {
  private:
    void dfs(vector<int>& v, int curr, Node* node)
    {
        curr = curr * 10 + node->data;
        if(node->left == nullptr && node->right == nullptr)
        {
            v.push_back(curr);
        }
        else
        {
            if(node->left)
            {
                dfs(v, curr, node->left);
            }
            if(node->right)
            {
                dfs(v, curr, node->right);
            }
        }
        curr = curr / 10;
    }
  public:
    int treePathsSum(Node *root) {
        // code here.
        vector<int> v;
        dfs(v, 0, root);
        int ans = 0;
        for(auto it : v)
        {
            ans += it;
        }
        return ans;
    }
};
