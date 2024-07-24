class Solution {
    // Function to check whether a Binary Tree is BST or not.
    private int MIN = 0;
    private int MAX = 100001;
    
    boolean isbst(Node root, int min, int max) {
        if (root == null)
            return true;
        if (root.data <= min || root.data >= max)
            return false;
            
        return isbst(root.left, min, root.data) 
            && isbst(root.right, root.data, max);
    }
    
    boolean isBST(Node root) {
        // code here.
        return isbst(root, MIN, MAX);
    }
}
