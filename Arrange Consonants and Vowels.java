class Solution {
    
    public Node arrangeCV(Node head){
        //write code here and return the head of changed linked list
        
        Node dummyv = new Node(head.data);
        Node vowel = dummyv;
        
        Node dummyc = new Node(head.data);
        Node cons = dummyc;
        
        Node curr = head;
        
        while(curr != null){
            if(curr.data == 'a' || curr.data == 'e' || curr.data == 'i' || curr.data == 'o' || curr.data == 'u'){
                Node newnode = new Node(curr.data);
                dummyv.next = newnode;
                dummyv = newnode;
            }
            else{
                Node newnode = new Node(curr.data);
                dummyc.next = newnode;
                dummyc = newnode;
            }
            
            curr=curr.next;
        }
        
        dummyv.next=cons.next;
        
        return vowel.next;
        
        
    }
}
