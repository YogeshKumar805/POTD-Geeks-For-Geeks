class Solution {
  public:
    int countStrings(int n, int k) {
        const int MOD = 1e9 + 7;
        
        // Max possible adjacent pairs is n-1, if k >= n, answer is 0
        if (k > n - 1) return 0;
        
        // dp[j][0] = ways ending in 0 with j pairs so far
        // dp[j][1] = ways ending in 1 with j pairs so far
        vector<vector<long long>> dp(k + 1, vector<long long>(2, 0));
        
        dp[0][0] = 1; // string "0"
        dp[0][1] = 1; // string "1"
        
        for (int i = 2; i <= n; i++) {
            vector<vector<long long>> ndp(k + 1, vector<long long>(2, 0));
            for (int j = 0; j <= k; j++) {
                // append 0 to a string ending in 0 -> ends in 0, no new pair
                ndp[j][0] = (ndp[j][0] + dp[j][0]) % MOD;
                // append 0 to a string ending in 1 -> ends in 0, no new pair
                ndp[j][0] = (ndp[j][0] + dp[j][1]) % MOD;
                // append 1 to a string ending in 0 -> ends in 1, no new pair
                ndp[j][1] = (ndp[j][1] + dp[j][0]) % MOD;
                // append 1 to a string ending in 1 -> ends in 1, new pair (j+1)
                if (j + 1 <= k) {
                    ndp[j + 1][1] = (ndp[j + 1][1] + dp[j][1]) % MOD;
                }
            }
            dp = ndp;
        }
        
        long long ans = (dp[k][0] + dp[k][1]) % MOD;
        return (int) ans;
    }
};
