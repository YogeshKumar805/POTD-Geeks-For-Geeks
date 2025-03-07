class Solution:

    def longestPalinSubseq(self, s):
        # code here
        n=len(s)
        dp=[[0]*n for _ in range(n)]
        for i in range(n):
            dp[i][i]=1
        for j in range(2,n+1):
            for i in range(n-j+1):
                l=i+j-1
                if s[i]==s[l]:
                    dp[i][l]=dp[i+1][l-1]+2
                else:
                    dp[i][l]=max(dp[i+1][l],dp[i][l-1])
        return dp[0][n-1]
