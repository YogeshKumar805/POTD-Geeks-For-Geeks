class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node* temp=head;
        Node* ne=new Node(data);
        if(head->data>=data)
        {
            while(temp->next!=head)
            temp=temp->next;
            
            temp->next=ne;
            ne->next=head;
            
            return ne;
        }
        while(temp->next!=head)
        {
            if(temp->data<=data && temp->next->data>=data)
            {
                ne->next=temp->next;
                temp->next=ne;
                
                return head;
            }
            temp=temp->next;
        }
        if(temp->data<=data)
        {
            temp->next=ne;
            ne->next=head;
        }
        return head;
        
    }
};

