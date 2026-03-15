class Solution:
    def verticalOrder(self, root):
        if not root:
            return []
        
        hd_map = defaultdict(list)
        queue = deque([(root, 0)])
        min_hd = max_hd = 0
        
        while queue:
            node, hd = queue.popleft()
            hd_map[hd].append(node.data)
            min_hd = min(min_hd, hd)
            max_hd = max(max_hd, hd)
            
            if node.left:
                queue.append((node.left, hd - 1))
            if node.right:
                queue.append((node.right, hd + 1))
        
        return [hd_map[hd] for hd in range(min_hd, max_hd + 1)]
