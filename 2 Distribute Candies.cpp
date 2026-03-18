class Solution {
  public:
  int lee(Node* r,int &ans){
      if(r==NULL)
      return 0;
      
      int lef=lee(r->left,ans);
      int rig=lee(r->right,ans);
      ans+=(abs(lef)+abs(rig));
      return lef+rig+r->data-1;
  }
    int distCandy(Node* root) {
        // code here
        int ans=0;
        int n=lee(root,ans);
        return abs(ans);
    }
};
