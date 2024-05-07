

/*   
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
vector<int> reverseLevelOrder(Node *root)
{
    vector<int> res;
    
    queue<Node *> q;
    q.push(root);
    
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        
        res.emplace_back(node->data);
        
        if (node->right)
            q.push(node->right);
        
        if (node->left)
            q.push(node->left);
    }
    
    reverse(res.begin(), res.end());
    return res;
}
