class Solution:
    def maximumProfit(self, prices) -> int:
        n = len(prices)
        if n == 0:  # Edge case: no prices available
            return 0

        # dp[ind][flag]: Maximum profit at index `ind` with `flag` 
        # flag = 0 means we can buy, flag = 1 means we can sell
        dp = [[0] * 2 for _ in range(n + 1)]

        # Fill the DP table in reverse order (bottom-up)
        for ind in range(n - 1, -1, -1):
            for flag in range(2):
                if flag == 0:  # We can buy
                    dp[ind][flag] = max(-prices[ind] + dp[ind + 1][1], dp[ind + 1][0])
                else:  # We can sell
                    dp[ind][flag] = max(prices[ind] + dp[ind + 1][0], dp[ind + 1][1])

        # The result is the maximum profit starting from index 0 with the option to buy
        return dp[0][0]
