class Solution {
	public:
	int minDiff(Node *root, int k) {
		// code here
		int result = INT_MAX;
		Node *node = root;
		while (node != nullptr) {
			result = min(result, abs(node->data - k));
			if (node->data<k)node = node->right;
			else
				node = node->left;
		}
		return result;
	}
};
