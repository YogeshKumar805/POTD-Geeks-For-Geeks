class Solution {
    void preorder(Node *root, vector<int> sublist, vector<vector<int>> &list){
        if(root == NULL)
            return;
        
        sublist.push_back(root->data);
        if(root->left == NULL && root->right == NULL){
            list.push_back(sublist);
            sublist.pop_back();
            return;
        }
        
        preorder(root->left, sublist, list);
        preorder(root->right, sublist, list);
    }
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> list;
        if(root == NULL)
            return list;
            
        vector<int> sublist;
        preorder(root, sublist, list);
        return list;
    }
};
