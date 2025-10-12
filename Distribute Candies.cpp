class Solution {
  public:
    int ans = 0 ;
    int f(Node*root){
        if(root == NULL) return 0 ;
        int l = f(root -> left) ;
        int r = f(root -> right) ;
        int need = 0 , surp = 0 ; 
        if(l > 0) surp += l ;
        if(l < 0) need += abs(l) ;
        if(r > 0) surp += r ;
        if(r < 0) need += abs(r) ;
        ans += (surp + need) ;
        need ++ ;
        surp += root -> data ;
        return surp - need ;
    }
    int distCandy(Node* root) {
        f(root) ;
        return ans ;
    }  
};
