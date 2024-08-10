class Solution {
    // Function to rotate a linked list.
    public Node rotate(Node head, int k) {
        // add code here
        Node ptr=head;
        while(ptr.next!=null){
            ptr=ptr.next;
        }
        ptr.next=head;
        
        Node prev=null,curr;
        curr=head;
        while(k!=0){
            prev=curr;
            curr=curr.next;
            k--;
        }
        
        prev.next=null;
        head=curr;
        
        return head;
        
        
    }
    
}
