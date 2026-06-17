class Solution:
    def maxProduct(self, n):
        # Simple tabulation approch
        
        dp = [[0] * (n+1) for _ in range(n+1)]
        
        for j in range(1, n+1):
            dp[n][j] = (n-j)
            
        for i in range(n-1, -1, -1):
            for j in range(0, i+1):
                dp[i][j] = max(
                        dp[i+1][j],
                        (i-j+1) * dp[i+1][i+1]
                    )
                    
        
        return dp[0][0]
