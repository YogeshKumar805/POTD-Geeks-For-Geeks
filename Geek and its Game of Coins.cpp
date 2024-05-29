class Solution {
  public:
    int solve(int n, int x, int y, vector<int> &dp)
    {
        if(n <= 1)
            return n;
        if(dp[n] != -1)
            return dp[n];
        int ans = 1;
        if(n >= x)
            ans &= solve(n - x, x, y, dp);
        if(n >= y)
            ans &= solve(n - y, x, y, dp);
        ans &= solve(n - 1, x, y, dp);
        return dp[n] = ans ^ 1;
    }
    int findWinner(int n, int x, int y) {
        vector<int> dp(n + 1, -1);
        return solve(n, x, y, dp);
    }
};
