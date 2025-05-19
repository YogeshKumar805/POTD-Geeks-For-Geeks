class Solution {
  public:
    Node* pre=nullptr, *suc=nullptr;
    void inorder(Node* node, vector<Node*>& inorderList, int key){
        if(!node) return;
        inorder(node->left, inorderList, key);
        inorderList.push_back(node);
        inorder(node->right, inorderList, key);
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> inorderList;
        inorder(root, inorderList, key);
        Node* pre=nullptr, *cur=nullptr, *suc=nullptr;
        for(int i=0; i<inorderList.size(); i++){
            cur = inorderList[i];
            pre = (i>0)?inorderList[i-1]:nullptr;
            suc = (i+1<inorderList.size())?inorderList[i+1]:nullptr;
            if(cur->data == key){
                return {pre, suc};
            }else if(key > cur->data && suc && key < suc->data ){
                return {cur,suc};
            }else if(key < cur->data && pre && key > pre->data){
                return {pre,cur};
            }
        }
        return {inorderList.back(),nullptr};
    }
};
