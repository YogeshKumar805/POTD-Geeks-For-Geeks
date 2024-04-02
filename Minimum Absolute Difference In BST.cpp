class Solution
{
    vector<int> v;
    void inorder(Node *root){
        if(!root) return;
        inorder(root->left);
        v.push_back(root->data);
        inorder(root->right);
    }
    public:
    int absolute_diff(Node *root)
    {
        int m=INT_MAX;
       inorder(root);
       for(int i=1;i<v.size();i++){
           int d=abs(v[i-1]-v[i]);
           m=min(m,d);
           
       }
       return m;
    }
};

