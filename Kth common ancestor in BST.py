class Solution:
    def dfs(self, root, k, x, y, ancestors):
        if root == None: return False
        left = self.dfs(root.left, k, x, y, ancestors)
        right = self.dfs(root.right, k, x, y, ancestors)
        if left and right or ((left or right) and (root.data == x or root.data == y)):
           ancestors.append(root.data)
           return True
        elif left or right:
            if len(ancestors) > 0 and len(ancestors) < k: ancestors.append(root.data)
            return True
        
        return root.data == x or root.data == y
        
    def kthCommonAncestor(self, root, k, x, y):
        ancestors = []
        self.dfs(root, k, x, y, ancestors)
        return -1 if k > len(ancestors) else ancestors[-1]
