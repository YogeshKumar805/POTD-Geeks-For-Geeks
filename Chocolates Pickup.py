class Solution:
    def maxChocolate(self, grid):
        # code here
        m, n = len(grid), len(grid[0])
        # dp[i][j][k] means at row i, position j and k
        # dp[0][0][n-1] = grid[0][0] + grid[0][n-1]
        dp = [[[-1]*n for _ in range(n)] for _ in range(m)]
        
        dp[0][0][-1] = grid[0][0] + grid[0][-1]
        for k in range(1, m):
            for i in range(n):
                for j in range(n):
                    v = -1
                    for c1 in (i-1, i, i+1):
                        for c2 in (j-1, j, j+1):
                            if c1 < 0 or c1 >= n or c2 < 0 or c2 >= n:
                                continue
                            v = max(v, dp[k-1][c1][c2])
                    if v == -1:
                        continue

                    if i == j:
                        dp[k][i][j] = v + grid[k][j]
                    else:
                        dp[k][i][j] = v + grid[k][i] + grid[k][j]
        
        ans = 0
        for r in dp[-1]:
            for c in r:
                ans = max(ans, c)
        return ans
