class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int i = 0, j = 0;
        while (i >= 0 && i < n && j >= 0 && j < m) {
            int num = mat[i][j];
            int l = (j > 0) ? mat[i][j - 1] : INT_MIN;
            int r = (j + 1 < m) ? mat[i][j + 1] : INT_MIN;
            int u = (i > 0) ? mat[i - 1][j] : INT_MIN;
            int d = (i + 1 < n) ? mat[i + 1][j] : INT_MIN;

            if (l > num) j--;
            else if (r > num) j++;
            else if (u > num) i--;
            else if (d > num) i++;
            else return {i, j};
        }
        return {-1, -1};
    }
};

