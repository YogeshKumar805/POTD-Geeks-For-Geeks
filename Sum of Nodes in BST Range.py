class Solution:
    def nodeSum(self, root, l, r):
        if not root:
            return 0
        stack = [root]
        total = 0
        while stack:
            node = stack.pop()
            if node:
                if l <= node.data <= r:
                    total += node.data
                if node.left:
                    stack.append(node.left)
                if node.right:
                    stack.append(node.right)
        return total
