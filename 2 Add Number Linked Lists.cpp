class Solution {
  public:
    Node* rev(Node* head){
        Node* node=head, *prev=NULL;
        while(node){
            Node* nxt=node->next;
            node->next=prev;
            prev=node;
            node=nxt;
        }
        return prev;
    }
  
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        Node* h1=rev(head1);
        Node* h2=rev(head2);
        
        int carry=0;
        
        Node* node1=h1, *node2=h2;
        Node* d=new Node(-1);
        Node* nxt=d;
        
        while(node1 && node2){
            int sum=node1->data+node2->data+carry;
            carry=sum/10;
            sum%=10;
            Node* newNode=new Node(sum);
            nxt->next=newNode;
            nxt=newNode;
            node1=node1->next;
            node2=node2->next;
        }
        
        while(node1){
            int sum=node1->data+carry;
            carry=sum/10;
            sum%=10;
            Node* newNode=new Node(sum);
            nxt->next=newNode;
            nxt=newNode;
            node1=node1->next;
        }
        
        while(node2){
            int sum=node2->data+carry;
            carry=sum/10;
            sum%=10;
            Node* newNode=new Node(sum);
            nxt->next=newNode;
            nxt=newNode;
            node2=node2->next;
        }
        
        if(carry>0){
            Node* newNode=new Node(carry);
            nxt->next=newNode;
            nxt=newNode;
            carry=0;
        }
        
        Node *node=rev(d->next);
        while(node && node->data==0){
            node=node->next;
        }
        return node?node:new Node(0);
    }
};
