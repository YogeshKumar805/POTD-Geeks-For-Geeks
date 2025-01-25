class Solution {
    public static Node findFirstNode(Node head) {
        // code here
        Node slow = head;
        Node fast = head;
        Node temp = new Node(-1);
        while(fast != null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast){
                slow = head;
               while(slow != fast){
                   slow = slow.next;
                   fast = fast.next;
               } 
               return slow;
            }
        }
        return temp;
    }
}
