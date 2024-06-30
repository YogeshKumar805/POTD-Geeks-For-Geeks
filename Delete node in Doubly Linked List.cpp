class Solution {
public:
    Node* deleteNode(Node* head, int x) {
        if (head == nullptr || x <= 0) {
            return head;
        }

        Node* curr = head;

        // If x == 1, we need to delete the head node
        if (x == 1) {
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete curr;
            return head;
        }

        // Move to the (x-1)-th node
        for (int i = 1; curr != nullptr && i < x - 1; i++) {
            curr = curr->next;
        }

        // If position x is out of bounds
        if (curr == nullptr || curr->next == nullptr) {
            return head;
        }

        Node* toDelete = curr->next;
        curr->next = toDelete->next;
        
        if (toDelete->next != nullptr) {
            toDelete->next->prev = curr;
        }

        delete toDelete;

        return head;
    }
};
