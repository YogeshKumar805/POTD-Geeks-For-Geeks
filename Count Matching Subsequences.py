class Solution:
    def countWays(self, s, t):
        n, m = len(s), len(t)
        MOD = 10**9+7
        
        dp = [[0]*(m+1) for _ in range(n+1)]
        for i in range(n+1):
            dp[i][0] = 1
            
        for i in range(n+1):
            for j in range(1, min(i, m)+1):
                not_take = dp[i-1][j]
                take = 0
                if s[i-1] == t[j-1]:
                    take = dp[i-1][j-1]
                dp[i][j] = (take+not_take)%MOD
        return dp[n][m]

