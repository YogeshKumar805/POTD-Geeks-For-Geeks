class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
      vector<int> array;
    vector<int> serialize(Node *root) //storing elements in array using inorder traversal
    {
        //Your code here
      if(root==NULL){
          return array;
      }
          serialize(root->left);
          if(root->data>0 and root->data<=1000000009)
          array.push_back(root->data);
          serialize(root->right);
      return array;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       Node* root = NULL;
       int l = A.size();
       
      for(int i=0;i<l;i+=3){ //creating tree using inorder traversal
           Node* lft;
           Node* rt;
           Node* ryt;
           
          if(root==NULL){
          lft = new Node(A[i]);
          root=lft;
          }
          else{
              lft = new Node(A[i]);
             Node* temp =  lft;
             lft->left = root;
             root = lft;
          }
          
          if(i+1 < l){
           rt = new Node(A[i+1]);
              rt->left=lft;
              root = rt;
              
          }if(i+2 < l){
          ryt = new Node(A[i+2]);
          root->right=ryt;
          }
          
      }
       
       return root;
    }

};

