class Solution {

    // Return the sum of last k nodes
    public int sumOfLastN_Nodes(Node head, int n) {
        // write code here
        Node temp=head;
        Node actual=head;
        int diff=0;
        int tempn=0;
        int actualn=0;
        int ans=0;
        
        while(temp.next!=null){
            tempn++;
            temp=temp.next;
           
            diff=tempn-actualn;
            if(diff==n){
                actualn++;
                actual=actual.next;
                
            }
            
        }
        
        while(actual!=null){
            ans+=actual.data;
            actual=actual.next;
            
        }
        return ans;
    }
}
