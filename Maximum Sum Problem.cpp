class Solution {
  public:
    vector<int> dp;
    
    int f(int n){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=max(n,f(n/2)+f(n/3)+f(n/4));
    }
    
    int maxSum(int n) {
        dp=vector<int>(n+1,-1);
        return f(n);
    }
};
