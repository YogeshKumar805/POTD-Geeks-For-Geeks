class Solution {
  public:
    // Function to construct binary tree from parent array.
    Node *createTree(vector<int> parent) {
      map<int,Node*>mp;
      Node* root;
      for (int i=0;i<parent.size();i++)
      {
           Node* curNode;
          if (mp.find(i)==mp.end())
          {
              curNode=new Node(i);
              mp[i]=curNode;
          }
          else curNode=mp[i];
          if (parent[i]==-1)
          {
              root=curNode;
              continue;
          }
         Node* parNode;
          if (mp.find(parent[i])==mp.end())
          {
              parNode=new Node(parent[i]);
              mp[parent[i]]=parNode;
          }
          else parNode=mp[parent[i]];
          
          if (parNode->left==NULL) parNode->left=curNode;
          else parNode->right=curNode;
          
      }
      return root;
    }
};
 

