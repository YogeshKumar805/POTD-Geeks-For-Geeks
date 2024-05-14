
from typing import List

class Solution:
    #dijkstra algorithm
    def MinimumEffort(self, rows : int, columns : int, heights : List[List[int]]) -> int:
        import heapq
        hth=len(heights)
        wth=len(heights[0])
        dp=[[float('inf') for _ in range(wth)] for _ in range(hth)]
        dp[0][0]=0
        q=[(0,0,0,)]
        while q:
            mx,x,y=heapq.heappop(q)
            for dx,dy in [(-1,0,),(1,0,),(0,-1,),(0,1,)]:
                nx,ny=x+dx,y+dy
                if not(0<=nx<wth and 0<=ny<hth):
                    continue
                mn=min(dp[ny][nx],max(mx,abs(heights[y][x]-heights[ny][nx])))
                if mn<dp[ny][nx]:
                    dp[ny][nx]=mn
                    heapq.heappush(q,((mn,nx,ny,)))
        return dp[-1][-1]
