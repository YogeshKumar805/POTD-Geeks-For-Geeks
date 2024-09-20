class Solution {
  public:
    Node *copyList(Node *head) {
        // Write your code here
         if (!head) {
        return NULL;
    }

    Node* current = head;
    while (current) {
        Node* newNode = new Node(current->data);
        newNode->next = current->next;
        current->next = newNode;
        current = newNode->next;
    }

    current = head;
    while (current) {
        if (current->random) {
            current->next->random = current->random->next;
        }
        current = current->next->next;
    }

    Node* newHead = head->next;
    current = head;
    while (current) {
        Node* temp = current->next;
        current->next = temp->next;
        if (temp->next) {
            temp->next = temp->next->next;
        }
        current = current->next;
    }

    return newHead;
    }
};
