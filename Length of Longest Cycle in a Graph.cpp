class Solution:
    def longestCycle(self, V, edges):
        adjList = {u: v for u, v in edges}
        vis = [False]*V
        visTime = [0]*V
        startId = [-1]*V
        
        maxCycle, timer = -1, 0
        for i in range(V):
            if vis[i]:
                continue
            
            node, start = i, i
            while node in adjList and vis[node] == False:
                vis[node] = True
                visTime[node] = timer
                startId[node] = start
                node = adjList[node]
                
                if node is not None and startId[node] == start:
                    cycleLen = timer-visTime[node]+1
                    maxCycle = max(maxCycle, cycleLen)
                    break
                timer += 1
        return maxCycle
