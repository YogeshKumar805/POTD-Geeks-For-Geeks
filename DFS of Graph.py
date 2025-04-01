class Solution:
    def dfs(self, adj):
        V = len(adj)
        visited = [False] * V
        result = []
        stack = [0]  # Start DFS from node 0

        while stack:
            node = stack.pop()
            if not visited[node]:
                visited[node] = True
                result.append(node)
                stack.extend(reversed(adj[node]))  # Add neighbors in reverse order for correct order
                
        return result
