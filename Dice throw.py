class Solution:
    def noOfWays(self, m, n, x):
        dp = [[0] * (x + 1) for _ in range(n + 1)]
        dp[0][0] = 1

        for i in range(1, n + 1):
            for j in range(i, x + 1):
                for face in range(1, m + 1):
                    if j - face >= 0:
                        dp[i][j] += dp[i - 1][j - face]

        return dp[n][x]

