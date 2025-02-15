class Solution {
  public:
    Node* solve(Node* node, Node* &n1, Node* &n2){
        if(!node)
        return NULL;
        
        if(node==n1 || node==n2)
        return node;
        
        Node * l = solve(node->left,n1,n2);
        Node * r = solve(node->right,n1,n2);
        
        if(!l && !r)
        return NULL;
        
        if(l && r)
        return node;
        
        if(!l)
        return r;
        
        return l;
    }
    Node* LCA(Node* root, Node* n1, Node* n2) {
    //   if(n1==root || n2==root)
    //   return root;
       
       return solve(root,n1,n2);
    }
};
