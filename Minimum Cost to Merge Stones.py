class Solution:
    def mergeStones(self, stones, k):
        n = len(stones)

        # Check if final merge to 1 pile is possible
        if (n - 1) % (k - 1) != 0:
            return -1

        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i+1] = prefix[i] + stones[i]

        INF = 10**15
        # dp[i][j][m] = min cost to merge stones[i..j] into m piles
        dp = [[[INF] * (k + 1) for _ in range(n)] for _ in range(n)]

        # Base case: one pile (cost 0)
        for i in range(n):
            dp[i][i][1] = 0

        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                
                # Try forming m piles
                for m in range(2, k + 1):
                    for mid in range(i, j):
                        # Only valid splits that reduce piles correctly
                        if (mid - i + 1 - 1) % (k - 1) == 0:
                            dp[i][j][m] = min(dp[i][j][m],
                                              dp[i][mid][1] + dp[mid+1][j][m-1])
                
                # If we can merge m=k piles into 1 pile
                if (length - 1) % (k - 1) == 0:
                    dp[i][j][1] = dp[i][j][k] + (prefix[j+1] - prefix[i])

        return dp[0][n-1][1]
