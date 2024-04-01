// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:
    #define append push_back
    vector<int> v;
    vector<int> bit;
    void update(int i, int val, int n) {
    for(; i <= n; i += i&-i)
        bit[i] += val;
}

int query(int i) {
    int sum = 0;
    for(; i > 0; i -= i&-i)
        sum += bit[i];
    return sum;
}
    void dfs(Node *root){
        if (root->left!=nullptr) dfs(root->left);
        v.append(root->data);
        if (root->right!=nullptr) dfs(root->right);
    }
    int pairsViolatingBST(int n, Node *root) {
        dfs(root);
        int ans=0;
        bit.resize(n+1, 0);
    vector<pair<int, int>> pairs(n);
    for(int i = 0; i < n; i++)
        pairs[i] = {v[i], i+1};
    sort(pairs.rbegin(), pairs.rend());
    for(auto &p : pairs) {
        ans+=query(p.second-1);
        update(p.second, 1, n);
    }
        return ans;
    }
};
