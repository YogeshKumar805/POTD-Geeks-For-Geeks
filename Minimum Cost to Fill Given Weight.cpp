class Solution {
  public:
    int minimumCost(vector<int>& cost, int w) {
        vector<int> dp(w + 1, 1e9);
        dp[0] = 0;

        int n = cost.size();

        for(int i = 0; i < n; i++) {
            if(cost[i] == -1) continue;
            int wt = i + 1;
            for(int j = wt; j <= w; j++) {
                dp[j] = min(dp[j] , dp[j - wt] + cost[i]);
            }
        }

        return dp[w] == 1e9 ? -1 : dp[w];
    }
};

