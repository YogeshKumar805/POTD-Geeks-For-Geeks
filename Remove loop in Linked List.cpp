class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
         Node* fast = head;
        Node* slow = head;
        bool found = false;
        Node* prev = slow;
        while(fast && fast -> next)
        {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast)
            {
                found = true;
                break;
            }
        }
        if(!found)return;
        slow = head;
        while(fast != slow)
        {
            prev = fast;
            slow = slow -> next;
            fast = fast -> next;
        }
        prev -> next = NULL;
    }
};
