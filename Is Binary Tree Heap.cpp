class Solution {
  public:
    vector<int>solveRec(Node*root){
        if(root==NULL){
            return {true,0,0,0}; //isheap, maxDepth, maxElement, minDepth
        }
        
        auto left=solveRec(root->left);
        auto right=solveRec(root->right);
        
        bool curAns=(left[1]==right[1] || left[1]-right[1]==1) && 
                    (left[3]>=right[1]) && 
                    (root->data>=left[2]) && 
                    (root->data>=right[2]);
                    
        return {curAns && left[0] && right[0],
                max(left[1],right[1])+1,
                max(left[2],max(right[2],root->data)),
                min(left[3],right[3])+1
            };
    }
    
    bool isHeap(Node* tree) {
        // code here
        return solveRec(tree)[0];
    }
};
