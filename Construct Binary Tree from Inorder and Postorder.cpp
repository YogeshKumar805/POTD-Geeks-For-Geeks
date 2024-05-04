class Solution {
public:
    // Recursive function to construct a binary tree from inorder and postorder traversals
    Node* buildTree(int in[], int post[], int n) {
        // Base case: If no nodes, return nullptr
        if (n == 0) {
            return nullptr;
        }

        // Find the root node index in inorder traversal
        int rootIndex = 0;
        while (rootIndex < n && in[rootIndex] != post[n - 1]) {
            rootIndex++;
        }

        // Create the root node with the value from postorder traversal
        Node* root = new Node(post[n - 1]);

        // Recursively build left subtree using elements before root in inorder traversal
        Node* leftSubtree = buildTree(in, post, rootIndex);

        // Recursively build right subtree using elements after root in inorder traversal
        Node* rightSubtree = buildTree(in + rootIndex + 1, post + rootIndex, n - rootIndex - 1);

        // Connect left and right subtrees to the root node
        root->left = leftSubtree;
        root->right = rightSubtree;

        return root;
    }
};
