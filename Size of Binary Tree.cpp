class Solution {
  public:
    int getSize(Node* root) {
        if(!root) return 0;
        return 1 + getSize(root->left) + getSize(root->right);
    }
};
