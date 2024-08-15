class Solution {
  public:
    /* Helper function to take of the recursion */
    int solve(Node* node) {
        int carry = 0;
        if (node->next != NULL) {
            node->data += solve(node->next);
            carry = node->data/10;
            node->data = node->data % 10;
        } else {
            // Base Case
            node->data = node->data + 1;
            carry = node->data / 10;
        }
        return carry;
    }
  
    Node* addOne(Node* head) {
        int carry = solve(head);
        // If there is a carry in the end then create a new node and insert in front of linked list.
        if (carry != 0) {
            Node *temp = new Node(carry);
            temp->next = head;
            head = temp;
        }
        return head;
    }
};
