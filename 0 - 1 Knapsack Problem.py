class Solution:
    def helper(self, W, wt, val, dp, idx):
        if idx == len(wt): return 0
        if wt[idx] > W: return self.helper(W, wt, val, dp, idx + 1)
        if dp[idx][W] != -1: return dp[idx][W]
        
        dp[idx][W] = max(
            val[idx] + self.helper(W - wt[idx], wt, val, dp, idx + 1),
            self.helper(W, wt, val, dp, idx + 1)
        )
        
        return dp[idx][W]
        
    def knapSack(self,W, wt, val):
        return self.helper(W, wt, val, [[-1 for _ in range(W + 1)] for _ in range(len(wt))], 0)
