class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {

        // Code here
        if(!head){
            return 0;
        }
        int count = 0;
        Node* temp = head;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }
};
