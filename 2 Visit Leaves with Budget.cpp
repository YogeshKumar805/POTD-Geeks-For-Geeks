class Solution {
  public:
    void collect(Node* node, int depth, vector<int>& leaves) {
        if (!node) return;
        if (!node->left && !node->right) {
            leaves.push_back(depth);
            return;
        }
        collect(node->left, depth + 1, leaves);
        collect(node->right, depth + 1, leaves);
    }

    int getCount(Node *root, int k) {
        vector<int> leaves;
        collect(root, 1, leaves);
        sort(leaves.begin(), leaves.end());
        int count = 0;
        for (int cost : leaves) {
            if (cost > k) break;
            k -= cost;
            count++;
        }
        return count;
    }
};
