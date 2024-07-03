class Solution {
    public Node removeAllDuplicates(Node head) {
        // code here
        Node dummy = new Node(0);
        dummy.next = head;
        Node prev = dummy;
        
        while (head != null) {
            if (head.next != null && head.data == head.next.data) {
                while (head.next != null && head.data == head.next.data) {
                    head = head.next;
                }
                prev.next = head.next;
            } else {
                prev = prev.next;
            }
            head = head.next;
        }
        
        return dummy.next;
    }
}
