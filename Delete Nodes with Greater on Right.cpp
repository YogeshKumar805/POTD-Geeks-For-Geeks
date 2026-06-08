class Solution {
public:

    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;

        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    Node* compute(Node* head) {

        if (!head || !head->next)
            return head;

        head = reverse(head);

        int mx = head->data;
        Node* curr = head;

        while (curr && curr->next) {

            if (curr->next->data < mx) {
                curr->next = curr->next->next;
            }
            else {
                curr = curr->next;
                mx = curr->data;
            }
        }

        return reverse(head);
    }
};
