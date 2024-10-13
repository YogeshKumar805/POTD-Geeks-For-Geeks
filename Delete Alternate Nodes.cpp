class Solution {
  public:
    void deleteAlt(struct Node *temp) {
        // Code here
        for (Node* head = temp; head && head->next; head = head->next) head->next = head->next->next;
    }
};
