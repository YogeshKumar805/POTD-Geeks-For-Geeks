//User function Template for C++

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    pair<int, int> func(Node* root){
        if(root == nullptr) return {0, 1};
        pair<int, int> l = func(root->left), r = func(root->right);
        if(l.second > r.second) return {l.first + root->data, l.second + 1};
        else if(l.second < r.second) return {r.first + root->data, r.second + 1};
        return {max(l.first, r.first) + root->data, l.second + 1};
    }
    int sumOfLongRootToLeafPath(Node *root){
        return func(root).first;
    }
};
