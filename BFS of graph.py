class Solution:
    from collections import deque
    def bfs(self, adj):
        visited=set([0])
        result=[]
        queue=self.deque([0])
        while queue:
            node=queue.popleft()
            result.append(node)
            for neighbor in adj[node]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)
        return result
