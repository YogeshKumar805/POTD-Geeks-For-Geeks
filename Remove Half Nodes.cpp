class Solution {
  public:
    Node* helper(Node* node){
        if(!node) return nullptr;
        if(!node->left && !node->right) return node;
        
        node->left = helper(node->left);
        node->right = helper(node->right);
        
        if((node->left != nullptr && node->right != nullptr)) return node;
        
        if(!node->left){
            return node->right;
        }
        if(!node->right){
            return node->left;
        }
    }
    Node *RemoveHalfNodes(Node *root) {
        // code here
        return helper(root);
        // return root;
    }
};

