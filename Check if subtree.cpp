class Solution {
  public:
    pair<bool,string> dfs(Node* root, string target){
        if(!root) return {false, "N"};
        
        auto lefty = dfs(root->left, target);
        auto righty = dfs(root->right, target);
        
        if(lefty.first || righty.first) return {true, ""};
        
        string pattern = lefty.second + '#' + to_string(root->data) + '#' + righty.second;
        
        if(pattern == target) return {true, ""};
        
        return {false, pattern};
    }
    
    string generatePattern(Node* root){
        if(!root) return "N";
        
        string lefty = generatePattern(root->left);
        string righty = generatePattern(root->right);
        
        return lefty + '#' + to_string(root->data) + '#' + righty;
    }
  
    bool isSubTree(Node *root1, Node *root2) {
        string target = generatePattern(root2);
        
        return dfs(root1, target).first;
    }
};
