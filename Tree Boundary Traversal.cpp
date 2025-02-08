class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> result;
        if (root == nullptr)
            return result;
        if (root->left || root->right)
            result.push_back(root->data);
        leftBoundary(root->left, result);
        leafNodesInOrder(root, result);
        stack<int> s;
        rightBoundary(root->right, s);
        while (!s.empty())
        {
            result.push_back(s.top());
            s.pop();
        }
        return result;
    }
    void leftBoundary(Node *root, vector<int> &result)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
            return;
        result.push_back(root->data);
        if (root->left)
            leftBoundary(root->left, result);
        else if (root->right)
            leftBoundary(root->right, result);
    }
    void leafNodesInOrder(Node *root, vector<int> &result)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
        {
            result.push_back(root->data);
            return;
        }
        leafNodesInOrder(root->left, result);
        leafNodesInOrder(root->right, result);
    }
    void rightBoundary(Node *root, stack<int> &s)
    {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr)
            return;
        s.push(root->data);
        if (root->right)
            rightBoundary(root->right, s);
        else if (root->left)
            rightBoundary(root->left, s);
    }
};
