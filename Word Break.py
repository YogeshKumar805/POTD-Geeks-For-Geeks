class Solution:
    def wordBreak(self, s, dictionary):
        # code here
        st = set(dictionary)
        l, n = len(max(dictionary, key=len)), len(s)

        dp = [False]*(n+1)
        dp[0] = True
        
        for j in range(n):
            for i in range(j, max(-1, j-l), -1):
                dp[j+1] = dp[j+1] or dp[i] and (s[i:j+1] in st)

        return dp[-1]

