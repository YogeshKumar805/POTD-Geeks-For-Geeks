// User function Template for Java

/*
class Node
{
    int data;
    Node left, right;

    public Node(int d)
    {
        data = d;
        left = right = null;
    }
}

*/
class Solution {
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    public List<Integer> merge(Node root1, Node root2) {
        // Write your code here
        List<Integer> list = new ArrayList<>();
        
        inorder(root1, list);
        inorder(root2, list);
        Collections.sort(list);
        return list;
        
    }
    public static void inorder(Node root, List<Integer> list){
        if(root==null) return;
        inorder(root.left, list);
        list.add(root.data);
        inorder(root.right, list);
    }
    
}
