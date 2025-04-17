class Solution:
    def findMinCycle(self, V, edges):
        from collections import defaultdict
        import heapq

        # Create adjacency list
        graph = defaultdict(list)
        for u, v, w in edges:
            graph[u].append((v, w))

        INF = float('inf')
        min_cycle = INF

        # For each edge, remove it and run Dijkstra
        for u, v, w in edges:
            # Temporarily remove the edge u-v
            graph[u].remove((v, w))
            graph[v].remove((u, w))

            # Run Dijkstra from u to v
            dist = [INF] * V
            dist[u] = 0
            heap = [(0, u)]

            while heap:
                d, node = heapq.heappop(heap)

                if d > dist[node]:
                    continue

                for nei, wt in graph[node]:
                    if dist[nei] > dist[node] + wt:
                        dist[nei] = dist[node] + wt
                        heapq.heappush(heap, (dist[nei], nei))

            if dist[v] != INF:
                min_cycle = min(min_cycle, dist[v] + w)

            # Add the edge back
            graph[u].append((v, w))
            graph[v].append((u, w))

        return min_cycle if min_cycle != INF else -1
