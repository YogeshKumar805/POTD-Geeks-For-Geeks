class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
         Node* tmp = head;
        while(tmp!=NULL){
            Node* newNode = new Node(tmp->data);
            newNode->next = tmp->next;
            tmp->next = newNode;
            tmp = tmp->next->next;
        }
        tmp = head;
        while(tmp){
            if(tmp->random)tmp->next->random = tmp->random->next;
            else tmp->next->random = tmp->random;
            tmp = tmp->next->next;
        }
        tmp = head;
        Node* dNode = new Node(-1);
        Node* res = dNode;
        while(tmp){
        
        res->next = tmp->next;
        tmp->next = tmp->next->next;
        res = res->next;
        tmp = tmp->next;
        }
        return dNode->next;
    }
};
