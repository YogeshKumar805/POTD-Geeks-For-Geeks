class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        
        vector<int> res;
        recurssion(root,0, res);
        return res;
        
    }
    
    void recurssion(Node *root, int level, vector<int> &res){
        
        if(root==NULL){
            return;
        }
        
        if(level==res.size()){
            res.push_back(root->data);
        }
        
        recurssion(root->left,level+1,res);
        recurssion(root->right,level+1,res);
    }
    
    
};

