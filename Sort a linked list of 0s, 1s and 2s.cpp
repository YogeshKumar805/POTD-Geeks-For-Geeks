class Solution {
  public:
    Node* segregate(Node* head) {
        Node* curr = head;
        int z = 0, o = 0, t = 0;
        while (curr != nullptr){
            if (curr -> data == 1) o += 1;
            else if (curr -> data == 2) t += 1;
            else z += 1;
            curr = curr -> next;
        }
        while (z--) cout << 0 << " ";
        while (o--) cout << 1 << " ";
        while (t--) cout << 2 << " ";
        return nullptr;
    }
};
