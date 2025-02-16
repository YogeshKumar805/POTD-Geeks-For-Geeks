class Tree
{
    
    // Function to serialize a tree and return a list containing nodes of tree.
    public void inOrder(Node root, ArrayList<Integer>list)
    {
        if(root == null)
        return;
        
        inOrder(root.left, list);
        list.add(root.data);
        inOrder(root.right, list);
    }
    
    public ArrayList<Integer> serialize(Node root)
    {
        // code here
        ArrayList<Integer> list = new ArrayList<>();
        inOrder(root, list);
        return list;
    }
    
    public Node createBST(ArrayList<Integer> arr, int s, int e)
    {
        if(s > e)
        return null;
        
        int mid = (s + e) / 2;
        
        Node root = new Node(arr.get(mid));
        root.left = createBST(arr, s, mid-1);
        root.right = createBST(arr, mid+1, e);
        
        return root;
    }

    // Function to deserialize a list and construct the tree.
    public Node deSerialize(ArrayList<Integer> arr)
    {
        // code here
        return createBST(arr, 0, arr.size()-1); 
    }
};
