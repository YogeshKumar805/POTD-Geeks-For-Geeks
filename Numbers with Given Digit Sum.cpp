class Solution {
  public:
    int countWays(int n, int sum) {
        if (sum > 9 * n) return -1;

        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        dp[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int s = 0; s <= sum; s++) {
                if (dp[i][s] == 0) continue;

                for (int d = 0; d <= 9; d++) {
                    if (s + d <= sum) {
                        dp[i + 1][s + d] += dp[i][s];
                    }
                }
            }
        }

        int total = dp[n][sum];

        if (n == 1) return total == 0 ? -1 : total;

        vector<vector<int>> dpZero(n, vector<int>(sum + 1, 0));
        dpZero[0][0] = 1;

        for (int i = 0; i < n - 1; i++) {
            for (int s = 0; s <= sum; s++) {
                if (dpZero[i][s] == 0) continue;

                for (int d = 0; d <= 9; d++) {
                    if (s + d <= sum) {
                        dpZero[i + 1][s + d] += dpZero[i][s];
                    }
                }
            }
        }

        int ans = total - dpZero[n - 1][sum];

        return ans == 0 ? -1 : ans;
    }
};
