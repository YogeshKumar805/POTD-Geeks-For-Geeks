class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        if(!head || (!head->next)) return 0;
        Node *slow= head->next, *fast = head->next->next;
        while(fast!= NULL && slow!= NULL && slow!= fast){
            if(fast->next== 0 || fast->next->next== 0) return 0;
            slow= slow->next;
            fast= fast->next->next;
            
        }
        if(!fast) return 0;
            int cnt= 1;
            slow= slow->next;
            while(slow!= fast){
                cnt++;
                slow= slow->next;
            }
          return cnt;
    }
};

