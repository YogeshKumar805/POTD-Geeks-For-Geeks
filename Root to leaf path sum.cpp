class Solution {
  public:
    bool hasPathSum(Node *root, int target) {
        // Your code here
        if (root == NULL)
            return false;
        if (root->data == target && root->left == NULL && root->right == NULL)
            return true;
        return hasPathSum(root->left, target - root->data) ||
               hasPathSum(root->right, target - root->data);
    }
};
