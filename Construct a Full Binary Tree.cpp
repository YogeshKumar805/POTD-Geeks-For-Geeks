/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
    unordered_map<int, int> prePos, mirrorPos;

    Node* build(vector<int>& pre, vector<int>& mirror,
                int ps, int pe, int ms, int me) {

        if (ps > pe) return nullptr;

        Node* root = new Node(pre[ps]);

        if (ps == pe) return root;

        int leftRoot = pre[ps + 1];

        int rightRoot = mirror[ms + 1];

        int rightPos = prePos[rightRoot];

        int leftSize = rightPos - (ps + 1);

        root->left = build(pre, mirror,
                           ps + 1, ps + leftSize,
                           mirrorPos[leftRoot], me);

        root->right = build(pre, mirror,
                            ps + leftSize + 1, pe,
                            ms + 1, mirrorPos[rightRoot]);

        return root;
    }

public:
    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {

        int n = pre.size();

        for (int i = 0; i < n; i++)
            prePos[pre[i]] = i;

        for (int i = 0; i < n; i++)
            mirrorPos[preMirror[i]] = i;

        return build(pre, preMirror, 0, n - 1, 0, n - 1);
    }
};
