class Solution {
  public:
    int solve(Node *root, long long sum, int &k, unordered_map<int,int>& mp)
    {
        if(!root)
        return 0;
        sum += root->data;
        mp[sum]++;
        int res = (k ? 0 : -1) + mp[sum-k] + solve(root->left, sum, k, mp) + solve(root->right, sum, k, mp);
        mp[sum]--;
        return res;
    }
    int sumK(Node *root, int k) {
        unordered_map<int,int> mp = {{0,1}};
        return solve(root, 0, k, mp);
    }
};
