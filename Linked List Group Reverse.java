class Solution {
    public static Node reverseKGroup(Node head, int k) {
        // code here
        Node next=null;
        Node prev=null;
        Node cur=new Node(0);
        cur.next=head;
        Node curr=head;
        Node currprev=null;
        while(curr!=null){
            int c=0;
            currprev=prev;
            prev=null;
            while(curr!=null && c<k){
            next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
            c++;
            }
             if(currprev==null ){
                cur.next=prev;
            }
            else if(currprev!=null){
            while(currprev.next!=null){
                currprev=currprev.next;
            }
            currprev.next=prev;
                
            }
            
          
         }
        return cur.next;
       
    }
}

