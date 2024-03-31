class Solution {
    
   static int ans=-1;
    
    public static int findMaxForN(Node root, int n) {
        // Resetting ans to -1 before starting the search
       ans = -1;  
        // Call the inorder function to traverse the tree
        inorder(root, n);
        // Returning ans, which holds the maximum value less than or equal to n
        return ans;
    }
    
    static void inorder(Node root, int n) {
        if (root == null) return;
        if (root.key <= n) {
            ans = Math.max(ans, root.key);
            inorder(root.right, n); // Since root.key <= n, we explore right subtree for potentially greater values.
        } else {
            inorder(root.left, n); // If root.key > n, explore only left subtree.
        }
    }
    
}
