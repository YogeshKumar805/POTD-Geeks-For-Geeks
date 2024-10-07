class Solution {
    static Node insert(Node head, int data) {
        Node node = new Node(data);
        node.npx = head;
        return node;
    }
    static ArrayList<Integer> getList(Node head) {
        ArrayList<Integer> al = new ArrayList<>();
        while(head != null) {
            al.add(head.data);
            head = head.npx;
        }
        return al;
    }
}
