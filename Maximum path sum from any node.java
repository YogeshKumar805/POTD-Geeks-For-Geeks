class Solution
{
    int maxSum = Integer.MIN_VALUE;
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node node)
    {
        //your code goes here
        if(node == null)
            return 0;
        int MaxSum = traverse(node);
        
        return maxSum;
    }
    
    public int traverse(Node node) {
        if(node == null)
            return 0;
            
        int ls =  traverse(node.left);
        
        int rs =  traverse(node.right);
        
        int single_max = Math.max((node.data + Math.max(ls, rs) ),node.data);
        
        maxSum = Math.max(Math.max(single_max, node.data + ls + rs), maxSum);
       
        return single_max;
        
    }
}
