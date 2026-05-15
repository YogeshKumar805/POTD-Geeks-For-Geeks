class Solution:

    def optimalKeys(self, n: int) -> int:
        
        # For small values, pressing 'A' is optimal
        if n <= 6:
            return n

        dp = [0] * (n + 1)

        # Base cases
        for i in range(1, 7):
            dp[i] = i

        # Fill DP table
        for i in range(7, n + 1):

            # Try every possible breakpoint
            for j in range(i - 3, 0, -1):

                # After j operations:
                # Ctrl+A, Ctrl+C, then paste multiple times
                curr = dp[j] * (i - j - 1)

                dp[i] = max(dp[i], curr)

        return dp[n]

