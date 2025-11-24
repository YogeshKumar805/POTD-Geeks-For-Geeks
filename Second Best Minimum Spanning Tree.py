class Solution:
    def secondMST(self, V, edges):
        # Sort edges by weight
        edges.sort(key=lambda x: x[2])
        
        # DSU class for union-find operations
        class DSU:
            def __init__(self, n):
                self.parent = list(range(n))
                self.rank = [0] * n
            
            def find(self, x):
                if self.parent[x] != x:
                    self.parent[x] = self.find(self.parent[x])
                return self.parent[x]
            
            def union(self, x, y):
                px, py = self.find(x), self.find(y)
                if px == py:
                    return False
                if self.rank[px] < self.rank[py]:
                    px, py = py, px
                self.parent[py] = px
                if self.rank[px] == self.rank[py]:
                    self.rank[px] += 1
                return True
        
        # Function to compute MST weight, optionally skipping an edge
        def kruskal(skip_edge=None):
            dsu = DSU(V)
            total_weight = 0
            used_edges = 0
            for u, v, w in edges:
                if skip_edge and ((u == skip_edge[0] and v == skip_edge[1]) or (u == skip_edge[1] and v == skip_edge[0])):
                    continue
                if dsu.union(u, v):
                    total_weight += w
                    used_edges += 1
            return total_weight if used_edges == V - 1 else float('inf')
        
        # Step 1: Find MST weight
        mst_weight = kruskal()
        if mst_weight == float('inf'):
            return -1  # Graph is not connected
        
        # Step 2: Try removing each MST edge and compute new MST
        second_best = float('inf')
        mst_edges = []
        dsu = DSU(V)
        for u, v, w in edges:
            if dsu.union(u, v):
                mst_edges.append((u, v))
        
        for skip_edge in mst_edges:
            new_weight = kruskal(skip_edge)
            if new_weight > mst_weight and new_weight < second_best:
                second_best = new_weight
        
        return -1 if second_best == float('inf') else second_best
