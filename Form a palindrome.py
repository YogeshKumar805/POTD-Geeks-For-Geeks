class Solution:
 def countMin(self, Str):
        s1 = Str
        n = len(s1)
        s2 = s1[::-1]
        dp = [[0 for i in range(n+1)] for j in range(n+1)]

        for i in range(n-1,-1,-1):
            for j in range(n-1,-1,-1):
                if s1[i] == s2[j]:
                    dp[i][j] = 1 + dp[i+1][j+1]
                else:
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1])
        return n - dp[0][0]
