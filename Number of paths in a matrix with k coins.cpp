class Solution {
public:

    int traverse(int i, int j, vector<vector<int>>& mat, int k, int cnt, vector<vector<unordered_map<int, int>>>& dp)
    {
        int n = mat.size();
        int m = mat[0].size();
        
        if (i >= n || j >= m)
            return 0;
            
        if (dp[i][j].find(cnt) != dp[i][j].end()) return dp[i][j][cnt];    
        

        if (i == n - 1 && j == m - 1) {
            if (mat[i][j] == k-cnt) {
                return 1;
            }
            return 0;
        }
        
        int newCnt = cnt + mat[i][j];

        int res = traverse(i + 1, j, mat, k, newCnt, dp) + traverse(i, j + 1, mat, k, newCnt, dp);
        
        return dp[i][j][cnt] = res;
    }

    int numberOfPath(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<unordered_map<int, int>>> dp(n, vector<unordered_map<int, int>>(m));
        
        int ans = traverse(0, 0, mat, k, 0, dp);
        
        // for (int i=0; i<n; i++) for (int j=0; j<m; j++) for (auto x:dp[i][j]) {
        //     cout << "i " << i << " j " << j << " map ";
        //     cout << x.first << ' ' << x.second << '\n';
        // }
        
        return ans;
    }
};
