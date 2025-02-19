class Solution {
    // Function to merge K sorted linked list.
    Node mergeKLists(List<Node> arr) {
        // Add your code here.
        PriorityQueue<Node>pq=new PriorityQueue<>((a,b) -> a.data-b.data);
        for(int i=0;i<arr.size();i++){
            pq.add(arr.get(i));
        }
        Node head1=new Node(-1);
        Node dummy=head1;
        while(!pq.isEmpty()){
            Node minNode=pq.poll();
            head1.next=minNode;
            head1=head1.next;
            if(minNode.next!=null){
                pq.add(minNode.next);
            }
        }
        return dummy.next;
    }
}
