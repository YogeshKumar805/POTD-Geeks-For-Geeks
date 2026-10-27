class Solution {
  public:
    
    int solve(int i, string& s, vector<int>& dp) {
        
        if (i == s.length()) {
            return 0;
        }
        
        if (dp[i] != -1) {
            return dp[i];
        }
        
        int ans = 1 + solve(i+1, s, dp);
        
        if (i+1 < s.length()) {
            
            int w = (s[i] != s[i+1]) ? 4 : 3;
            
            ans = max(ans, w + solve(i+2, s, dp));
        }
        
        return dp[i] = ans;
    }
    int getMaxWeight(string &s) {
        // code here
        int n = s.length();
        // vector<int> dp(n, -1);
        // return solve(0, s, dp);
        
        vector<int> dp(n+1, 0);
        
        for (int i = n-1; i >= 0; i--) {
            
            int ans = 1 + dp[i+1];
            
            if (i+1 < n) {
                int w = (s[i] != s[i+1]) ? 4 : 3;
                
                ans = max(ans, w + dp[i+2]);
            }
            
            dp[i] = ans;
        }
        
        return dp[0];
    }
};
