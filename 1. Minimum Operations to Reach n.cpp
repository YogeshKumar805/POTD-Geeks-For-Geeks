class Solution {
public:
    int minOperation(int n) {
        vector<int> dp(n + 1); dp[0]=0;

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + 1;
            if (i % 2 == 0)
                dp[i] = min(dp[i], dp[i / 2] + 1);
        }

        return dp[n];
    }
};
