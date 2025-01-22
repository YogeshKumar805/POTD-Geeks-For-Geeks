class Solution {
  public:
    Node* reverse(Node* head){
        Node* prev=NULL;
        Node* current=head;
        while(current!=NULL){
            Node* store=current->next;
            current->next=prev;
            prev=current;
            current=store;
        }
        return prev;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        Node* head1=reverse(num1);
        Node* head2=reverse(num2);
        int carry=(head1->data+head2->data)/10;
        Node* newhead=new Node((head1->data+head2->data)%10);
        Node* temp=newhead;
        head1=head1->next;
        head2=head2->next;
        while(head1 && head2){
            int sum=carry+head1->data+head2->data;
            carry=sum/10;
            sum=sum%10;
            Node* newnode=new Node(sum);
            temp->next=newnode;
            temp=newnode;
            head1=head1->next;
            head2=head2->next;
        }
        while(head1){
            int sum=carry+head1->data;
            carry=sum/10;
            sum=sum%10;
            Node* newnode=new Node(sum);
            temp->next=newnode;
            temp=newnode;
            head1=head1->next;
        }
        while(head2){
            int sum=carry+head2->data;
            carry=sum/10;
            sum=sum%10;
            Node* newnode=new Node(sum);
            temp->next=newnode;
            temp=newnode;
            head2=head2->next;
        }
        if(carry){
            Node* newnode=new Node(carry);
            temp->next=newnode;
        }
        newhead=reverse(newhead);
        while(newhead->data==0){
              Node* store=newhead->next;
              newhead->next=NULL;
              newhead=store;
        }
        return newhead;
        
    }
};
