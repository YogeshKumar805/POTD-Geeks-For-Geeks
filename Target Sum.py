class Solution:
    def totalWays(self, arr, target):
        total = sum(arr)
        
        # Edge cases
        if (target + total) % 2 != 0 or abs(target) > total:
            return 0
        
        subset_sum = (target + total) // 2
        
        # DP array
        dp = [0] * (subset_sum + 1)
        dp[0] = 1
        
        for num in arr:
            for j in range(subset_sum, num - 1, -1):
                dp[j] += dp[j - num]
        
        return dp[subset_sum]
