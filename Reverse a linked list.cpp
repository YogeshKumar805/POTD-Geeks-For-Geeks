class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        Node *nextt=head;
        Node *prev=NULL;
        while(nextt){
            nextt=head->next;
            head->next=prev;
            prev=head;
            head=nextt;
            
            
        }
        return prev;
    }
};

