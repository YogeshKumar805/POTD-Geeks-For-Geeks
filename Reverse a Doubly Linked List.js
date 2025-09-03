class Solution {
    reverse(head) {
        let ans=[];
        let newHead=head;
        while (newHead){
            ans.push(newHead.data);
            newHead=newHead.next;
        }
            
        let current=head;
        while (current){
             current.data=ans.pop();
            current=current.next;
        }
           
        return head
        
    }
}
