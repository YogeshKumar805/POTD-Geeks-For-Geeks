class Solution:
    def removekeys(self, root, l, r):
        if not root:
            return None
        if root.data < l:
            return self.removekeys(root.right, l, r)
        if root.data > r:
            return self.removekeys(root.left, l, r)
        root.left = self.removekeys(root.left, l, r)
        root.right = self.removekeys(root.right, l, r)
        return root
