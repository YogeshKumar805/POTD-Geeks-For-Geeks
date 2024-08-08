class Solution {
  private:
    bool res=true;
  public:
    int f(Node* n){
        if(!n)return 0;
        int ls=f(n->left),rs=f(n->right);
        if(!n->left && !n->right)
            return n->data;
        if(n->data!=ls+rs)
            res=false;
        return n->data+ls+rs;
    }
    bool isSumTree(Node* root) {
        f(root);
        return res;
    }
};
