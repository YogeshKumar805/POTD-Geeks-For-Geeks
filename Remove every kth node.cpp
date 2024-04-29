class Solution {
    public:
    Node* deleteK(Node *head,int K){
      //Your code here
      if(K==1){
          return NULL;
      }
      int count = 1;
      Node* prev = NULL;
      Node* temp = head;
      while(temp!=NULL){
          prev = temp;
          temp = temp->next;
          count++;
          if(count==K){
              if(!temp){
                  break;
              }
              prev->next=temp->next;
              count=1;
              prev = prev->next;
              temp = temp->next;
          }
      }
      return head;
    }
};
