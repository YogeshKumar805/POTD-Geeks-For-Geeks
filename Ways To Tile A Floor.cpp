class Solution {
  public:
    int numberOfWays(int n) {
        // code here
        int dp[101];        //dp[i] denotes no. of tiles arrangement for 2 x i floor
        
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i=2; i<=100; i++) {    //dp[i-1] -> Last tile placed vertically
            dp[i] = dp[i-1]+dp[i-2];    //dp[i-2] -> Last tiles placed horizontally
        }
        
        return dp[n];
    }
};
