class Solution {
    int mod = 1e9 + 7;
  public:
    int padovanSequence(int n) {
        vector<int> dp(n+1);
        dp[0] = dp[1] = dp[2] = 1;
        for(int i=3; i<=n;i++) {
            dp[i] = (dp[i-2] + dp[i-3]) % mod;
        }
        return dp[n];
    }
};

