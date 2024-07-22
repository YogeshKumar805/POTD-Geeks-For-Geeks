class TreeNode:
    def __init__(self, data=0, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

class Solution:
    def is_bst(self, node, min_val, max_val):
        if node is None:
            return True
        if not (min_val < node.data < max_val):
            return False
        return self.is_bst(node.left, min_val, node.data) and self.is_bst(node.right, node.data, max_val)

    def get_tree_size(self, node):
        if node is None:
            return 0
        return 1 + self.get_tree_size(node.left) + self.get_tree_size(node.right)

    def get_bst_size(self, node):
        if node is None:
            return 0
        if self.is_bst(node, float('-inf'), float('inf')):
            return self.get_tree_size(node)
        return max(self.get_bst_size(node.left), self.get_bst_size(node.right))

    def largestBst(self, root):
        return self.get_bst_size(root)
