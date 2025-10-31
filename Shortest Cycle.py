class Solution:
    def shortCycle(self, V, edges):
        from collections import deque, defaultdict
        g = defaultdict(list)
        for u, v in edges:
            g[u].append(v)
            g[v].append(u)
        ans = float('inf')
        
        for start in range(V):
            dist = [-1] * V
            parent = [-1] * V
            queue = deque([start])
            dist[start] = 0
            
            while queue:
                node = queue.popleft()
                
                for nbr in g[node]:
                    if dist[nbr] == -1:  # Not visited
                        dist[nbr] = dist[node] + 1
                        parent[nbr] = node
                        queue.append(nbr)
                    elif parent[node] != nbr:  # Found a cycle (not going back to parent)
                        # Cycle length = dist[node] + dist[nbr] + 1
                        ans = min(ans, dist[node] + dist[nbr] + 1)
        
        return ans if ans != float('inf') else -1
        
