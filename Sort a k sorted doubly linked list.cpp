class Solution {
  public:
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        DLLNode* ptr=head;
        DLLNode* curr=head;
        DLLNode* ans=NULL;
        while(k>=0 && ptr!=NULL){
            pq.push(ptr->data);
            ptr=ptr->next;
            k--;
        }
        while(ptr!=NULL){
            curr->data=pq.top();
            pq.pop();
           if(ans==NULL)
           ans=curr;
            pq.push(ptr->data);
            ptr=ptr->next;
            curr=curr->next;
        }
        while(pq.empty()==false){
            curr->data=pq.top();
            pq.pop();
            if(ans==NULL)
           ans=curr;
            curr=curr->next;
        }
        return ans;
    }
};
