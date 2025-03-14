class Solution {
  public:
    int fun(int i, int sum, vector<int> &coins, vector<vector<int>> &dp){
        if(sum==0)
            return 1;
        if(i<0)
            return 0;
        if(dp[i][sum]!=-1)
            return dp[i][sum];
        
        int t = 0;
        int nt = fun(i-1, sum, coins, dp);
        
        if(sum>=coins[i])    
            t = fun(i, sum-coins[i], coins, dp);
        
        return dp[i][sum] = t + nt;    
    }
  
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        
        return fun(n-1, sum, coins, dp);
        
    }
};

