#define MOD 1000000007
class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        // code here
        Node * temp1 = first;
        Node * temp2 = second;
        
        long long product = 0;
        long long num1 = 0, num2 = 0;
        
        while (temp1 != nullptr) {
            num1 = (num1 * 10 + temp1->data) % MOD;
            temp1 = temp1->next;
        }
        
        while (temp2 != nullptr) {
            num2 = (num2 * 10 + temp2->data) % MOD;
            temp2 = temp2->next;
        }
        
        product = (num1 * num2) % MOD;
        
        return product;
    }
};
