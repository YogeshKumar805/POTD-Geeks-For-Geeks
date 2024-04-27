
/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution {
  public:
    struct Node *sortDoubly(struct Node *head) {
        if(head == NULL)
           return head;
        Node *temp = head;
        vector<int> arr;
        while(temp != nullptr){
            arr.push_back(temp->data);
            temp = temp->next;        
        }
        sort(arr.begin(), arr.end());
        struct Node *newNode = new Node(arr[0]);
        struct Node *dummyHead = newNode;
        for(int i = 1; i < arr.size(); i++){
            Node *temp_node = new Node(arr[i]);
            dummyHead->next = temp_node;
            temp_node->prev = dummyHead;
            dummyHead = temp_node;
        }
        return newNode;
    }
};
