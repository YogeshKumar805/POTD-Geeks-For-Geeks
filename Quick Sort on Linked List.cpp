class Solution {
public:
    struct Node* getTail(struct Node* head) {
        while (head != nullptr && head->next != nullptr) {
            head = head->next;
        }
        return head;
    }

    // Partition the linked list and return the pivot.
    struct Node* partition(struct Node* head, struct Node* end, struct Node** newHead, struct Node** newEnd) {
        Node* pivot = end;
        Node *smallerHead = nullptr, *smallerTail = nullptr;
        Node *greaterHead = nullptr, *greaterTail = nullptr;
        Node* cur = head;

        while (cur != pivot) {
            Node* next = cur->next;
            cur->next = nullptr;

            if (cur->data < pivot->data) {
                if (!smallerHead) {
                    smallerHead = smallerTail = cur;
                } else {
                    smallerTail->next = cur;
                    smallerTail = cur;
                }
            } else {
                if (!greaterHead) {
                    greaterHead = greaterTail = cur;
                } else {
                    greaterTail->next = cur;
                    greaterTail = cur;
                }
            }
            cur = next;
        }

        // Combine smaller list, pivot, and greater list.
        if (smallerTail) {
            *newHead = smallerHead;
            smallerTail->next = pivot;
        } else {
            *newHead = pivot;
        }

        pivot->next = greaterHead;
        *newEnd = greaterTail ? greaterTail : pivot;

        return pivot;
    }

    struct Node* quickSortRecur(struct Node* head, struct Node* end) {
        if (!head || head == end) return head;

        Node *newHead = nullptr, *newEnd = nullptr;
        Node* pivot = partition(head, end, &newHead, &newEnd);

        if (newHead != pivot) {
            Node* tmp = newHead;
            while (tmp->next != pivot) {
                tmp = tmp->next;
            }
            tmp->next = nullptr;

            newHead = quickSortRecur(newHead, tmp);

            tmp = getTail(newHead);
            tmp->next = pivot;
        }

        pivot->next = quickSortRecur(pivot->next, newEnd);

        return newHead;
    }

    struct Node* quickSort(struct Node* head) {
        Node* tail = getTail(head);
        return quickSortRecur(head, tail);
    }
};
