class Tree
{
    //Function to return list containing elements of left view of binary tree.
    ArrayList<Integer> leftView(Node root)
    {
ArrayList<Integer> list = new ArrayList<>();
    if (root == null) return list;

    Queue<Node> queue = new LinkedList<>();
    queue.add(root);

    while (!queue.isEmpty()) {
        int levelSize = queue.size();
        list.add(queue.peek().data); // Add leftmost node

        for (int i = 0; i < levelSize; i++) {
            Node node = queue.poll();
            if (node.left != null) queue.add(node.left);
            if (node.right != null) queue.add(node.right);
        }
    }
    return list;
    }
}
