class Solution {
    ArrayList<Integer> ans;
    // Return the Kth smallest element in the given BST
    public int kthSmallest(Node root, int k) {
        // Write your code here
        ans = new ArrayList<>();
        inorder(root);
        if(ans.size() >= k){
            return ans.get(k-1);
        }
        return -1;
    }
    
    void inorder(Node root){
        if(root==null){
            return;
        }
        inorder(root.left);
        ans.add(root.data);
        inorder(root.right);
    }
}
