/* Structure for Tree Node
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
    
    int solve(Node* root) {
        
        if (root == NULL)
            return 0;
        
        int leftSum = solve(root->left);
        
        int rightSum = solve(root->right);
        
        int originalValue = root->data;
        
        root->data = leftSum + rightSum;
        
        return originalValue + root->data;
    }
    
    void toSumTree(Node *root) {
        
        solve(root);
    }
};
