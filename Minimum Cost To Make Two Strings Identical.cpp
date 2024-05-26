class Solution {
public:
    int findMinCost(string x, string y, int costX, int costY) {
        int n = x.size();
        int m = y.size();
        
        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);
        for (int idx2 = 0; idx2 <= m; idx2++) {
            prev[idx2] = (m - idx2) * costY;
        }
        for (int idx1 = n - 1; idx1 >= 0; idx1--) {
            curr[m] = (n - idx1) * costX;
            for (int idx2 = m - 1; idx2 >= 0; idx2--) {
                if (x[idx1] == y[idx2]) {
                    curr[idx2] = prev[idx2 + 1];
                } else {
                    int deleteX = costX + prev[idx2];
                    int deleteY = costY + curr[idx2 + 1];
                    curr[idx2] = min(deleteX, deleteY);
                }
            }
            prev = curr;
        }

        return prev[0];
    }
};
