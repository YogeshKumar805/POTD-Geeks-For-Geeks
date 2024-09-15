class Solution {
  public:
    Node* bToDLL(Node* root) {
        vector<Node*> p;
        dfs1(root, p);
        if (p.empty()) return nullptr;
        Node* head = p[0];
        Node* prev = head;
        for (int i = 1; i < p.size(); i++) {
            p[i]->left = prev;
            prev->right = p[i];
            prev = p[i];
        }
        prev->right = nullptr;
        return head;
    }
    void dfs1(Node* root, vector<Node*>& p) {
        if (root == nullptr) {
            return;
        }
        dfs1(root->left, p);
        p.push_back(root);
        dfs1(root->right, p);
    }
};
