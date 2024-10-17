class Solution {
  public:
    vector<Node*> alternatingSplitList(struct Node* head) {
        Node *h1 = new Node(-1), *h2 = new Node(-1);
        Node *t1 = h1, *t2 = h2; int i = 0;
        while ( head ){
            if ( i%2 == 0 ) {
                t1->next = new Node(head->data);
                t1 = t1->next;
            } else {
                t2->next = new Node(head->data);
                t2 = t2->next;
            } head = head->next; 
            i++;
        } return {h1->next, h2->next};
    }
};
