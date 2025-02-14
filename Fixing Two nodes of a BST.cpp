class Solution {
  public:
 Node* first = nullptr, *second = nullptr, *prev = nullptr;
  void Solve(Node* root){
       if (!root) return;
        
        Solve(root->left);
        
        if (prev && root->data < prev->data) {
            if (!first) {
                first = prev;
            }
            second = root;
        }
        prev = root;
        
        Solve(root->right);
  }
    void correctBST(Node* root) {
         Solve(root);
        if (first && second) swap(first->data, second->data);
    }
};
