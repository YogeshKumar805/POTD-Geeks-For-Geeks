from collections import deque
class Solution:
    def bottomView(self, root):
        if not root:
            return []
        queue = deque([(root, 0)])
        bottom_view = {}
        while queue:
            node, dist = queue.popleft()
            bottom_view[dist] = node.data
            if node.left:
                queue.append((node.left, dist - 1))
            if node.right:
                queue.append((node.right, dist + 1))
        result = []
        for dist in sorted(bottom_view.keys()):
            result.append(bottom_view[dist])
        return result

