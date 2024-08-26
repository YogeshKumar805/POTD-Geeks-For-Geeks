class Solution {
  public:
    int wildCard(string pattern, string str) {
        int n = pattern.size(), m = str.size(); int dp[n+2][m+2];
        memset(dp, 0, sizeof(dp)); dp[n][m] = 1;
        for ( int i = n; i>=0; i-- ){
            for ( int j = m; j>=0; j-- ){
                if ( pattern[i] == str[j] || pattern[i] == '?' ) {
                    dp[i][j] |= dp[i+1][j+1];
                }
                if ( pattern[i] == '*' ){
                    dp[i][j] |= dp[i+1][j+1];
                    dp[i][j] |= dp[i][j+1];
                    dp[i][j] |= dp[i+1][j];
                } 
            }
        } return dp[0][0];
    }
};
