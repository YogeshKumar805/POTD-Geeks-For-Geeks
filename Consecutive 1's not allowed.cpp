class Solution {
  public:
   
    int countStrings(int n) {
        // code here
        vector<int> dp(n+1,-1);
        return countStr(n,dp);
        
    }
    int  countStr(int n, vector<int> &dp)
    {
        if(n==1) return 2;
        if(n==2) return 3;
        if(dp[n]!=-1)
            return dp[n];
        dp[n]= countStr(n-1,dp)+countStr(n-2,dp);
        
        return dp[n];
    }
};
