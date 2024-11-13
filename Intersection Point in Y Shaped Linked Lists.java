class Intersect {
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node head1, Node head2) {
        // code here
        Node pt1;
        Node pt2;
        pt1=head1;
        pt2=head2;
        if (head1==null && head2==null){
            return -1;
        }
        while(pt1!=pt2){
            if(pt1==null){
                pt1=head2;
            }
            else{
                pt1=pt1.next;
            }
             if(pt2==null){
                pt2=head1;
            }
            else{
                pt2=pt2.next;
            }
            
        }
        if(pt1!=null){
                return pt1.data;
            }
            else{
                return -1;
            }
        
        
    }
}

