class Solution:
    def tsp(self, cost):
        n = len(cost)
        N = 1 << n
        INF = 10**9
        
        dp = [[INF] * n for _ in range(N)]
        dp[1][0] = 0
        
        for mask in range(N):
            for u in range(n):
                if not (mask & (1 << u)):
                    continue
                for v in range(n):
                    if mask & (1 << v):
                        continue
                    nxt = mask | (1 << v)
                    dp[nxt][v] = min(dp[nxt][v], dp[mask][u] + cost[u][v])
        
        ans = INF
        full = N - 1
        for u in range(n):
            ans = min(ans, dp[full][u] + cost[u][0])
        
        return ans
