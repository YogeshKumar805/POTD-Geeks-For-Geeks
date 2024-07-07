class Solution {

    public ArrayList<Integer> Ancestors(Node root, int target) {
        // add your code here
        
        ArrayList<Integer> list = new ArrayList<>();
        
        find(root , target , list);
        
        return list;
    }
    
    public static boolean find(Node root , int key , ArrayList<Integer> list){
        if(root == null)    return false;
        
        if(root.data == key)    return true;
        
        boolean left = find(root.left , key ,list);
        boolean right = find(root.right , key , list);
        
        if(left || right)   list.add(root.data);
        
        return left||right;
    }
}
