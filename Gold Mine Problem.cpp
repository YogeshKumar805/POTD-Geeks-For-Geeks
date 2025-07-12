class Solution {
public:
    int maxGold(vector<vector<int>>& mat) {
        int m = mat.size();    // number of rows
        int n = mat[0].size(); // number of columns
        
        // Create DP table where dp[i][j] represents max gold 
        // we can collect reaching cell (i,j)
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        // Initialize first column - these are our starting points
        // We can start from any cell in the first column
        for (int i = 0; i < m; i++) {
            dp[i][0] = mat[i][0];
        }
        
        // Fill the DP table column by column from left to right
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < m; i++) {
                // Current cell's gold + maximum from previous column
                int currentGold = mat[i][j];
                int maxFromPrev = 0;
                
                // Check all three possible previous positions:
                
                // 1. From diagonally up-left (i-1, j-1)
                if (i - 1 >= 0) {
                    maxFromPrev = max(maxFromPrev, dp[i-1][j-1]);
                }
                
                // 2. From directly left (i, j-1)
                maxFromPrev = max(maxFromPrev, dp[i][j-1]);
                
                // 3. From diagonally down-left (i+1, j-1)
                if (i + 1 < m) {
                    maxFromPrev = max(maxFromPrev, dp[i+1][j-1]);
                }
                
                // Store the maximum gold we can collect reaching this cell
                dp[i][j] = currentGold + maxFromPrev;
            }
        }
        
        // Find the maximum gold from the last column
        // The miner can exit from any cell in the last column
        int result = 0;
        for (int i = 0; i < m; i++) {
            result = max(result, dp[i][n-1]);
        }
        
        return result;
    }
};
