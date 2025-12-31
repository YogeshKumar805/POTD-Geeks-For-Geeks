class Solution {
  public:
    bool isPalindrome(Node *head) {
        if (!head || !head->next) return true;
        
        Node *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node *prev = NULL, *curr = slow, *next = NULL;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        Node *left = head, *right = prev;
        while (right) {
            if (left->data != right->data) return false;
            left = left->next;
            right = right->next;
        }
        
        return true;
    }
};
