class Solution {
  public:
    unordered_map<string,int> mpp;
    vector<Node*> ans;
    vector<Node*> printAllDups(Node* root) {
        dfs(root);
        return ans;
    }
    string dfs(Node* root) {
        if (root == nullptr) {
            return "#";
        }
        string s = to_string(root->data) + "," + dfs(root->left) + "," + dfs(root->right);
        if (mpp[s] == 1) {
            ans.push_back(root);
        }
        mpp[s]++;
        return s;
    }
};

