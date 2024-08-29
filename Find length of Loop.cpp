class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;
        bool f = false;

        // Detect the loop using Floyd's Cycle Detection algorithm
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                f = true;
                break;
            }
        }

        // If no loop is found, return 0
        if (!f) {
            return 0;
        }

        // Find the start of the loop
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        // Count the number of nodes in the loop
        int cnt = 1;
        slow = slow->next;
        while (slow != fast) {
            slow = slow->next;
            cnt++;
        }

        return cnt;
    }
};

