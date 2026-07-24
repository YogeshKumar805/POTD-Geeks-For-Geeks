/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
public:
    int ans = 1;

    void dfs(Node* root, int len) {
        if (!root) return;

        ans = max(ans, len);

        if (root->left) {
            if (root->left->data == root->data + 1)
                dfs(root->left, len + 1);
            else
                dfs(root->left, 1);
        }

        if (root->right) {
            if (root->right->data == root->data + 1)
                dfs(root->right, len + 1);
            else
                dfs(root->right, 1);
        }
    }

    int longestConsecutive(Node* root) {
        if (!root) return -1;

        dfs(root, 1);

        return (ans == 1) ? -1 : ans;
    }
};
